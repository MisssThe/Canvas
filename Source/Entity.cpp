//
// Created by MisThe on 2023/5/25.
//

#include "../Include/Core/Scene/Entity.h"
#include <cereal/types/string.hpp>

void Entity::Read(cereal::BinaryInputArchive &archive) {
//    archive(this->name, this->components, this->children);
}

void Entity::Write(cereal::BinaryOutputArchive &archive) {
//    archive(this->name, this->components, this->children);
}

void Entity::CustomMark() {

}

Entity::~Entity() {

}

void Entity::SetParent(Entity *entity) {
    if (entity == nullptr)
        return;
    if (this->parent)
        this->parent->children->Remove(this);
    this->parent = entity;
    entity->children->Push(this);
}

void Entity::Iterator(std::function<void(Entity *)> func) {
    func(this);
    this->children->IteratorWithout([&func](Entity *entity) {
        entity->Iterator(func);
    });
}

Entity::Entity() {
    this->children = new Queue<Entity*>();
    this->components = new Queue<Component*>();
    this->parent = nullptr;
}
