//
// Created by MisThe on 2023/5/22.
//

#include "../Include/Core/Scene/Scene.h"
#include <cereal/types/string.hpp>

Scene::Scene() {
    this->root = new Entity();
    this->root->name = "root";
}

Scene::~Scene() = default;

void Scene::CustomMark() {
    CustomPtr::S_Mark(this->root);
}

void Scene::Read(cereal::BinaryInputArchive &archive) {
//    archive(*this->root);
}

void Scene::Write(cereal::BinaryOutputArchive &archive) {
//    archive(*this->root);
}

Entity* Scene::AddEntity() {
    Entity *go = new Entity();
    go->SetParent(this->root);
    return go;
}

void Scene::Load() {
//    if (Scene::scenes == nullptr)
//        Scene::scenes = new CustomQueue<Scene*>();
//    Scene::scenes->Push(this);
}

void Scene::Unload() {
//    if (Scene::scenes == nullptr)
//        return;
//    Scene::scenes->Remove(this);
}