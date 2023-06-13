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
    void SetActive(bool active);
    bool IsActive();
    void AddComponent(Component* component) const;
    Component* AddComponent(std::string type) const;
    Component* GetComponent(std::string type);
    Queue<Component*>* GetComponentsInChildren(std::string type, bool all = true);
    void GetComponentsInChildren(std::string type, Queue<Component*>* result, bool all = true);
    void Destroy();
public:
    std::string name;
    Queue<Component*>* components;
    Queue<Entity*>* children;
    Entity* parent;
private:
    bool active;
};

#endif //CANVAS_1_0_ENTITY_H
