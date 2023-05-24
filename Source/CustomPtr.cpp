//
// Created by MisThe on 2023/5/21.
//

#include "../Include/Core/GarbageCollection/CustomPtr.h"
#include "../Include/Core/GarbageCollection/GarbageCollection.h"

CustomPtr::CustomPtr() {
    this->isMark = false;
    GarbageCollection::_Register(this);
}

CustomPtr::~CustomPtr() {
    //普普通通的析构
}

void CustomPtr::Release() {
    delete this;
}

void CustomPtr::Mark() {
    //避免循环引用
    if (this->isMark)
        return;
    this->isMark = true;
    this->CustomMark();
}

bool CustomPtr::S_IsCustomPtr(...) {
    return false;
}

bool CustomPtr::S_IsCustomPtr(CustomPtr *ptr) {
    return true;
}

void CustomPtr::S_Mark(CustomPtr *ptr) {
    ptr->Mark();
}

void CustomPtr::S_Mark(...) {

}

void CustomPtr::S_Mark(std::string str) {

}
