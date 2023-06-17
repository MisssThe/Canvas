//
// Created by MisThe on 2023/6/8.
//

#include "../Include/Core/Invoker/Graphic/Elements/Detail/Texture.h"

void Texture::Read(cereal::BinaryInputArchive &archive) {
    archive(this->texturePath);
}

void Texture::Write(cereal::BinaryOutputArchive &archive) {
    archive(this->texturePath);
}

void Texture::CustomMark() {

}

void Texture::Cache(std::string file) {
    this->texturePath = file;
}
