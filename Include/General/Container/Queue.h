//
// Created by MisThe on 2023/5/21.
//

#ifndef CANVAS_1_0_QUEUE_H
#define CANVAS_1_0_QUEUE_H


#include <queue>
#include "../../Core/Framework/CustomPtr.h"
#include <cereal/archives/binary.hpp>

template<class T> class Queue : public CustomPtr {
private:
    std::queue<T> queue;
protected:
    void CustomMark() override {
        this->IteratorWithout([](T temp) {
            CustomPtr::S_Mark(temp);
        });
    }
    ~Queue() override = default;
public:
    Queue(Queue<T> const &temp) {
        this->queue = temp.queue;
    }
    Queue() = default;
public:
    void Push(T temp) {
        this->queue.push(temp);
    }
    T Front() {
        return this->queue.front();
    }
    T Pop() {
        T temp = this->queue.front();
        this->queue.pop();
        return temp;
    }
    void Remove(T t) {
        this->IteratorWithRemove([&t](T temp) {
            return temp != t;
        });
    }
    int Size() {
        return this->queue.size();
    }
    void Clear() {
        std::queue<T> empty;
        std::swap(this->queue, empty);
    }
    void IteratorWithout(std::function<void(T)> func) {
        this->IteratorWithRemove([&func](T temp) -> bool {
            func(temp);
            return true;
        });
    }
    bool IteratorWithRemove(std::function<bool(T)> func) {
        int size = this->queue.size();
        for (int index = 0; index < size; ++index) {
            T temp = this->queue.front();
            this->queue.pop();
            if (func(temp))
                this->queue.push(temp);
        }
        return this->queue.size() == size;
    }
    bool IteratorWithResult(std::function<bool(T)> func) {
        int size = this->queue.size();
        bool result = true;
        for (int index = 0; index < size; ++index) {
            T temp = this->queue.front();
            this->queue.pop();
            result &= func(temp);
            this->queue.push(temp);
        }
        return result;
    }
    bool Contain(T temp) {
        return !this->IteratorWithResult([&temp](T t) {
            return t != temp;
        });
    }
};

#endif //CANVAS_1_0_QUEUE_H
