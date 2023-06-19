//
// Created by MisThe on 2023/5/17.
//

#include "../Include/General/IO.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <queue>

std::string IO::PathToName(const std::string& path) {
    unsigned long begin = path.find_last_of('/') + 1;
    begin = begin == std::string::npos ? 0 : begin;
    unsigned long end = path.find_last_of('.');
    end = end == std::string::npos ? path.length() : end;
    return path.substr(begin, end - begin);
}

bool IO::Exist(const std::string& path) {
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

void IO::CreateDirectory(const std::string& filePath) {
    std::string delimiter = "/";
    size_t pos = filePath.find(delimiter);
    if (pos == std::string::npos || filePath.substr(0, pos) != "Canvas") {
        throw std::runtime_error("一级目录必须是 'Canvas'");
    }

    std::string directoryPath;
    std::string pathCopy = filePath;  // 创建一个副本
    std::string token;
    while ((pos = pathCopy.find(delimiter)) != std::string::npos) {
        token = pathCopy.substr(0, pos);
        directoryPath += token + delimiter;
        pathCopy.erase(0, pos + delimiter.length());

        // 忽略第一级目录
        if (directoryPath != "Canvas/") {
            if (!std::filesystem::exists(directoryPath)) {
                std::filesystem::create_directory(directoryPath);
            }
        }
    }
}

void IO::GetChildrenFiles(const std::string& directory, Queue<std::string>* result) {
    if (result == nullptr)
        return;
    std::filesystem::path str(directory);
    std::filesystem::directory_entry entry(str);
    if (entry.status().type() != std::filesystem::file_type::directory) {
        result->Push(entry.path().string());
        return;
    }
    std::filesystem::directory_iterator children(str);
    for (auto &child: children) {
        IO::GetChildrenFiles(child.path().string(), result);
    }
}

Queue<std::string>* IO::ChildrenFiles(const std::string& directory) {
    auto* result = new Queue<std::string>();
    if (!IO::Exist(directory))
        return result;
    IO::GetChildrenFiles(directory, result);
    return result;
}

std::string IO::PathToExtension(const std::string &path) {
    unsigned long begin = path.find_last_of('.') + 1;
    begin = begin == std::string::npos ? 0 : begin;
    return path.substr(begin, path.length() - begin);
}
