//
// Created by MisThe on 2023/6/4.
//

#include "../Include/Core/Setting/SceneSetting.h"
#include "cereal/types/string.hpp"

void SceneSetting::Read(cereal::BinaryInputArchive &archive) {
    archive(this->editorScenePath);
}

void SceneSetting::Write(cereal::BinaryOutputArchive &archive) {
    archive(this->editorScenePath);
}

void SceneSetting::CustomMark() {

}

SceneSetting::SceneSetting() {
    this->editorScenePath = "Canvas/Scene/editor.scene";
    this->activeScenePath = "Canvas/Scene/active.scene";
}
