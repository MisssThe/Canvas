//
// Created by MisThe on 2023/6/20.
//

#include "../Include/Core/Asset/CustomJson.h"
#include "../Include/General/Tool/Debug.h"
#include "../Include/General/Tool/IO.h"
#include "../Include/General/Tool/String.h"
#include <fstream>
#include <string>
#include <json/json.h>


void CustomJson::CustomMark() {

}

CustomJson::CustomJson(const std::string_view & path) {
    Json::Reader reader;
    std::string_view info;
    IO::ReadInfo(path, info);
    if (!reader.parse(info.data(), this->root)) {
        Debug::Warn("Custom Json", {"Read Failed [", path, "]"});
    }
}

void CustomJson::Iterator(const std::function<void(std::string_view &, Json::Value &)>& call) {
    Json::Value value = this->root;
    this->PrivateIterator(call, root);
}

void CustomJson::PrivateIterator(const std::function<void(std::string_view &, Json::Value &)>& call,const Json::Value& value) {
    for (auto info: value.getMemberNames()) {
        Json::Value temp = value[info];
        if (temp.isObject()) {
            this->PrivateIterator(call, temp);
        }
        else {
            std::string_view sv;
            String::Convert(info,sv);
            call(sv, temp);
        }
    }
}
