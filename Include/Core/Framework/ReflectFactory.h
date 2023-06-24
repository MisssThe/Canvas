//
// Created by MisThe on 2023/6/4.
// 只创建指针不记录指针，不参与垃圾回收
//

#ifndef CANVAS_1_0_REFLECTFACTORY_H
#define CANVAS_1_0_REFLECTFACTORY_H


#include "CustomPtr.h"
#include "../../General/Container/Map.h"
#include <string>

class ReflectFactory final
{
public:
    static void S_Initial();
    static CustomPtr* S_Instance(std::string_view type);
    static bool S_Register(std::string_view type, std::function<CustomPtr*()> func);
private:
    static Map<std::string_view,std::function<CustomPtr*()>> S_instances;
};

#endif //CANVAS_1_0_REFLECTFACTORY_H
