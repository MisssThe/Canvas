//
// Created by MisThe on 2023/6/5.
//

#include "../Include/Core/Invoker/Graphic/Elements/Detail/Shader.h"

void Shader::Read(cereal::BinaryInputArchive &archive) {
    archive(vertexShaderPath, fragmentShaderPath);
}

void Shader::Write(cereal::BinaryOutputArchive &archive) {
    archive(vertexShaderPath, fragmentShaderPath);
}

void Shader::CustomMark() {

}
