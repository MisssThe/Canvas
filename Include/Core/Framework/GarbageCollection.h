//
// Created by MisThe on 2023/5/21.
//

#ifndef CANVAS_1_0_GARBAGECOLLECTION_H
#define CANVAS_1_0_GARBAGECOLLECTION_H


#include "CustomPtr.h"
#include "../../General/Container/Queue.h"

class GarbageCollection final
{
public:
    struct GarbageCollectionConfig
    {
    public:
        int interval;   //调用间隔
    };
public:
    GarbageCollection() = delete;
    ~GarbageCollection() = delete;
    static void S_Config(GarbageCollectionConfig config);
    static void S_AddRoot(CustomPtr* root);
    static void S_Invoke();
    static void S_Register(CustomPtr* ptr);
    static void S_Release();
private:
    static int _interval;
    static int _waitTime;
    static Queue<CustomPtr*>* S_rootQueue;
    static Queue<CustomPtr*>* S_ptrQueue;
};


#endif //CANVAS_1_0_GARBAGECOLLECTION_H
