//
// Created by MisThe on 2023/5/25.
//

#ifndef CANVAS_1_0_ENTITY_H
#define CANVAS_1_0_ENTITY_H


#include "../Asset/Serialize.h"
#include "../../General/Container/Queue.h"
#include "Invoker/Component/Component.h"
#include "Invoker/SceneInvoker.h"

class Entity : public Serialize {
public:
    Entity();
protected:
    void Read(cereal::BinaryInputArchive &archive) override;
    void Write(cereal::BinaryOutputArchive &archive) override;
    void CustomMark() override;
    ~Entity() override;
public:
    void SetParent(Entity *entity);
    void Iterator(std::function<void(Entity* entity)> func);
    template<class T> void AddComponent() {
        T* temp = new T();
        this->components->Push(temp);
        SceneInvoker::S_Instance()->invoker->Register(temp);
    }
public:
    std::string name;
    Queue<Component*>* components;
    Queue<Entity*>* children;
    Entity* parent;
};


#endif //CANVAS_1_0_ENTITY_H
