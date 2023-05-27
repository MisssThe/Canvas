//
// Created by MisThe on 2023/5/21.
//

#include "../Include/Core/GarbageCollection/GarbageCollection.h"
#include "../Include/General/Debug.h"

Queue<CustomPtr*>* GarbageCollection::S_ptrQueue;
Queue<CustomPtr*>* GarbageCollection::S_rootQueue;

int GarbageCollection::_interval = 0;
int GarbageCollection::_waitTime = 0;

void GarbageCollection::S_Config(GarbageCollectionConfig config) {
    if (config.interval < 0)
        return;
    GarbageCollection::_interval = config.interval;
    GarbageCollection::_waitTime = 0;

    if (GarbageCollection::S_ptrQueue == nullptr)
        GarbageCollection::S_ptrQueue = new Queue<CustomPtr *>();
    if (GarbageCollection::S_rootQueue == nullptr)
        GarbageCollection::S_rootQueue = new Queue<CustomPtr *>();
    GarbageCollection::S_ptrQueue->Remove(GarbageCollection::S_ptrQueue);
    GarbageCollection::S_ptrQueue->Remove(GarbageCollection::S_rootQueue);
}

//使用标记清除进行垃圾回收
//垃圾回收前要保证线程池内的所有线程完成或暂停执行
void GarbageCollection::S_Invoke() {
    if (GarbageCollection::_waitTime++ < GarbageCollection::_interval)
        return;
    GarbageCollection::_waitTime = GarbageCollection::_interval;

    if (GarbageCollection::S_rootQueue == nullptr || GarbageCollection::S_ptrQueue == nullptr)
        return;
    Debug::Info("Garbage Collection", "Start Collection [" + std::to_string(GarbageCollection::S_rootQueue->Size()) + "]");
    //遍历root节点判断是否需要mark
    GarbageCollection::S_rootQueue->IteratorWithout([](CustomPtr *ptr) {
        CustomPtr::S_Mark(ptr);
    });
    int max = GarbageCollection::S_ptrQueue->Size();
    int dropCount = 0;
    GarbageCollection::S_ptrQueue->IteratorWithRemove([&dropCount](CustomPtr *ptr) {
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

void GarbageCollection::S_Register(CustomPtr *ptr) {
    if (GarbageCollection::S_ptrQueue == nullptr)
        return;
    GarbageCollection::S_ptrQueue->Push(ptr);
}

void GarbageCollection::S_AddRoot(CustomPtr *root) {
    if (root == nullptr)
        return;
    if (GarbageCollection::S_rootQueue->Contain(root))
        return;
    GarbageCollection::S_rootQueue->Push(root);
    GarbageCollection::S_ptrQueue->Remove(root);
}