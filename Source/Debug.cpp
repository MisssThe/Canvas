//
// Created by MisThe on 2023/5/11.
//

#include <iostream>
#include "../Include/General/Time.h"
#include "../Include/General/Debug.h"

void Debug::Info(const std::string& title, const std::string& context) {
    std::string outStr =  "\033[32m[" + Time::CanvasTimeWithStr() + "] " + "[" + title + "]: " + context;
    std::cout << outStr << std::endl;
}

void Debug::Warn(std::string title, std::string context) {
    std::string outStr = "\033[33m[" + Time::CanvasTimeWithStr() + "] " + "[" + title + "]: " + context;
    std::cout << outStr << std::endl;
}

void Debug::Error(std::string title, std::string context) {
    std::string outStr = "\033[31m[" + Time::CanvasTimeWithStr() + "] " + "[" + title + "]: " + context;
    std::cout << outStr << std::endl;}
