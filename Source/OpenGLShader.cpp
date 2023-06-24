//
// Created by MisThe on 2023/6/11.
//

#include <glad/glad.h>
#include "../Include/Core/Invoker/Graphic/Core/OpenGL/OpenGLShader.h"
#include "../Include/General/Tool/Debug.h"

void OpenGLShader::CustomMark() {

}

OpenGLShader::OpenGLShader(Shader *shader) {
    if (shader == nullptr)
        return;
    this->program = -1;
    this->CompileShader(shader);
}

void OpenGLShader::Bind() const {
    glUseProgram(program);
}

unsigned int OpenGLShader::CompileShaderSource(int type, const std::string& code) const {
    unsigned int shaderSource = glCreateShader(type);
    if (code.empty()) {
        Debug::Error("Compile Shader Source", {"Empty Shader Source [", code, "]"});
        return -1;
    }
    const char* source = code.c_str();
    glShaderSource(shaderSource, 1, &source, nullptr);
    glCompileShader(shaderSource);
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(shaderSource, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shaderSource, 512, nullptr, infoLog);
        Debug::Warn("Compile Shader Source", {infoLog});
    }
    glAttachShader(this->program, shaderSource);
    return shaderSource;
}

void OpenGLShader::CompileShader(Shader* shader) {
    auto* shaderSource = new Queue<unsigned int>();
    this->program = glCreateProgram();
    shaderSource->Push(this->CompileShaderSource(GL_VERTEX_SHADER, shader->vertexShaderCode.data()));
    shaderSource->Push(this->CompileShaderSource(GL_FRAGMENT_SHADER, shader->fragmentShaderCode.data()));
    glLinkProgram(this->program);
    int success;
    char infoLog[512];
    glGetProgramiv(this->program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(this->program, 512, nullptr, infoLog);
        Debug::Warn("Compile Shader Source", {infoLog});
    }
    shaderSource->IteratorWithout([](unsigned int shaderSource) {
        glDeleteShader(shaderSource);
    });
}

OpenGLShader::~OpenGLShader() {
    glDeleteProgram(this->program);
}

int OpenGLShader::GetLocation(std::string_view key) {
    return glGetUniformLocation(this->program, key.data());
}