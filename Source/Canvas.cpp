//
// Created by MisThe on 2023/5/21.
//

#include "../Include/Canvas.h"
#include "../Include/Core/GarbageCollection/GarbageCollection.h"
#include "../Include/Core/GarbageCollection/ThreadPool.h"
#include "../Include/Core/Scene/Entity/Transform.h"
#include "../Include/Core/Asset/AssetManager.h"
#include "../Include/Core/Scene/SceneManager.h"

bool Canvas::S_exist = true;

void Canvas::InitGarbageCollection() {
    GarbageCollection::GarbageCollectionConfig config{
        0
    };
    GarbageCollection::S_Config(config);
}

void Canvas::InitThreadPool() {
    ThreadPool::ThreadPoolConfig config {
        20
    };
    ThreadPool::S_Config(config);
}

void Canvas::InitAsset() {
    AssetManager::AssetConfig config {

    };
    AssetManager::S_Config(config);
}

void Canvas::InitScene() {
    SceneManager::SceneManagerConfig config{
            "Canvas/Scene/editor.scene"
    };
    SceneManager::S_Config(config);
}

Canvas::Canvas() {
    this->InitGarbageCollection();
    this->InitAsset();
    this->InitThreadPool();
    this->InitScene();
}

void Canvas::Invoke() {
    while (Canvas::S_exist) {
        //Canvas中提供线程操作以提高性能
        //Canvas在执行垃圾回收时需要挂起其他线程
        //合理利用render的同步时间
        Invoker::S_Instance()->Invoke();
        AssetManager::S_Invoke();
        GarbageCollection::S_Invoke();
    }
}

Canvas::~Canvas() {
    AssetManager::S_Release();
}

void Canvas::S_Quit() {
    Canvas::S_exist = false;
}
