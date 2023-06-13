//
// Created by MisThe on 2023/6/4.
//

#include "../Include/Core/Invoker/Graphic/Elements/Material.h"
#include "../Include/Core/Framework/Static.h"

void Material::CustomMark() {
    CustomPtr::S_Mark(this->shader);
//    CustomPtr::S_Mark(this->shader);
//    CustomPtr::S_Mark(this->shader);
}

void Material::Read(cereal::BinaryInputArchive &archive) {
    std::string path;
    archive(path);
    this->shader = Static::S_AssetManager()->Instance<Shader>(path);}

void Material::Write(cereal::BinaryOutputArchive &archive) {
    archive(this->shader->path);
}
