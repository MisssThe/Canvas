//
// Created by MisThe on 2023/6/8.
//

#include "../Include/Core/Scene/Component/Renderer.h"
#include "../Include/General/Tool/Debug.h"
#include "../Include/Core/Framework/Static.h"


void Renderer::CustomMark() {
    CustomPtr::S_Mark(this->mesh);
    CustomPtr::S_Mark(this->material);
}

void Renderer::OnInitial() {
}

void Renderer::OnEnable() {
}

void Renderer::OnInvoke() {
}

void Renderer::OnDisable() {

}

void Renderer::OnDestroy() {

}

std::string_view Renderer::Type() {
    return "Renderer";
}

void Renderer::ComponentRead(cereal::BinaryInputArchive &archive) {
    std::string_view meshPath, materialPath;
    auto result = String::Read(archive, 2);
    meshPath = result->Pop();
    materialPath = result->Pop();
    this->mesh = Static::S_AssetManager()->Instance<Mesh>(meshPath);
    this->material = Static::S_AssetManager()->Instance<Material>(materialPath);
}

void Renderer::ComponentWrite(cereal::BinaryOutputArchive &archive) {
    std::string_view meshPath, materialPath;
    if (this->mesh != nullptr)
        meshPath = this->mesh->path;
    if (this->material != nullptr)
        materialPath = this->material->path;
    String::Write(archive, {meshPath, materialPath});
}

Queue<std::string_view> *Renderer::RequireComponent() {
    return nullptr;
}
