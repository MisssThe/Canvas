//
// Created by MisThe on 2023/5/21.
//

#ifndef CANVAS_1_0_GARBAGECOLLECTION_H
#define CANVAS_1_0_GARBAGECOLLECTION_H


#include "CustomPtr.h"
#include "../../General/Container/Queue.h"

class GarbageCollection {
public:
    class GarbageCollectionConfig
    {
    public:
        int interval;   //调用间隔
    };
public:
    GarbageCollection() = delete;
    ~GarbageCollection() = delete;
    static void _Config(GarbageCollectionConfig config);
    static void AddRoot(CustomPtr* root);
    static void _Invoke();
    static void _Register(CustomPtr* ptr);
//    static void _UnDestroy(CustomPtr* ptr);
private:
    static int _interval;
    static int _waitTime;
    static Queue<CustomPtr*>* _rootQueue;
    static Queue<CustomPtr*>* _ptrQueue;
};


#endif //CANVAS_1_0_GARBAGECOLLECTION_H
