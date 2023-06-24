//
// Created by MisThe on 2023/6/4.
//

#include "../Include/Core/Setting/SceneSetting.h"
#include "../Include/General/Tool/String.h"

void SceneSetting::Read(cereal::BinaryInputArchive &archive) {
    this->editorScenePath = String::Read(archive, 1)->Pop();
}

void SceneSetting::Write(cereal::BinaryOutputArchive &archive) {
    String::Write(archive, {this->editorScenePath});
}

void SceneSetting::CustomMark() {

}

SceneSetting::SceneSetting() {
    this->editorScenePath = "Canvas/Scene/editor.scene";
    this->activeScenePath = "Canvas/Scene/active.scene";
}
