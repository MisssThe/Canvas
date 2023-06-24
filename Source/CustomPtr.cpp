//
// Created by MisThe on 2023/5/21.
//

#include "../Include/Core/Framework/CustomPtr.h"
#include "../Include/Core/Framework/GarbageCollection.h"
#include "../Include/Core/Framework/ThreadPool.h"

CustomPtr::CustomPtr() {
    this->isMark = false;
    GarbageCollection::S_Register(this);
    //非主线程上创建的任务需要注册到线程池的数据集中
    if (!ThreadPool::S_IsMainThread()) {
        ThreadPool::S_RegisterPtr(this);
    }
}

void CustomPtr::Release() {
    delete this;
}

bool CustomPtr::S_IsCustomPtr(...) {
    return false;
}

bool CustomPtr::S_IsCustomPtr(CustomPtr *ptr) {
    return true;
}

void CustomPtr::S_Mark(CustomPtr *ptr) {
    if (ptr == nullptr)
        return;
    //避免循环引用
    if (ptr->isMark)
        return;
    ptr->isMark = true;
    ptr->CustomMark();
}

void CustomPtr::S_Mark(std::function<void()> call) {

}

void CustomPtr::S_Mark(...) {

}