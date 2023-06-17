//
// Created by MisThe on 2023/5/21.
//

#include "../Include/Canvas.h"
#include "../Include/Core/Invoker/Graphic/Renderer.h"
#include "../Include/Core/Framework/GarbageCollection.h"
#include "../Include/Core/Asset/AssetManager.h"
#include "../Include/Core/Scene/SceneManager.h"
#include "../Include/Core/Framework/Static.h"
#include "../Include/Core/Framework/ReflectFactory.h"
#include "../Include/Core/Framework/ThreadPool.h"


bool Canvas::S_exist = true;
bool Canvas::S_notPause = true;

Canvas::Canvas() {
    GarbageCollection::GarbageCollectionConfig config{
            0
    };
    GarbageCollection::S_Config(config);
    ThreadPool::S_Config({});
    ReflectFactory::S_Initial();
    Static::S_Initial();
}

void Canvas::Invoke() {
//    Static::S_SceneManager()->Active()->ClearEntity();
//    Renderer* renderer = reinterpret_cast<Renderer *>((new Entity())->AddComponent("Renderer"));
//    renderer->mesh = Static::S_AssetManager()->Create<Mesh>("Canvas/Assets/Mesh/test.mesh");
//    renderer->material = Static::S_AssetManager()->Create<Material>("Canvas/Assets/Material/test.material");
//    renderer->material->shader = Static::S_AssetManager()->Create<Shader>("Canvas/Graphic/ShaderCache/Texture/texture.shader");
//    renderer->material->shader->vertexShaderPath = "Canvas/Graphic/ShaderCache/Texture/texture.vert";
//    renderer->material->shader->fragmentShaderPath = "Canvas/Graphic/ShaderCache/Texture/texture.frag";
    while (Canvas::S_exist) {
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
    }
}

Canvas::~Canvas() {
    GarbageCollection::S_Release();
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
