//
// Created by MisThe on 2023/6/11.
//

#ifndef CANVAS_1_0_OPENGLSHADER_H
#define CANVAS_1_0_OPENGLSHADER_H


#include "../../Elements/Detail/Shader.h"

class OpenGLShader : public CustomPtr {
protected:
    void CustomMark() override;
    ~OpenGLShader() override;
public:
    explicit OpenGLShader(Shader* shader);
private:
    void CompileShader(Shader* shader);
    unsigned int CompileShaderSource(int type, const std::string& code) const;
public:
    void Bind() const;
    int GetLocation(std::string_view key);
private:
    unsigned int program;
};


#endif //CANVAS_1_0_OPENGLSHADER_H
