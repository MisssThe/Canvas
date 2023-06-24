//
// Created by MisThe on 2023/6/25.
//

#include "../Include/Core/Scene/Component/Camera.h"

void Camera::OnInitial() {

}

void Camera::OnEnable() {

}

void Camera::OnInvoke() {

}

void Camera::OnDisable() {

}

void Camera::OnDestroy() {

}

std::string_view Camera::Type() {
    return "Camera";
}

void Camera::CustomMark() {

}

void Camera::ComponentRead(cereal::BinaryInputArchive &archive) {

}

void Camera::ComponentWrite(cereal::BinaryOutputArchive &archive) {

}

Queue<std::string_view> *Camera::RequireComponent() {
    return new Queue<std::string_view>{
        "Transform"
    };
}
