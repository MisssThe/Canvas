//
// Created by MisThe on 2023/5/25.
//

#include "../Include/Core/Invoker/Component/Component.h"
#include "../Include/Core/Framework/Static.h"

void Component::Read(cereal::BinaryInputArchive &archive) {
    archive(this->enable, this->destroy);
    this->ComponentRead(archive);
}

void Component::Write(cereal::BinaryOutputArchive &archive) {
    archive(this->enable, this->destroy);
    this->ComponentWrite(archive);
}

Component::Component() {
    Static::S_Components()->Register(this);
}
