//
// Created by MisThe on 2023/5/28.
//

#ifndef CANVAS_1_0_SCENEINVOKER_H
#define CANVAS_1_0_SCENEINVOKER_H


#include "Component/ComponentsInvoker.h"
#include "Psycho/Psycho.h"
#include "Graphic/Graphic.h"

class SceneInvoker : public CustomPtr
{
public:
    static SceneInvoker* S_Instance();
public:
    void Invoke();
protected:
    void CustomMark() override;
    ~SceneInvoker() override;
public:
    ComponentsInvoker* invoker;
    Psycho* psycho;
    Graphic* graphic;
private:
    SceneInvoker();
private:
    static SceneInvoker* S_instance;
};


#endif //CANVAS_1_0_SCENEINVOKER_H
