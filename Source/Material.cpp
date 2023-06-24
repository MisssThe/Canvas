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
    QueueSerialize::Read<float>(archive, this->floatQueue,[&archive]()->float {
        float temp;
        archive(temp);
        return temp;
    });
    QueueSerialize::Read<Texture *>(archive, this->textureQueue, [&archive, &p]() -> Texture * {
        p = String::Read(archive, 1)->Pop();
        auto *texture = Static::S_AssetManager()->Instance<Texture>(p);
        return texture;
    });
}

void Material::Write(cereal::BinaryOutputArchive &archive) {
    String::Write(archive, {this->shader->path});
    QueueSerialize::Write<float>(archive, this->floatQueue, [&archive](float temp) {
        archive(temp);
    });
    QueueSerialize::Write<Texture *>(archive, this->textureQueue, [&archive](Texture *texture) {
        String::Write(archive, {texture->path});
    });
}

Material::Material() {
    this->textureQueue = new Queue<Texture*>();
    this->floatQueue = new Queue<float>();
    this->SetShader(Static::S_AssetManager()->Instance<Shader>("Canvas/Caches/Shader/Canvas_Assets_Shader_Error_error.Shader"));
}

void Material::SetShader(Shader *target) {
    if (target == nullptr || target == this->shader)
        return;
    this->shader = target;
    //设置初始值
    for (int index = 0; index < shader->floatSize; ++index) {
        this->floatQueue->Push(0);
    }
    for (int index = 0; index < shader->textureSize; ++index) {
        //Default Black Texture
        this->textureQueue->Push(nullptr);
    }
}
