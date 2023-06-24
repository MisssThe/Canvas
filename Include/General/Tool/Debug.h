//
// Created by MisThe on 2023/5/11.
//

#ifndef ENGINE_DEBUG_H
#define ENGINE_DEBUG_H

#include <string_view>

class Debug {
public:
    static void Info(const std::string_view &title, std::initializer_list<std::string_view> context);
    static void Warn(const std::string_view title, std::initializer_list<std::string_view> context);
    static void Error(const std::string_view title, std::initializer_list<std::string_view> context);
};


#endif //ENGINE_DEBUG_H
