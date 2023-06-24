//
// Created by MisThe on 2023/5/25.
//

#ifndef CANVAS_1_0_ENTITY_H
#define CANVAS_1_0_ENTITY_H

#include "../../Asset/Serialize.h"
#include "../../../General/Container/Queue.h"
#include "../../Invoker/Component/Component.h"

class Entity : public Serialize {
public:
    Entity(bool isRoot = false);
protected:
    void Read(cereal::BinaryInputArchive &archive) override;
    void Write(cereal::BinaryOutputArchive &archive) override;
    void CustomMark() override;
public:
    void SetParent(Entity *entity);
    void Iterator(std::function<void(Entity* entity)> func);
    void SetActive(bool flag);
    bool IsActive() const;
    void AddComponent(Component* component) const;
    Component* AddComponent(std::string_view type) const;
    Component* GetComponent(std::string_view type) const;
    Queue<Component*>* GetComponentsInChildren(std::string_view type, bool all = true) const;
    void GetComponentsInChildren(std::string_view type, Queue<Component*>* result, bool all = true) const;
    void Destroy();
public:
    std::string_view name;
    Queue<Component*>* components;
    Queue<Entity*>* children;
    Entity* parent;
private:
    bool active{};
};

#endif //CANVAS_1_0_ENTITY_H
