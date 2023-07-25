//
// Created by Administrator on 2023/7/25.
//

#ifndef CANVAS_1_0_TEMPCUSTOMPTR_H
#define CANVAS_1_0_TEMPCUSTOMPTR_H

#include <string>
#include <functional>
#include <cereal/archives/binary.hpp>
#include "../../Core/Framework/CustomPtr.h"
#include <cereal/types/string.hpp>

class Ptr {
public:
    Ptr();
public:
    void Release();
    void Mark();
    virtual void MarkSelf() = 0;
private:
    bool isMark = false;
protected:
    virtual ~Ptr() = default;
};

// 参数个数范围为1~15，超过需要手动扩展
#define COUNT_IMP(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, NUM, ...) NUM
#define COUNT(...) COUNT_IMP(__VA_ARGS__, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

#define REFLECT_1(arg) call(this->arg);
#define REFLECT_2(arg, ...)  REFLECT_1(arg) REFLECT_1(__VA_ARGS__)
#define REFLECT_3(arg, ...)  REFLECT_1(arg) REFLECT_2(__VA_ARGS__)
#define REFLECT_4(arg, ...)  REFLECT_1(arg) REFLECT_3(__VA_ARGS__)
#define REFLECT_5(arg, ...)  REFLECT_1(arg) REFLECT_4(__VA_ARGS__)
#define REFLECT_6(arg, ...)  REFLECT_1(arg) REFLECT_5(__VA_ARGS__)
#define REFLECT_7(arg, ...)  REFLECT_1(arg) REFLECT_6(__VA_ARGS__)
#define REFLECT_8(arg, ...)  REFLECT_1(arg) REFLECT_7(__VA_ARGS__)
#define REFLECT_9(arg, ...)  REFLECT_1(arg) REFLECT_8(__VA_ARGS__)
#define REFLECT_10(arg, ...) REFLECT_1(arg) REFLECT_9(__VA_ARGS__)
#define REFLECT_11(arg, ...) REFLECT_1(arg) REFLECT_10(__VA_ARGS__)
#define REFLECT_12(arg, ...) REFLECT_1(arg) REFLECT_11(__VA_ARGS__)
#define REFLECT_13(arg, ...) REFLECT_1(arg) REFLECT_12(__VA_ARGS__)
#define REFLECT_14(arg, ...) REFLECT_1(arg) REFLECT_13(__VA_ARGS__)
#define REFLECT_15(arg, ...) REFLECT_1(arg) REFLECT_14(__VA_ARGS__)

#define SYMBOL_CATENATE(arg1, arg2) arg1##arg2
#define SYMBOL_CATENATE_WITH_MACRO(arg1, arg2) SYMBOL_CATENATE(arg1, arg2)

#define REFLECT(...)  bool Iterator(const std::function<void(Ptr *)> &call) const override { SYMBOL_CATENATE_WITH_MACRO(REFLECT_, COUNT(__VA_ARGS__))(__VA_ARGS__) return true;}
#define MARCO(marco) marco

#define CUSTOM_PTR(...) \
public:                 \
MARCO(REFLECT(__VA_ARGS__)) \
void MarkSelf() override { this->Iterator([](Ptr *ptr) ->void { ptr->Mark(); }); } \
protected:              \
void ReadPtr(cereal::BinaryInputArchive &archive) override { this->Iterator([archive](Ptr *ptr) ->void { archive(*ptr); }); } \
void WritePtr(cereal::BinaryInputArchive &archive) override { this->Iterator([archive](Ptr *ptr) ->void { archive(*ptr); }); }

#define CUSTOM_VAL(...)
#define REGISTER(type) bool type##Register = Reflect::S_Register(#type, []()->Ptr*{ return new type(); });


class ReflectPtr : public Ptr {
public:
    virtual bool Iterator(const std::function<void(Ptr *)> &call) const { return false; };
protected:
    ~ReflectPtr() override = default;
};

class SerializePtr : public ReflectPtr {
public:
    void serialize(cereal::BinaryInputArchive& archive);
    void serialize(cereal::BinaryOutputArchive& archive);
protected:
    virtual void ReadPtr(cereal::BinaryInputArchive& archive) = 0;
    virtual void ReadVal(cereal::BinaryInputArchive& archive) = 0;
protected:
    virtual void WritePtr(cereal::BinaryOutputArchive& archive) = 0;
    virtual void WriteVal(cereal::BinaryOutputArchive& archive) = 0;
protected:
    ~SerializePtr() override = default;
};

class CustomPtr : public SerializePtr {
protected:
    ~CustomPtr() override = default;
};

class TestPtr : public CustomPtr {
CUSTOM_PTR(arg);
protected:
    ~TestPtr() override = default;
};


#endif //CANVAS_1_0_TEMPCUSTOMPTR_H
