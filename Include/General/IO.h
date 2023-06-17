//
// Created by MisThe on 2023/5/17.
//

#ifndef CANVAS_IO_H
#define CANVAS_IO_H

#include <string>
#include "Container/Queue.h"

class IO {
private:
    IO() = delete;
    ~IO() = delete;
public:
    static std::string PathToName(const std::string& path);
    static std::string PathToExtension(const std::string& path);
    static bool Exist(const std::string& path);
    static bool ReadInfo(const std::string& path,std::string& info);
    static Queue<std::string>* ChildrenFiles(const std::string& path);
    static void CreateDirectory(const std::string& filePath);
private:
    static void GetChildrenFiles(const std::string& directory, Queue<std::string>* result);
};


#endif //CANVAS_IO_H
