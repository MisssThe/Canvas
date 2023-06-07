//
// Created by MisThe on 2023/6/4.
//

#include "../Include/Core/Invoker/Graphic/Core/GraphicCore.h"
#include "../Include/Core/Framework/Static.h"

void GraphicCore::DrawScreen(Material *material) {
    this->DrawRender(Static::S_AssetManager()->Instance<Mesh>(""), material);
}
