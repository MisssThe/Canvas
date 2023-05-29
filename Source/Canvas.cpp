//
// Created by MisThe on 2023/5/21.
//

#include "../Include/Canvas.h"
#include "../Include/Core/GarbageCollection/GarbageCollection.h"
#include "../Include/Core/GarbageCollection/ThreadPool.h"
#include "../Include/Core/Scene/Entity/Transform.h"

//初始化GC
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
    Asset::AssetConfig config {

    };
    Asset::S_Config(config);
}

Canvas::Canvas() {
    this->InitGarbageCollection();
    this->InitAsset();
    this->InitThreadPool();
}

void Canvas::Invoke() {
    Scene* scene = Asset::S_Instance<Scene>("Canvas/Scene/editor.scene");
    scene->Load();
    scene->AddEntity();
    scene->AddEntity();
    scene->AddEntity();
    scene->AddEntity();
    scene->AddEntity();
    scene->AddEntity();
//    ComponentInstance::S_Instance<Transform>();
//    ComponentInstance::S_Instance<Transform>();
//    ComponentInstance::S_Instance<Transform>();
//    ComponentInstance::S_Instance<Transform>();
//    ComponentInstance::S_Instance<Transform>();
//    ComponentInstance::S_Instance<Transform>();
//    while (true) {
    //Canvas中提供线程操作以提高性能
    //Canvas在执行垃圾回收时需要挂起其他线程
    //合理利用render的同步时间
    SceneInvoker::S_Instance()->Invoke();
    Asset::S_Invoke();
    GarbageCollection::S_Invoke();
//    }
}

Canvas::~Canvas() {
    Asset::S_Destroy();
}