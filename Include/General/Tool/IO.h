//
// Created by MisThe on 2023/5/17.
//

#ifndef CANVAS_IO_H
#define CANVAS_IO_H

#include <string>
#include "../Container/Queue.h"

class IO {
private:
    IO() = delete;
    ~IO() = delete;
public:
    static std::string_view PathToName(const std::string_view& path);
    static std::string_view PathToExtension(const std::string_view& path);
    static bool Exist(const std::string_view& path);
    static bool ReadInfo(const std::string_view& path,std::string_view& info);
    static Queue<std::string_view>* ChildrenFiles(const std::string_view& path);
    static void CreateDirectory(const std::string_view& filePath);
private:
    static void GetChildrenFiles(const std::string_view& directory, Queue<std::string_view>* result);
};


#endif //CANVAS_IO_H
