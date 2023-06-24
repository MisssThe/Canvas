//
// Created by MisThe on 2023/6/16.
//

#include "../Include/Core/Invoker/Graphic/Core/OpenGL/OpenGLTexture.h"
#include "../Include/General/Tool/Debug.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <glad/glad.h>

void OpenGLTexture::CustomMark() {

}

OpenGLTexture::OpenGLTexture(Texture *texture) {
    this->CompileTexture(texture);
}

void OpenGLTexture::CompileTexture(Texture *texture) {
    glGenTextures(1, &this->tex);
    glBindTexture(GL_TEXTURE_2D, this->tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load(texture->texturePath.data(), &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        Debug::Warn("Texture", {"Compile Failed [", texture->texturePath, "]"});
    }
    stbi_image_free(data);
}

void OpenGLTexture::Bind(int index) {
    glActiveTexture(GL_TEXTURE0 + index);
    glBindTexture(GL_TEXTURE_2D, this->tex);
}