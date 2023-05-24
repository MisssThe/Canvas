//
// Created by MisThe on 2023/5/11.
//

#ifndef ENGINE_DEBUG_H
#define ENGINE_DEBUG_H

#include <string>

class Debug {
public:
    static void Info(const std::string& title, const std::string& context);
    static void Warn(std::string title, std::string context);
    static void Error(std::string title, std::string context);
};


#endif //ENGINE_DEBUG_H
