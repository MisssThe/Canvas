//
// Created by MisThe on 2023/5/25.
//

#include "../Include/Core/Scene/Entity.h"
#include <cereal/types/string.hpp>

void Entity::Read(cereal::BinaryInputArchive &archive) {
    this->components = new Queue<Component*>();
//    archive(this->name, this->components);
}

void Entity::Write(cereal::BinaryOutputArchive &archive) {
//    archive(this->name, this->components);
}

void Entity::CustomMark() {

}

Entity::~Entity() {

}
