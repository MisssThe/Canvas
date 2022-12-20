//
// Created by ZLX on 2022/12/20.
//

#include "../Head/Tool/Debug.h"

#include <windows.h>
#include <iostream>

void Debug::Info(std::string context, std::string title) {
    title = title.empty() ? "Info" : title;
    context = context.empty() ? "invalid output." : context;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    std::cout << "[ " << title << " ]: " << context << std::endl;
}

void Debug::Warm(std::string context, std::string title) {
    title = title.empty() ? "Warm" : title;
    context = context.empty() ? "invalid output." : context;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    std::cout << "[ " << title << " ]: " << context << std::endl;
}

void Debug::Error(std::string context, std::string title) {
    title = title.empty() ? "Error" : title;
    context = context.empty() ? "invalid output." : context;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
    std::cout << "[ " << title << " ]: " << context << std::endl;
}
