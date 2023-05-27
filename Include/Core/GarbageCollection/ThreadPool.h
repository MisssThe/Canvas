//
// Created by MisThe on 2023/5/28.
//

#ifndef CANVAS_1_0_THREADPOOL_H
#define CANVAS_1_0_THREADPOOL_H

#include <thread>
#include "../../General/Container/Map.h"
#include "../../General/Container/Queue.h"

class ThreadPool {
public:
    struct ThreadPoolConfig
    {
    public:
        int maxThread;
    };
    struct Task
    {

    };
public:
    static void S_Config(ThreadPoolConfig config);
    static bool S_IsMainThread();
    static Task S_InvokeTask(const std::function<void()>& task);
    static void S_RegisterPtr(CustomPtr* ptr);
private:
    static std::thread::id S_mainThreadID;
    static Map<std::thread::id, Queue<CustomPtr*>*>* S_threadPtrMap;
    static Queue<Queue<CustomPtr*>*>* S_threadPtrCacheQueue;
};


#endif //CANVAS_1_0_THREADPOOL_H
