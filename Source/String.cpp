//
// Created by MisThe on 2023/6/11.
//

#include "../Include/General/String.h"

std::string String::Replace(std::string &source, const std::string &str1, const std::string &str2) {
    return source.replace(source.find(str1), str1.length(),str2);
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