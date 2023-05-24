//
// Created by MisThe on 2023/5/21.
//

#include "../Include/Canvas.h"
#include "../Include/Core/GarbageCollection/GarbageCollection.h"
#include "../Include/Core/Asset/DefaultAsset.h"

//初始化GC
void Canvas::InitGarbageCollection() {
    GarbageCollection::GarbageCollectionConfig config{
        10
    };
    GarbageCollection::_Config(config);
    GarbageCollection::AddRoot(Asset::S_Instance<DefaultAsset>("Canvas/default"));
}

Canvas::Canvas() {
    Canvas::InitGarbageCollection();
}

void Canvas::Invoke() {
//    while (true) {
    //Canvas中提供线程操作以提高性能
    //Canvas在执行垃圾回收时需要挂起其他线程
    //合理利用render的同步时间
    GarbageCollection::_Invoke();
//    }
}

Canvas::~Canvas() {

}
