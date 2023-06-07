//
// Created by MisThe on 2023/6/8.
//

#include "../Include/Core/Invoker/Graphic/Renderer.h"
#include "../Include/General/Debug.h"


void Renderer::CustomMark() {

}

void Renderer::Initial() {
    Debug::Info("Renderer", "Initial");
}

void Renderer::OnEnable() {
    Debug::Info("Renderer", "Enable");
}

void Renderer::Invoke() {
    Debug::Info("Renderer", "Invoke");
}

void Renderer::OnDisable() {

}

void Renderer::Destroy() {

}

std::string Renderer::Type() {
    return "Renderer";
}

void Renderer::ComponentRead(cereal::BinaryInputArchive &archive) {

}

void Renderer::ComponentWrite(cereal::BinaryOutputArchive &archive) {

}
