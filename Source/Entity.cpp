//
// Created by MisThe on 2023/5/25.
//

#include "../Include/Core/Scene/Entity/Entity.h"
#include <cereal/types/string.hpp>

void Entity::Read(cereal::BinaryInputArchive &archive) {
    int childSize, componentSize;
    archive(this->name, childSize, componentSize);
    std::string componentName;
    for (int index = 0; index < componentSize; ++index) {
        archive(componentName);
        Component* component = ComponentInstance::S_Instance(componentName);
        archive(*component);
        this->components->Push(component);
    }
    for (int index = 0; index < childSize; ++index) {
        Entity* entity = new Entity();
        entity->SetParent(this);
        archive(*entity);
    }
}

void Entity::Write(cereal::BinaryOutputArchive &archive) {
    archive(this->name, this->children->Size(), this->components->Size());
    this->components->IteratorWithout([&archive](Component *component) {
        archive(component->Type());
        archive(*component);
    });
    this->children->IteratorWithout([&archive](Entity *entity) {
        archive(*entity);
    });
}

void Entity::CustomMark() {
    CustomPtr::S_Mark(this->components);
    CustomPtr::S_Mark(this->children);
//    CustomPtr::S_Mark(this->parent);
}

Entity::~Entity() = default;

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

void Entity::AddComponent(Component *component) const {
    if (component == nullptr)
        return;
    this->components->Push(component);
}
