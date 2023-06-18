//
// Created by MisThe on 2023/6/11.
//

#include "../Include/General/String.h"

void String::ReplaceAll(std::string& source, const std::string& str1, const std::string& str2) {
    int len1 = str1.length();
    int len2 = str2.length();
    int pos = -len2;
    while ((pos = source.find(str1,pos + len2)) != std::string::npos) {
        source = source.replace(pos, len1, str2);
    }
}

void String::ReplaceFirst(std::string& source, const std::string& str1, const std::string& str2) {
    int len1 = str1.length();
    int pos = source.find(str1);
    source = source.replace(pos, len1, str2);
}

void String::ReplaceLast(std::string& source, const std::string& str1, const std::string& str2) {
    int len1 = str1.length();
    int pos = source.find_last_of(str1) - len1 + 1;
    source = source.replace(pos, len1, str2);
}

Vector<std::string> *String::Split(std::string source, const std::string &flag) {
    int step = flag.length();
    if (step < 1)
        return nullptr;
    int pos = 0, oldPos = 0;
    Vector<std::string>* vector = new Vector<std::string>();
    std::vector<std::string> v;
    while ((pos = source.find(flag,oldPos)) != std::string::npos) {
        vector->Add(source.substr(oldPos, pos - oldPos));
        oldPos = pos + step;
    }
    std::string final = source.substr(oldPos, source.length() - oldPos);
    if (final.length() > 0)
        vector->Add(final);
    return vector;
}