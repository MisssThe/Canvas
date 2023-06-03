//
// Created by MisThe on 2023/5/28.
//

#ifndef CANVAS_1_0_INVOKER_H
#define CANVAS_1_0_INVOKER_H


#include "Component/Components.h"
#include "Psycho/Psycho.h"
#include "Graphic/Graphic.h"

class Invoker : public CustomPtr
{
public:
    struct SceneInvokerConfig
    {

    };
public:
    static void S_Config(SceneInvokerConfig config);
    static Invoker* S_Instance();
    static void S_Pause();
    static void S_Resume();
public:
    void Invoke() const;
protected:
    void CustomMark() override;
    ~Invoker() override;
public:
    Components* components;
    Psycho* psycho;
    Graphic* graphic;
private:
    Invoker();
private:
    static Invoker* S_instance;
    static bool S_notPause;
};


#endif //CANVAS_1_0_INVOKER_H
