//
// Created by MisThe on 2023/5/28.
//

#include "../Include/Core/Invoker/Invoker.h"
#include "../Include/Core/GarbageCollection/GarbageCollection.h"

Invoker* Invoker::S_instance = nullptr;
bool Invoker::S_notPause = true;

void Invoker::CustomMark() {
    CustomPtr::S_Mark(this->components);
    CustomPtr::S_Mark(this->psycho);
    CustomPtr::S_Mark(this->graphic);
}

Invoker::~Invoker() = default;

Invoker *Invoker::S_Instance() {
    if (Invoker::S_instance == nullptr) {
        Invoker::S_instance = new Invoker();
    }
    return Invoker::S_instance;
}

Invoker::Invoker() {
    this->components = new Components();
    this->psycho = new Psycho();
    this->graphic = new Graphic();
    GarbageCollection::S_AddRoot(this);
}

void Invoker::Invoke() const {
    if (Invoker::S_notPause) {
        this->components->Invoke();
    }
    this->psycho->Invoke();
    this->graphic->Invoke();
}

void Invoker::S_Pause() {
    Invoker::S_notPause = false;
}

void Invoker::S_Resume() {
    Invoker::S_notPause = true;
}
