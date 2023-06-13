//
// Created by MisThe on 2023/5/17.
//

#ifndef CANVAS_IO_H
#define CANVAS_IO_H

#include <string>

class IO {
private:
    IO() = delete;
    ~IO() = delete;
public:
    //根据路径获取文件名
    static std::string PathToName(const std::string& path);
    static bool Exist(std::string path);
    static bool ReadInfo(const std::string& path,std::string& info);
};


#endif //CANVAS_IO_H
