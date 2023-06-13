//
// Created by MisThe on 2023/5/17.
//

#include "../Include/General/IO.h"
#include <fstream>
#include <sstream>

std::string IO::PathToName(const std::string& path) {
    int begin = path.find_last_of('/') + 1;
    begin = begin == std::string::npos ? 0 : begin;
    int end = path.find_last_of('.');
    end = end == std::string::npos ? path.length() : end;
    return path.substr(begin, end - begin);
}

bool IO::Exist(std::string path) {
    std::ifstream is(path);
    bool result = is.is_open();
    is.close();
    return result;
}

bool IO::ReadInfo(const std::string& path, std::string& info) {
    std::ifstream is(path);
    bool success = false;
    if (is.is_open())
    {
        success = true;
        std::stringstream ss;
        ss << is.rdbuf();
        info = ss.str();
    }
    is.close();
    return success;
}
