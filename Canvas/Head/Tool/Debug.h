//
// Created by ZLX on 2022/12/20.
//

#ifndef CANVAS_DEBUG_H
#define CANVAS_DEBUG_H

#include <string>

class Debug {
public:
    static void Info( std::string context = "", std::string title = "");
    static void Warm( std::string context = "", std::string title = "");
    static void Error( std::string context = "", std::string title = "");
};


#endif //CANVAS_DEBUG_H
