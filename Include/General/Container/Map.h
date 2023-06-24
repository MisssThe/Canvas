//
// Created by MisThe on 2023/5/21.
//

#ifndef CANVAS_1_0_MAP_H
#define CANVAS_1_0_MAP_H


#include "../../Core/Framework/CustomPtr.h"
#include <unordered_map>

template<class Key, class Value> class Map : public CustomPtr
{
private:
    std::unordered_map<Key, Value> map;
    Value empty;
protected:
    void CustomMark() override {
        this->Iterator([](Key k, Value v) {
            CustomPtr::S_Mark(k);
            CustomPtr::S_Mark(v);
        });
    }
public:
    Map(Value defaultEmpty = nullptr)
    {
        this->empty = defaultEmpty;
    }
    Map(std::initializer_list<std::pair<Key, Value>> list) {
        this->Insert(list);
    }
    //string无法使用建议使用下面At
    Value Get(Key& key) {
        auto temp = this->map.find(key);
        if (temp == this->map.end())
            return this->empty;
        return temp->second;
    }
    bool Set(Key& key, Value& value) {
        if (!this->Contain(key))
            return false;
        this->map[key] = value;
        return true;
    }
    void Insert(std::initializer_list<std::pair<Key, Value>> list) {
        for (auto init : list) {
            this->Insert(init.first, init.second);
        }
    }
    void Insert(Key key, Value value) {
        this->map.insert(std::pair<Key, Value>(key, value));
    }
    bool Contain(Key key) {
        return this->map.find(key) != map.end();
    }
    void Remove(Key key) {
        this->map.erase(key);
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
