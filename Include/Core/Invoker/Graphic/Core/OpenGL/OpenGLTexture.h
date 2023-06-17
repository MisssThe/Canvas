//
// Created by MisThe on 2023/6/16.
//

#ifndef CANVAS_1_0_OPENGLTEXTURE_H
#define CANVAS_1_0_OPENGLTEXTURE_H


#include "../../../../Framework/CustomPtr.h"
#include "../../Elements/Detail/Texture.h"

class OpenGLTexture : public CustomPtr {
protected:
    void CustomMark() override;
    ~OpenGLTexture() override = default;
public:
    explicit OpenGLTexture(Texture* texture);
    void Bind(int index);
private:
    void CompileTexture(Texture* texture);
private:
    unsigned int tex;
};


#endif //CANVAS_1_0_OPENGLTEXTURE_H
