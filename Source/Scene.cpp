//
// Created by MisThe on 2023/5/22.
//

#include "../Include/Core/Scene/Scene.h"
#include "../Include/General/String.h"
#include "../Include/Core/Asset/AssetManager.h"
#include "../Include/Core/Framework/Static.h"

Scene::Scene() {

}

void Scene::CustomMark() {
    CustomPtr::S_Mark(this->info);
}

//Entity* Scene::AddEntity(Entity* entity) {
//    Entity *go = new Entity();
//    go->SetParent(this->root);
//    go->name = name;
//    return go;
//}

void Scene::Load() {
    std::string infoPath = String::Replace(this->path, ".scene", "_info.scene_info");
    this->info = Static::S_AssetManager()->Create<SceneInfo>(infoPath);
}

void Scene::Unload() {
    Static::S_AssetManager()->Remove(this->info);
}

void Scene::ClearEntity() {
    this->info->root->children->IteratorWithout([](Entity* entity) {
        entity->Destroy();
    });
    this->info->root->children->Clear();
}

Entity *Scene::Root() {
    return this->info->root;
}

void Scene::Read(cereal::BinaryInputArchive &archive) {

}

void Scene::Write(cereal::BinaryOutputArchive &archive) {

}

