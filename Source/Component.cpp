//
// Created by MisThe on 2023/5/25.
//

#include "../Include/Core/Scene/Invoker/Component/Component.h"

void Component::Read(cereal::BinaryInputArchive &archive) {
    archive(this->enable, this->destroy);
}

void Component::Write(cereal::BinaryOutputArchive &archive) {
    archive(this->enable, this->destroy);
}