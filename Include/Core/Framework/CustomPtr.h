//
// Created by MisThe on 2023/5/21.
// 禁止用户手动删除指针，用户只能通过ptr = null的方式去减少指针引用
// 禁止用户手动开辟线程操作，只能通过提供的线程池进行线程操作
// 使用非Custom Ptr类型的指针要注意手动释放
//

#ifndef CANVAS_1_0_CUSTOMPTR_H
#define CANVAS_1_0_CUSTOMPTR_H

#include <queue>
#include <string>
#include <functional>

class CustomPtr {
public:
    CustomPtr();
    void Release();
public:
    bool isMark;
public:
    static bool S_IsCustomPtr(CustomPtr* ptr);
    static bool S_IsCustomPtr(...);
    template<class T> static bool S_IsNull(T ptr) {
        return false;
    }
    template<class T> static bool S_IsNull(T* ptr) {
        return ptr == nullptr;
    }
    static void S_Mark(CustomPtr* ptr);
    static void S_Mark(...);
//    static void S_Mark(std::string str);
    static void S_Mark(std::function<void()> call);
protected:
    virtual void CustomMark() = 0;
    virtual ~CustomPtr() = default;
};


#endif //CANVAS_1_0_CUSTOMPTR_H
