//
// Created by MisThe on 2023/6/25.
//

#ifndef CANVAS_1_0_CAMERA_H
#define CANVAS_1_0_CAMERA_H


#include "../../Invoker/Component/Component.h"

class Camera : public Component {
public:
    void OnInitial() override;
    void OnEnable() override;
    void OnInvoke() override;
    void OnDisable() override;
    void OnDestroy() override;
public:
    std::string_view Type() override;

    Queue<std::string_view> *RequireComponent() override;

protected:
    void CustomMark() override;
    ~Camera() override = default;
    void ComponentRead(cereal::BinaryInputArchive &archive) override;
    void ComponentWrite(cereal::BinaryOutputArchive &archive) override;
};


#endif //CANVAS_1_0_CAMERA_H
