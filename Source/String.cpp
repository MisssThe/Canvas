//
// Created by MisThe on 2023/6/11.
//

#include "../Include/General/Tool/String.h"
#include <cereal/types/string.hpp>

std::queue<char*> String::stringViews;

void String::ReplaceAll(std::string_view& source, const std::string_view& str1, const std::string_view& str2) {
    unsigned int len1 = str1.length();
    unsigned int len2 = str2.length();
    int pos = -len2;
    std::string s(source);
    while ((pos = source.find(str1,pos + len2)) != std::string::npos) {
        source = s.replace(pos, len1, str2);
    }
    String::Convert(s, source);
}

void String::ReplaceFirst(std::string_view & source, const std::string_view & str1, const std::string_view & str2) {
    unsigned int len1 = str1.length();
    unsigned int pos = source.find(str1);
    std::string s(source);
    source = s.replace(pos, len1, str2);
    String::Convert(s, source);
}

void String::ReplaceLast(std::string_view & source, const std::string_view & str1, const std::string_view & str2) {
    unsigned int len1 = str1.length();
    unsigned int pos = source.find_last_of(str1) - len1 + 1;
    std::string s(source);
    source = s.replace(pos, len1, str2);
    String::Convert(s, source);
}

Vector<std::string_view> *String::Split(std::string_view source, const std::string_view &flag) {
    unsigned int step = flag.length();
    if (step < 1)
        return nullptr;
    int pos = 0, oldPos = 0;
    auto* vector = new Vector<std::string_view>();
    std::vector<std::string> v;
    std::string s(source);
    while ((pos = source.find(flag,oldPos)) != std::string::npos) {
        vector->Add(s.substr(oldPos, pos - oldPos));
        oldPos = pos + step;
    }
    std::string_view final = source.substr(oldPos, source.length() - oldPos);
    if (final.length() > 0)
        vector->Add(final);
    return vector;
}

Queue<std::string_view> *String::Read(cereal::BinaryInputArchive &archive, int size) {
    Queue<std::string_view>* result = new Queue<std::string_view>();
    std::string ss;
    std::string_view sv;
    for (int index = 0; index < size; ++index) {
        archive(ss);
        String::Convert(ss, sv);
        result->Push(sv);
    }
    return result;
}

void String::Write(cereal::BinaryOutputArchive &archive, std::initializer_list<std::string_view> str) {
    for (auto s: str) {
        std::string ss(s);
        archive(ss);
    }
}

void String::Convert(const std::string& source, std::string_view& dest) {
    char* str = new char[source.length()];
    String::stringViews.push(str);
    std::strcat(str,source.data());
    dest = str;
}

std::string_view String::Combine(std::initializer_list<std::string_view> str) {
    int length = 1;
    for (auto s : str) {
        length += s.length();
    }
    char* result = new char[length];
    for (auto s : str) {
        for (auto c : s) {
            *result = c;
            result++;
        }
    }
    *result = '\0';
    result -= length - 1;
    std::string_view sv = result;
    String::stringViews.push(result);
    return sv;
}