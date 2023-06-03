//
// Created by MisThe on 2023/6/3.
//

#include "../Include/Core/Setting/GraphicSetting.h"

void GraphicSetting::Read(cereal::BinaryInputArchive &archive) {
    archive(this->graphicType);
}

void GraphicSetting::Write(cereal::BinaryOutputArchive &archive) {
    archive(this->graphicType);
}

void GraphicSetting::CustomMark() {

}

GraphicSetting::~GraphicSetting() {

}
