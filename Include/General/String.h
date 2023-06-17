//
// Created by MisThe on 2023/6/11.
//

#ifndef CANVAS_1_0_STRING_H
#define CANVAS_1_0_STRING_H

#include <string>
#include "Container/Vector.h"

class String {
public:
	static void Replace(std::string& source, const std::string& str1, const std::string& str2);
    static Vector<std::string>* Split(std::string source, const std::string &flag);
};


#endif //CANVAS_1_0_STRING_H
