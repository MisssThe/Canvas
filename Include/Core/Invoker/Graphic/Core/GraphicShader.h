//
// Created by MisThe on 2023/6/24.
//

#ifndef CANVAS_1_0_GRAPHICSHADER_H
#define CANVAS_1_0_GRAPHICSHADER_H


#include "../../../Framework/CustomPtr.h"

class GraphicShader : public CustomPtr {
public:
    virtual void SetFloat(std::string_view key,float x) = 0;
    virtual void SetVector(std::string_view key,float x, float y,float z,float w) = 0;
//    virtual void SetTexture(std::string key, Texture* texture) = 0;
};


#endif //CANVAS_1_0_GRAPHICSHADER_H
