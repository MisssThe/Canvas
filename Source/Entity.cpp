//
// Created by MisThe on 2023/5/25.
//

#include "../Include/Core/Scene/Entity/Entity.h"
#include "../Include/Core/Framework/ReflectFactory.h"
#include "../Include/General/Tool/Debug.h"
#include "../Include/Core/Framework/Static.h"

void Entity::Read(cereal::BinaryInputArchive &archive) {
    int childSize, componentSize;
    this->name = String::Read(archive, 1)->Pop();
    archive(childSize, componentSize);
    std::string_view componentName;
    for (int index = 0; index < componentSize; ++index) {
        componentName = String::Read(archive, 1)->Pop();
        auto *component = dynamic_cast<Component *>(ReflectFactory::S_Instance(componentName));
        archive(*component);
        this->components->Push(component);
    }
    for (int index = 0; index < childSize; ++index) {
        auto *entity = new Entity(true);
        entity->SetParent(this);
        archive(*entity);
    }
}

void Entity::Write(cereal::BinaryOutputArchive &archive) {
    String::Write(archive,{this->name});
    archive(this->children->Size(), this->components->Size());
    this->components->IteratorWithout([&archive](Component *component) {
        String::Write(archive,{component->Type()});
        archive(*component);
    });
    this->children->IteratorWithout([&archive](Entity *entity) {
        archive(*entity);
    });
}

void Entity::CustomMark() {
    CustomPtr::S_Mark(this->components);
    CustomPtr::S_Mark(this->children);
}

void Entity::SetParent(Entity *entity) {
    if (this->parent)
        this->parent->children->Remove(this);
    this->parent = entity;
    if (entity == nullptr)
        return;
    entity->children->Push(this);
}

void Entity::Iterator(std::function<void(Entity *)> func) {
    func(this);
    this->children->IteratorWithout([&func](Entity *entity) {
        entity->Iterator(func);
    });
}

Entity::Entity(bool isRoot) {
    this->children = new Queue<Entity*>();
    this->components = new Queue<Component*>();
    this->parent = nullptr;
    if (isRoot)
        return;
    this->SetParent(Static::S_SceneManager()->Active()->Root());
}

void Entity::AddComponent(Component *component) const {
    if (component == nullptr)
        return;
    //查找实体上是否有对应组件
    auto require = component->RequireComponent();
    if (require != nullptr) {
        if (!require->IteratorWithResult([this](std::string_view ct) {
            return this->GetComponent(ct);
        })) {
            return;
        }
    }
    this->components->Push(component);
}

Component* Entity::AddComponent(std::string_view type) const {
    auto* component = dynamic_cast<Component *>(ReflectFactory::S_Instance(type));
    if (component == nullptr)
        Debug::Warn("Add Component", {"Invalid Component Type"});
    this->AddComponent(component);
    return component;
}

Queue<Component *> *Entity::GetComponentsInChildren(std::string_view type, bool all) const {
    auto* result = new Queue<Component*>();
    this->GetComponentsInChildren(type, result, all);
    return result;
}

void Entity::GetComponentsInChildren(std::string_view type, Queue<Component *>* result, bool all) const {
    if (result == nullptr)
        return;
    Component *component = this->GetComponent(type);
    if (component != nullptr && (all || component->enable))
        result->Push(component);
    this->children->IteratorWithout([&type, &result](Entity *entity) {
        entity->GetComponentsInChildren(type, result);
    });
}

Component *Entity::GetComponent(std::string_view type) const {
    Component *result = nullptr;
    this->components->IteratorWithout([&type, &result](Component *component) {
        if (component->Type() == type)
            result = component;
    });
    return result;
}

void Entity::SetActive(bool flag) {
    if (this->active == flag)
        return;
    this->active = flag;
    this->components->IteratorWithout([&flag](Component* component) {
       component->enable = flag;
    });
}

bool Entity::IsActive() const {
    return this->active;
}

void Entity::Destroy() {
    this->parent = nullptr;
    this->components->IteratorWithout([](Component* component) {
        component->Destroy();
    });
}
