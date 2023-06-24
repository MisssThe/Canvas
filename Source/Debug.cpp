//
// Created by MisThe on 2023/5/11.
//

#include <iostream>
#include "../Include/General/Performance/Time.h"
#include "../Include/General/Tool/Debug.h"

void Debug::Info(const std::string_view &title, std::initializer_list<std::string_view> context) {
    std::cout << "\033[32m[" <<
              Time::CanvasTimeWithStr() <<
              "] [" <<
              title <<
              "]: ";
    for (auto c : context) {
        std::cout << c;
    }
  std::cout << std::endl;
}

void Debug::Warn(const std::string_view title, std::initializer_list<std::string_view> context) {
    std::cout << "\033[33m[" <<
              Time::CanvasTimeWithStr() <<
              "] [" <<
              title <<
              "]: ";
    for (auto c : context) {
        std::cout << c;
    }
    std::cout << std::endl;
}

void Debug::Error(const std::string_view title, std::initializer_list<std::string_view> context) {
    std::cout << "\033[31m[" <<
              Time::CanvasTimeWithStr() <<
              "] [" <<
              title <<
              "]: ";
    for (auto c : context) {
        std::cout << c;
    }
    std::cout << std::endl;
}
