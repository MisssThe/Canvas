//
// Created by MisThe on 2023/6/5.
//

#include "../Include/Core/Invoker/Graphic/Elements/Detail/Shader.h"
#include "../Include/General/IO.h"
#include "../Include/General/String.h"

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
    String::ReplaceLast(propShaderPath, extension, "prop");
    String::ReplaceLast(vertShaderPath, extension, "vert");
    String::ReplaceLast(fragShaderPath, extension, "frag");
    //收集shader info
    IO::ReadInfo(vertShaderPath, this->vertexShaderCode);
    IO::ReadInfo(fragShaderPath, this->fragmentShaderCode);
    //读取Property数据并进行填充
}
