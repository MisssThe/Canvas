//
// Created by MisThe on 2023/5/28.
//

#ifndef CANVAS_1_0_COMPONENTSINVOKER_H
#define CANVAS_1_0_COMPONENTSINVOKER_H


#include "Component.h"
#include "../../../../General/Container/Queue.h"

class ComponentsInvoker final : public CustomPtr
{
public:
    ComponentsInvoker();
    void Invoke();
    void Register(Component*component);
private:
    void CustomMark() override;
    ~ComponentsInvoker() override = default;
private:
    Queue<Component *> *initial;
    Queue<Component *> *onEnable;
    Queue<Component *> *invoke;
    Queue<Component *> *onDisable;
    Queue<Component *> *disabled;
    Queue<Component *> *destroy;
};


#endif //CANVAS_1_0_COMPONENTSINVOKER_H
