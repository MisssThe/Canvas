//
// Created by MisThe on 2023/5/21.
//

#ifndef CANVAS_1_0_MAP_H
#define CANVAS_1_0_MAP_H


#include "../../Core/GarbageCollection/CustomPtr.h"
#include <unordered_map>

template<class Key, class Value> class Map : public CustomPtr
{
private:
    std::unordered_map<Key, Value> map;
protected:
    void CustomMark() override {
        this->Iterator([](Key k, Value v) {
            CustomPtr::S_Mark(k);
            CustomPtr::S_Mark(v);
        });
    }
    ~Map() override {

    }
public:
    Value Get(Key& key) {
        auto temp = this->map.find(key);
        if (temp == this->map.end())
            return nullptr;
        return temp->second;
    }

    void Insert(Key key, Value value) {
        this->map.insert(std::pair<Key, Value>(key, value));
    }

    bool Contain(Key key) {
        return this->map.find(key) != nullptr;
    }

    void Remove(Key key) {
        this->map.earse(key);
    }

    void Clear() {
        this->map.clear();
    }
    void Iterator(std::function<void(Key key, Value value)> func) {
        for (auto m : this->map) {
            func(m.first, m.second);
        }
    }
    int Size() {
        return this->map.size();
    }
};


#endif //CANVAS_1_0_MAP_H
