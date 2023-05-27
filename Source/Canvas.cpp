//
// Created by MisThe on 2023/5/21.
//

#include "../Include/Canvas.h"
#include "../Include/Core/GarbageCollection/GarbageCollection.h"
#include "../Include/Core/Asset/DefaultAsset.h"
#include "../Include/Core/GarbageCollection/ThreadPool.h"

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
    Canvas::InitGarbageCollection();
    Canvas::InitAsset();
    Canvas::InitThreadPool();
}

void Canvas::Invoke() {
    Scene* scene = Asset::S_Instance<Scene>("Canvas/Scene/editor.scene");
//    while (true) {
    //Canvas中提供线程操作以提高性能
    //Canvas在执行垃圾回收时需要挂起其他线程
    //合理利用render的同步时间
    GarbageCollection::S_Invoke();
//    }
}

Canvas::~Canvas() {
    Asset::S_Destroy();
}