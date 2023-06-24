//
// Created by MisThe on 2023/6/4.
//

#include "../Include/Core/Invoker/Graphic/Elements/Material.h"
#include "../Include/Core/Framework/Static.h"
#include "../Include/General/Container/ContainSerialize/QueueSerialize.h"
#include "cereal/types/string.hpp"

void Material::CustomMark() {
    CustomPtr::S_Mark(this->shader);
    CustomPtr::S_Mark(this->textureQueue);
    CustomPtr::S_Mark(this->floatQueue);
//    CustomPtr::S_Mark(this->shader);
//    CustomPtr::S_Mark(this->shader);
}

void Material::Read(cereal::BinaryInputArchive &archive) {
    std::string_view p;
    p = String::Read(archive, 1)->Pop();
    this->shader = Static::S_AssetManager()->Instance<Shader>(p);
    this->textureQueue = QueueSerialize::Read<Texture *>(archive, [&archive, &p]() -> Texture * {
        p = String::Read(archive, 1)->Pop();
        auto *texture = Static::S_AssetManager()->Instance<Texture>(p);
        return texture;
    });
}

void Material::Write(cereal::BinaryOutputArchive &archive) {
    String::Write(archive, {this->shader->path});
    QueueSerialize::Write<Texture *>(archive, this->textureQueue, [&archive](Texture *texture) {
        String::Write(archive, {texture->path});
    });
}

Material::Material() {
    this->shader = Static::S_AssetManager()->Instance<Shader>("Canvas/Caches/Shader/Canvas_Assets_Shader_Texture_texture.Shader");
    this->textureQueue = new Queue<Texture*>();
    this->floatQueue = new Queue<float>();
}
