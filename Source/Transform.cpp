//
// Created by MisThe on 2023/5/28.
//

#include "../Include/Core/Scene/Entity/Transform.h"
#include "../Include/General/Debug.h"

void Transform::Initial() {

}

void Transform::OnEnable() {

}

void Transform::Invoke() {
    Debug::Info("Transform", "Start Invoke");
}

void Transform::OnDisable() {

}

void Transform::Destroy() {

}

std::string Transform::Type() {
    return "Transform";
}

void Transform::CustomMark() {

}

void Transform::ComponentRead(cereal::BinaryInputArchive &archive) {

}

void Transform::ComponentWrite(cereal::BinaryOutputArchive &archive) {

}