//
// Created by Administrator on 2023/7/25.
//

#include "TempCustomPtr.h"

Ptr::Ptr() {
    this->isMark = false;
    GarbageCollection::S_Register(this);
    //非主线程上创建的任务需要注册到线程池的数据集中
    if (!ThreadPool::S_IsMainThread()) {
        ThreadPool::S_RegisterPtr(this);
    }
}

void Ptr::Release() {
    delete this;
}

void Ptr::Mark() {
    if (this->isMark)
        return;
    this->isMark = true;
    this->MarkSelf();
}


void SerializePtr::serialize(cereal::BinaryInputArchive &archive) {
    this->ReadPtr(archive);
    this->ReadVal(archive);
}

void SerializePtr::serialize(cereal::BinaryOutputArchive &archive) {
    this->WritePtr(archive);
    this->WriteVal(archive);
}

bool SerializePtr::Iterator(const std::function<void(Ptr *)> &call) const {
    return ReflectPtr::Iterator(call);
}


