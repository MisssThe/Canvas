//
// Created by MisThe on 2023/5/21.
//

#include "../Include/Core/GarbageCollection/GarbageCollection.h"
#include "../Include/General/Debug.h"

Queue<CustomPtr*>* GarbageCollection::_ptrQueue;
Queue<CustomPtr*>* GarbageCollection::_rootQueue;
int GarbageCollection::_interval = 0;
int GarbageCollection::_waitTime = 0;

void GarbageCollection::_Config(GarbageCollectionConfig config) {
    if (config.interval < 0)
        return;
    GarbageCollection::_interval = config.interval;
    GarbageCollection::_waitTime = 0;

    if (GarbageCollection::_ptrQueue == nullptr)
        GarbageCollection::_ptrQueue = new Queue<CustomPtr *>();
    if (GarbageCollection::_rootQueue == nullptr)
        GarbageCollection::_rootQueue = new Queue<CustomPtr *>();
    GarbageCollection::_ptrQueue->Remove(GarbageCollection::_ptrQueue);
    GarbageCollection::_ptrQueue->Remove(GarbageCollection::_rootQueue);
}

void GarbageCollection::_Invoke() {
    if (GarbageCollection::_waitTime++ < GarbageCollection::_interval)
        return;
    GarbageCollection::_waitTime = GarbageCollection::_interval;

    if (GarbageCollection::_rootQueue == nullptr || GarbageCollection::_ptrQueue == nullptr)
        return;
    Debug::Info("Garbage Collection", "Start Collection [" + std::to_string(GarbageCollection::_rootQueue->Size()) + "]");
    //遍历root节点判断是否需要mark
    GarbageCollection::_rootQueue->IteratorWithout([](CustomPtr *ptr) {
        ptr->Mark();
        ptr->isMark = false;
    });
    int max = GarbageCollection::_ptrQueue->Size();
    int dropCount = 0;
    GarbageCollection::_ptrQueue->IteratorWithRemove([&dropCount](CustomPtr *ptr) {
        if (ptr->isMark) {
            ptr->isMark = false;
            return true;
        } else {
            dropCount++;
            ptr->Release();
            return false;
        }
    });
    Debug::Info("Garbage Collection", "Collection Finish [" + std::to_string(dropCount) + "/" + std::to_string(max) + "]");
}

void GarbageCollection::_Register(CustomPtr *ptr) {
    if (GarbageCollection::_ptrQueue == nullptr)
        return;
    GarbageCollection::_ptrQueue->Push(ptr);
}

void GarbageCollection::AddRoot(CustomPtr *root) {
    if (root == nullptr)
        return;
    if (GarbageCollection::_rootQueue->Contain(root))
        return;
    GarbageCollection::_rootQueue->Push(root);
    GarbageCollection::_ptrQueue->Remove(root);
}