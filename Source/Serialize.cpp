//
// Created by MisThe on 2023/5/21.
//

#include "../Include/Core/Asset/Serialize.h"
#include <cereal/types/string.hpp>

void Serialize::serialize(cereal::BinaryInputArchive &archive) {
    this->Read(archive);
}

void Serialize::serialize(cereal::BinaryOutputArchive &archive) {
    this->Write(archive);
}