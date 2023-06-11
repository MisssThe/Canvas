//
// Created by MisThe on 2023/6/11.
//

#include "../Include/General/String.h"

std::string String::Replace(std::string source, std::string str1, std::string str2) {
    return source.replace(source.find(str1), str1.length(),str2);
}
