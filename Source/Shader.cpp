//
// Created by MisThe on 2023/6/5.
//

#include "../Include/Core/Invoker/Graphic/Elements/Detail/Shader.h"
#include "../Include/General/Tool/IO.h"
#include "../Include/General/Tool/String.h"
#include "../Include/Core/Asset/CustomJson.h"
#include "../Include/General/Container/ContainSerialize/QueueSerialize.h"

void Shader::Read(cereal::BinaryInputArchive &archive) {
    auto result = String::Read(archive, 2);
    this->vertexShaderCode = result->Pop();
    this->fragmentShaderCode = result->Pop();
    QueueSerialize::Read<ShaderInfo>(archive, this->shaderInfo, [&archive]() -> ShaderInfo {
        std::string_view n;
        ShaderInfoType type;
        n = String::Read(archive, 1)->Pop();
        archive(type);
        return {n, type};
    });
    archive(this->floatSize, this->textureSize);
}

void Shader::Write(cereal::BinaryOutputArchive &archive) {
    String::Write(archive, {vertexShaderCode, fragmentShaderCode});
    QueueSerialize::Write<ShaderInfo>(archive, this->shaderInfo, [&archive](ShaderInfo info) {
        String::Write(archive, {info.name});
        archive(info.type);
    });
    archive(this->floatSize, this->textureSize);
}

void Shader::CustomMark() {
    CustomPtr::S_Mark(this->shaderInfo);
}

void Shader::Cache(std::string_view file) {
    //收集所有相关shader
    std::string_view extension = IO::PathToExtension(file);
    std::string_view propShaderPath = file;
    std::string_view vertShaderPath = file;
    std::string_view fragShaderPath = file;
    String::ReplaceLast(propShaderPath, extension, "sprop");
    String::ReplaceLast(vertShaderPath, extension, "vert");
    String::ReplaceLast(fragShaderPath, extension, "frag");
    //收集shader info
    IO::ReadInfo(vertShaderPath, this->vertexShaderCode);
    IO::ReadInfo(fragShaderPath, this->fragmentShaderCode);
    //读取Property数据并进行填充
    this->CompressShaderProperty(propShaderPath);
}

void Shader::CompressShaderProperty(std::string_view &propertyPath) {
    //将SHADER_MATERIAL_PROPERTY 替换为 propertyPath
    std::string infoBegin = "struct Material {\n";
    std::string infoEnd = "}; uniform Material material";
    std::string info;
    //解析property
    auto *cj = new CustomJson(propertyPath);
    int tempFloatSize = 0, tempTextureSize =0;
    cj->Iterator([&info, this, &tempFloatSize, &tempTextureSize](std::string_view &key, Json::Value &value) {
        if (!value.isString())
            return;
        std::string strType = value.asString();
        ShaderInfoType type;
        if (strType == "float") {
            type = ShaderInfoType::Float;
            tempFloatSize += 1;
        } else if (strType == "vec2" || strType == "vec3" || strType == "vec4") {
            type = ShaderInfoType::Vector;
            tempFloatSize += 4;
        } else if (strType == "sampler2D") {
            type = ShaderInfoType::Texture;
            tempTextureSize += 1;
        } else {
            return;
        }
        ShaderInfo tempShaderInfo;
        tempShaderInfo.type =  type;

        tempShaderInfo.name = String::Combine({"material.", key});
        this->shaderInfo->Push(tempShaderInfo);
        info = info + strType + " " + std::string(key) + ";\n";
    });
    std::string finalInfo = infoBegin + info + infoEnd;
    String::ReplaceFirst(this->vertexShaderCode, "SHADER_MATERIAL_PROPERTY", finalInfo);
    String::ReplaceFirst(this->fragmentShaderCode, "SHADER_MATERIAL_PROPERTY", finalInfo);
}

Shader::Shader() {
    this->shaderInfo = new Queue<ShaderInfo>();
}
