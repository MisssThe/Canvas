//
// Created by MisThe on 2023/6/11.
//

#include "../Include/General/String.h"

void String::Replace(std::string& source, const std::string& str1, const std::string& str2) {
    int pos = 0;
    int len1 = str1.length();
    int len2 = str2.length();
    while ((pos = source.find(str1,pos + len2)) != std::string::npos) {
        source = source.replace(pos, len1, str2);
    }
}
