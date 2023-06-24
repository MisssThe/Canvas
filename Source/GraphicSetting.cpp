//
// Created by MisThe on 2023/6/3.
//

#include "../Include/Core/Setting/GraphicSetting.h"
#include "../Include/General/Tool/String.h"

void GraphicSetting::Read(cereal::BinaryInputArchive &archive) {
    archive(this->graphicType, this->width, this->height, this->isSync, this->useBoard, this->useTransparent);
    auto result = String::Read(archive, 2);
    this->windowName = result->Pop();
    this->featurePath = result->Pop();
}

void GraphicSetting::Write(cereal::BinaryOutputArchive &archive) {
    archive(this->graphicType, this->width, this->height, this->isSync, this->useBoard, this->useTransparent);
    String::Write(archive, {this->windowName, this->featurePath});
}

void GraphicSetting::CustomMark() {

}

GraphicSetting::GraphicSetting() {
    this->featurePath = "Canvas/Graphic/Features/forward.feature";
}
