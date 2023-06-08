//
// Created by MisThe on 2023/6/3.
//

#include "../Include/Core/Invoker/Graphic/GraphicData.h"

void GraphicData::CustomMark() {
    CustomPtr::S_Mark(this->renderers);
}

GraphicData::GraphicData() {
    this->renderers = new Queue<Renderer*>();
}
