//
// Created by MisThe on 2023/6/8.
//

#include "../Include/Core/Invoker/Graphic/Elements/Detail/Texture.h"
#include "../Include/General/Tool/String.h"

void Texture::Read(cereal::BinaryInputArchive &archive) {
    this->texturePath = String::Read(archive, 1)->Pop();
}

void Texture::Write(cereal::BinaryOutputArchive &archive) {
    String::Write(archive, {this->texturePath});
}

void Texture::CustomMark() {

}

void Texture::Cache(std::string_view file) {
    this->texturePath = file;
}
