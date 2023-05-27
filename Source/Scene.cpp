//
// Created by MisThe on 2023/5/22.
//

#include "../Include/Core/Scene/Scene.h"
#include <cereal/types/string.hpp>

Scene::~Scene() {

}

void Scene::CustomMark() {
//    this->root->Mark();
}

void Scene::Construct() {
    this->root = new Entity();
    this->root->name = "root";
}

void Scene::Read(cereal::BinaryInputArchive &archive) {
    this->root = new Entity();
    archive(*this->root);
}

void Scene::Write(cereal::BinaryOutputArchive &archive) {
//    archive(*this->root);
}