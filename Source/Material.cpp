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
    std::string path;
    archive(path);
    this->shader = Static::S_AssetManager()->Instance<Shader>(path);
    this->textureQueue = QueueSerialize::Read<Texture *>(archive, [&archive, &path]() -> Texture * {
        archive(path);
        Texture *texture = Static::S_AssetManager()->Instance<Texture>(path);
        return texture;
    });
}

void Material::Write(cereal::BinaryOutputArchive &archive) {
    archive(this->shader->path);
    QueueSerialize::Write<Texture*>(archive, this->textureQueue, [&archive](Texture* texture) {
        archive(texture->path);
    });
}

Material::Material() {
    this->shader = Static::S_AssetManager()->Instance<Shader>("Canvas/Caches/Shader/Canvas_Assets_Shader_Texture_texture.Shader");
    this->textureQueue = new Queue<Texture*>();
    this->floatQueue = new Queue<float>();
}
