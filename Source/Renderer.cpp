//
// Created by MisThe on 2023/6/8.
//

#include "../Include/Core/Invoker/Graphic/Renderer.h"
#include "../Include/General/Debug.h"
#include "../Include/Core/Framework/Static.h"


void Renderer::CustomMark() {

}

void Renderer::Initial() {
    Debug::Info("Renderer", "Initial");
}

void Renderer::OnEnable() {
    Debug::Info("Renderer", "Enable");
}

void Renderer::Invoke() {
    Debug::Info("Renderer", "Invoke");
}

void Renderer::OnDisable() {

}

void Renderer::Destroy() {

}

std::string Renderer::Type() {
    return "Renderer";
}

void Renderer::ComponentRead(cereal::BinaryInputArchive &archive) {
    std::string meshPath, materialPath;
    if (this->mesh != nullptr)
        meshPath = this->mesh->path;
    if (this->material != nullptr)
        materialPath = this->material->path;
    archive(meshPath, materialPath);
}

void Renderer::ComponentWrite(cereal::BinaryOutputArchive &archive) {
    std::string meshPath, materialPath;
    archive(meshPath, materialPath);
    this->mesh = Static::S_AssetManager()->Instance<Mesh>(meshPath);
    this->material = Static::S_AssetManager()->Instance<Material>(materialPath);
}