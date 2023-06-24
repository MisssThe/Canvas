//
// Created by MisThe on 2023/6/20.
//

#ifndef CANVAS_1_0_CUSTOMJSON_H
#define CANVAS_1_0_CUSTOMJSON_H


#include "../Framework/CustomPtr.h"
#include "json/value.h"

class CustomJson : public CustomPtr {
public:
    explicit CustomJson(const std::string_view & path);
    void Iterator(const std::function<void(std::string_view &,Json::Value&)>& call);
private:
    void PrivateIterator(const std::function<void(std::string_view &, Json::Value&)>& call, const Json::Value& value);
protected:
    void CustomMark() override;
    ~CustomJson() override = default;
private:
    Json::Value root;
};


#endif //CANVAS_1_0_CUSTOMJSON_H
