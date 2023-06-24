//
// Created by MisThe on 2023/5/17.
//

#include "../Include/General/Tool/IO.h"
#include "../Include/General/Tool/String.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <queue>

std::string_view IO::PathToName(const std::string_view& path) {
    unsigned long begin = path.find_last_of('/') + 1;
    begin = begin == std::string_view::npos ? 0 : begin;
    unsigned long end = path.find_last_of('.');
    end = end == std::string_view::npos ? path.length() : end;
    return path.substr(begin, end - begin);
}

bool IO::Exist(const std::string_view& path) {
    std::ifstream is(path);
    bool result = is.is_open();
    is.close();
    return result;
}

bool IO::ReadInfo(const std::string_view& path, std::string_view& info) {
    std::ifstream is(path);
    bool success = false;
    if (is.is_open())
    {
        success = true;
        std::stringstream ss;
        ss << is.rdbuf();
        std::string temp = ss.str();
        String::Convert(temp, info);
    }
    is.close();
    return success;
}

void IO::CreateDirectory(const std::string_view& filePath) {
//    std::string_view delimiter = "/";
//    size_t pos = filePath.find(delimiter);
//    if (pos == std::string_view::npos || filePath.substr(0, pos) != "Canvas") {
//        throw std::runtime_error("一级目录必须是 'Canvas'");
//    }
//
//    std::string_view directoryPath;
//    std::string pathCopy = filePath;  // 创建一个副本
//    std::string_view token;
//    while ((pos = pathCopy.find(delimiter)) != std::string_view::npos) {
//        token = pathCopy.substr(0, pos);
//        directoryPath += token + delimiter;
//        pathCopy.erase(0, pos + delimiter.length());
//
//        // 忽略第一级目录
//        if (directoryPath != "Canvas/") {
//            if (!std::filesystem::exists(directoryPath)) {
//                std::filesystem::create_directory(directoryPath);
//            }
//        }
//    }
}

void IO::GetChildrenFiles(const std::string_view& directory, Queue<std::string_view>* result) {
    if (result == nullptr)
        return;
    std::filesystem::path str(directory);
    std::filesystem::directory_entry entry(str);
    if (entry.status().type() != std::filesystem::file_type::directory) {
        std::string ss(entry.path().string());
        std::string_view sv;
        String::Convert(ss, sv);
        result->Push(sv);
        return;
    }
    std::filesystem::directory_iterator children(str);
    for (auto &child: children) {
        std::string ss(entry.path().string());
        std::string_view sv;
        String::Convert(ss, sv);
        IO::GetChildrenFiles(child.path().string(), result);
    }
}

Queue<std::string_view>* IO::ChildrenFiles(const std::string_view& directory) {
    auto* result = new Queue<std::string_view>();
    if (!IO::Exist(directory))
        return result;
    IO::GetChildrenFiles(directory, result);
    return result;
}

std::string_view IO::PathToExtension(const std::string_view& path) {
    unsigned long begin = path.find_last_of('.') + 1;
    begin = begin == std::string::npos ? 0 : begin;
    return path.substr(begin, path.length() - begin);
}
