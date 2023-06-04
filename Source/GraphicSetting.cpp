//
// Created by MisThe on 2023/6/3.
//

#include "../Include/Core/Setting/GraphicSetting.h"
#include <cereal/types/string.hpp>

void GraphicSetting::Read(cereal::BinaryInputArchive &archive) {
    archive(this->graphicType, this->width, this->height, this->isSync, this->name, this->featurePath);
}

void GraphicSetting::Write(cereal::BinaryOutputArchive &archive) {
    archive(this->graphicType, this->width, this->height, this->isSync, this->name, this->featurePath);
}

void GraphicSetting::CustomMark() {

}

GraphicSetting::GraphicSetting() {
    this->featurePath = "Canvas/Graphic/Features/forward.feature";
}
