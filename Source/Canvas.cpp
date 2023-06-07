//
// Created by MisThe on 2023/5/21.
//

#include "../Include/Canvas.h"
#include "../Include/Core/Framework/GarbageCollection.h"
#include "../Include/Core/Framework/ThreadPool.h"
#include "../Include/Core/Asset/AssetManager.h"
#include "../Include/Core/Scene/SceneManager.h"
#include "../Include/Core/Framework/Static.h"
#include "../Include/Core/Scene/Entity/Transform.h"
#include "../Include/Core/Framework/ReflectFactory.h"

bool Canvas::S_exist = true;
bool Canvas::S_notPause = true;

Canvas::Canvas() {
    GarbageCollection::GarbageCollectionConfig config{
            0
    };
    GarbageCollection::S_Config(config);
    ReflectFactory::S_Initial();
    Static::S_Initial();
}

void Canvas::Invoke() {
//    Static::S_SceneManager()->Editor()->AddEntity("test")->AddComponent("Renderer");
//    while (Canvas::S_exist) {
        //Canvas中提供线程操作以提高性能
        if (Canvas::S_notPause) {
            Static::S_Components()->Invoke();
        }
        Static::S_Psycho()->Invoke();
        Static::S_Graphic()->Invoke();
        Static::S_AssetManager()->Invoke();
        //Canvas在执行垃圾回收时需要挂起其他线程
        //合理利用render的同步时间
        GarbageCollection::S_Invoke();
//    }
}

Canvas::~Canvas() {
    Static::S_AssetManager()->Clear();
}

void Canvas::S_Quit() {
    Canvas::S_exist = false;
}

void Canvas::S_Pause() {
    Canvas::S_notPause = false;
}

void Canvas::S_Resume() {
    Canvas::S_notPause = true;
}
