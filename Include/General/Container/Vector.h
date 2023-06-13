//
// Created by MisThe on 2023/5/21.
//

#ifndef CANVAS_1_0_VECTOR_H
#define CANVAS_1_0_VECTOR_H


#include "../../Core/Framework/CustomPtr.h"

template<class T> class Vector : public CustomPtr
{
protected:
    void CustomMark() override {

    }
    ~Vector() override = default;
public:
    Vector() = default;
    explicit Vector(int size) {
        this->vector.resize(size);
    }
    Vector(std::initializer_list<T> list) {
        this->vector = list;
    }
    void Iterator(std::function<void(T t)> func) {
        for (T temp : this->vector) {
            func(temp);
        }
    }
    void Add(T& temp) {
        this->vector.push_back(temp);
    }
    void* Begin() {
        if (this->Size() < 1)
            return nullptr;
        return &this->vector[0];
    }
    int Size() {
        return this->vector.size();
    }
    int MemorySize() {
        return this->Size() * sizeof(T);
    }
    T Get(int index) {
        return this->vector[index];
    }
private:
    std::vector<T> vector;
};


#endif //CANVAS_1_0_VECTOR_H
