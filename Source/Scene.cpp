//
// Created by MisThe on 2023/5/22.
//

#include "../Include/Core/Scene/Scene.h"
#include <cereal/types/string.hpp>

Scene::Scene() {
    this->root = new Entity();
    this->root->name = "root";
}

void Scene::CustomMark() {
    CustomPtr::S_Mark(this->root);
}

void Scene::Read(cereal::BinaryInputArchive &archive) {
    archive(*this->root);
}

void Scene::Write(cereal::BinaryOutputArchive &archive) {
    archive(*this->root);
}

//Entity* Scene::AddEntity(Entity* entity) {
//    Entity *go = new Entity();
//    go->SetParent(this->root);
//    go->name = name;
//    return go;
//}

void Scene::Load() {

}

void Scene::Unload() {

}

void Scene::ClearEntity() {
    this->root->children->IteratorWithout([](Entity* entity) {
        entity->Destroy();
    });
}

Entity *Scene::Root() {
    return this->root;
}
