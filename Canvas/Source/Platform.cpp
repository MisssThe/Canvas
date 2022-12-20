//
// Created by ZLX on 2022/12/19.
//

#include "../Head/Core/Platform/Platform.h"

void Platform::Start() {
    #ifdef _WIN32
        #define ANDROID
    #elif __linux__
        #define LINUX
    #elif __APPLE__
        #define IOS
    #endif
}

void Platform::Stop() {
    #undef ANDROID
    #undef LINUX
    #undef IOS
}
