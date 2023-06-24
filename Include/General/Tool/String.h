//
// Created by MisThe on 2023/6/11.
// 不要在函数的入口和出口使用std::string，不要使用std::string作成员变量，使用std::string_view替代
// 需要保留string信息到外部使用时务必使用Convert进行转换保证可控
//

#ifndef CANVAS_1_0_STRING_H
#define CANVAS_1_0_STRING_H

#include <string>
#include "../Container/Vector.h"
#include "cereal/archives/binary.hpp"
#include "../Container/Queue.h"

class String {
public:
	static void ReplaceAll(std::string_view& source, const std::string_view& str1, const std::string_view& str2);
	static void ReplaceFirst(std::string_view& source, const std::string_view& str1, const std::string_view& str2);
	static void ReplaceLast(std::string_view& source, const std::string_view& str1, const std::string_view& str2);
    static Vector<std::string_view>* Split(std::string_view source, const std::string_view &flag);
    static Queue<std::string_view>* Read(cereal::BinaryInputArchive &archive, int size);
    static void Write(cereal::BinaryOutputArchive &archive, std::initializer_list<std::string_view> str);
    static void Convert(const std::string& source, std::string_view& dest);
    static std::string_view Combine(std::initializer_list<std::string_view> str);
private:
    static std::queue<char*> stringViews;
//    static std::string_view Combine(std::initializer_list<std::string_view> st);
};


#endif //CANVAS_1_0_STRING_H
