//
// Created by MisThe on 2023/5/28.
//

#include "../Include/Core/Framework/ThreadPool.h"
#include "../Include/Core/Framework/GarbageCollection.h"

Map<std::thread::id, Queue<CustomPtr*>*>* ThreadPool::S_threadPtrMap = nullptr;
Queue<Queue<CustomPtr*>*>* ThreadPool::S_threadPtrCacheQueue = nullptr;
std::thread::id ThreadPool::S_mainThreadID = std::this_thread::get_id();

bool ThreadPool::S_IsMainThread() {
    return std::this_thread::get_id() == S_mainThreadID;
}

ThreadPool::Task ThreadPool::S_InvokeTask(const std::function<void()>& task) {
    std::thread thread(task);
    thread.join();
    return ThreadPool::Task();
}

void ThreadPool::S_RegisterPtr(CustomPtr *ptr) {
    if (ptr == nullptr)
        return;
    std::thread::id ti = std::this_thread::get_id();
    if (ThreadPool::S_threadPtrMap == nullptr)
        return;
    if (ThreadPool::S_threadPtrMap->Get(ti) == nullptr)
    {
        ThreadPool::S_threadPtrMap->Insert(ti, ThreadPool::S_threadPtrCacheQueue->Pop());
    }
    ThreadPool::S_threadPtrMap->Get(ti)->Push(ptr);
}

void ThreadPool::S_Config(ThreadPool::ThreadPoolConfig config) {
    ThreadPool::S_threadPtrMap = new Map<std::thread::id, Queue<CustomPtr *> *>();
    ThreadPool::S_threadPtrCacheQueue = new Queue<Queue<CustomPtr*>*>();
    for (int index = 0; index < config.maxThread; ++index) {
        ThreadPool::S_threadPtrCacheQueue->Push(new Queue<CustomPtr*>());
    }
    GarbageCollection::S_AddRoot(ThreadPool::S_threadPtrCacheQueue);
    GarbageCollection::S_AddRoot(ThreadPool::S_threadPtrMap);
}