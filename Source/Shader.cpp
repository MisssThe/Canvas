//
// Created by MisThe on 2023/6/5.
//

#include "../Include/Core/Invoker/Graphic/Elements/Detail/Shader.h"
#include "../Include/General/IO.h"
#include "../Include/General/String.h"
#include "../Include/Core/Asset/CustomJson.h"

void Shader::Read(cereal::BinaryInputArchive &archive) {
    archive(vertexShaderCode, fragmentShaderCode);
}

void Shader::Write(cereal::BinaryOutputArchive &archive) {
    archive(vertexShaderCode, fragmentShaderCode);
}

void Shader::CustomMark() {

}

void Shader::Cache(std::string file) {
    //收集所有相关shader
    std::string extension = IO::PathToExtension(file);
    std::string propShaderPath = file;
    std::string vertShaderPath = file;
    std::string fragShaderPath = file;
    String::ReplaceLast(propShaderPath, extension, "sprop");
    String::ReplaceLast(vertShaderPath, extension, "vert");
    String::ReplaceLast(fragShaderPath, extension, "frag");
    //收集shader info
    IO::ReadInfo(vertShaderPath, this->vertexShaderCode);
    IO::ReadInfo(fragShaderPath, this->fragmentShaderCode);
    //读取Property数据并进行填充
    this->CompressShaderProperty(propShaderPath);
}

void Shader::CompressShaderProperty(std::string &propertyPath) {
    //将SHADER_MATERIAL_PROPERTY 替换为 propertyPath
    std::string infoBegin = "struct Material {\n";
    std::string infoEnd = "}; uniform Material";
    std::string info;
    //解析property
    CustomJson *cj = new CustomJson(propertyPath);
    cj->Iterator([&info](std::string &key, Json::Value &value) {
        if (!value.isString())
            return;
        info += "   " + value.asString() + " " + key + ";\n";
    });
    std::string finalInfo = infoBegin + info + infoEnd;
    String::ReplaceFirst(this->vertexShaderCode, "SHADER_MATERIAL_PROPERTY", finalInfo);
    String::ReplaceFirst(this->fragmentShaderCode, "SHADER_MATERIAL_PROPERTY", finalInfo);
}
