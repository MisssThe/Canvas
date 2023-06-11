//
// Created by MisThe on 2023/6/11.
//

#include "../Include/Core/Scene/SceneInfo.h"

void SceneInfo::Read(cereal::BinaryInputArchive &archive) {
    archive(*this->root);
}

void SceneInfo::Write(cereal::BinaryOutputArchive &archive) {
    archive(*this->root);
}

void SceneInfo::CustomMark() {
    CustomPtr::S_Mark(this->root);
}

SceneInfo::SceneInfo() {
    this->root = new Entity(true);
    this->root->name = "root";
}
