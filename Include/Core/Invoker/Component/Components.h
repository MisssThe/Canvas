//
// Created by MisThe on 2023/5/28.
//

#ifndef CANVAS_1_0_COMPONENTS_H
#define CANVAS_1_0_COMPONENTS_H


#include "../../../General/Container/Queue.h"
#include "../../../General/Container/Map.h"

class Component;

class Components final : public CustomPtr
{
public:
    Components();
    void Invoke();
    void Register(Component*component);
private:
    void CustomMark() override;
private:
    Queue<Component *> *initial;
    Queue<Component *> *onEnable;
    Queue<Component *> *invoke;
    Queue<Component *> *onDisable;
    Queue<Component *> *disabled;
    Queue<Component *> *destroy;
};


#endif //CANVAS_1_0_COMPONENTS_H
