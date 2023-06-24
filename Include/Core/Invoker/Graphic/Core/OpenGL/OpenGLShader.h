//
// Created by MisThe on 2023/6/11.
//

#ifndef CANVAS_1_0_OPENGLSHADER_H
#define CANVAS_1_0_OPENGLSHADER_H


#include "../../Elements/Detail/Shader.h"
#include "../GraphicShader.h"

class OpenGLShader : public GraphicShader {
protected:
    void CustomMark() override;
    ~OpenGLShader() override;
public:
    explicit OpenGLShader(Shader* shader);
private:
    void CompileShader(Shader* shader);
    unsigned int CompileShaderSource(int type, const std::string& code) const;
public:
    void SetFloat(std::string_view key,float x) override;
    void SetVector(std::string_view key,float x, float y,float z,float w) override;
//    void SetTexture(std::string key, Texture* texture) override;
public:
    void Bind() const;
private:
    unsigned int program;
};


#endif //CANVAS_1_0_OPENGLSHADER_H
