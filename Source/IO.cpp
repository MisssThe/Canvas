//
// Created by MisThe on 2023/5/17.
//

#include "../Include/General/IO.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>
#include <queue>

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
void createDirectory(const std::string& filePath) {
    std::string delimiter = "/";
    size_t pos = filePath.find(delimiter);
    if (pos == std::string::npos || filePath.substr(0, pos) != "Canvas") {
        throw std::runtime_error("一级目录必须是 'Canvas'");
    }

    std::string directoryPath = "";
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

std::queue<std::string> ChildrenFile(const std::string& path) {
    std::queue<std::string> filesQueue;

    // Check if the given path is valid
    if (!std::filesystem::exists(path)) {
        throw std::invalid_argument("Invalid file path.");
    }

    // Check if the given path is a regular file
    if (std::filesystem::is_regular_file(path)) {
        // Read the file and store its contents in the queue
        std::ifstream file(path);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                filesQueue.push(line);
            }
            file.close();
        } else {
            throw std::runtime_error("Failed to open file: " + path);
        }
    }
        // Check if the given path is a directory
    else if (std::filesystem::is_directory(path)) {
        // Traverse the directory and its subdirectories
        for (const auto& entry : std::filesystem::recursive_directory_iterator(path)) {
            if (std::filesystem::is_regular_file(entry.path())) {
                // Read the file and store its contents in the queue
                std::ifstream file(entry.path());
                if (file.is_open()) {
                    std::string line;
                    while (std::getline(file, line)) {
                        filesQueue.push(line);
                    }
                    file.close();
                } else {
                    throw std::runtime_error("Failed to open file: " + entry.path().string());
                }
            }
        }
    }
        // Invalid value
    else {
        throw std::invalid_argument("Invalid file or directory path.");
    }

    return filesQueue;
}

