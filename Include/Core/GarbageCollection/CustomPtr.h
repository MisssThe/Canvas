//
// Created by MisThe on 2023/5/21.
//

#ifndef CANVAS_1_0_CUSTOMPTR_H
#define CANVAS_1_0_CUSTOMPTR_H

#include <cstdlib>
#include <queue>

class CustomPtr {
public:
    CustomPtr();
    void Release();
public:
    void Mark();
    bool isMark;
public:
    static bool S_IsCustomPtr(CustomPtr* ptr);
    static bool S_IsCustomPtr(...);
    static void S_Mark(CustomPtr* ptr);
    static void S_Mark(...);
    static void S_Mark(std::string str);
protected:
    virtual void CustomMark() = 0;
    virtual ~CustomPtr();
};


#endif //CANVAS_1_0_CUSTOMPTR_H
