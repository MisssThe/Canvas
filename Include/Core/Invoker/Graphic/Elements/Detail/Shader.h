//
// Created by MisThe on 2023/6/5.
//

#ifndef CANVAS_1_0_SHADER_H
#define CANVAS_1_0_SHADER_H


#include "../../../../../General/Container/Queue.h"
#include "../../../../Asset/Asset.h"
#include <string>

class Shader : public Asset {
public:
    enum ShaderInfoType {
        Float, Bool,
        Vec, Vec2, Vec3, Vec4,
        Matrix2x2, Matrix3x3, Matrix4x4,
        Texture2D, Texture3D, TextureCube
    };
    struct ShaderInfo {
        const char* name;
        ShaderInfoType type;
    };
public:
    Queue<ShaderInfo> property;
    std::string vertexShaderPath;
    std::string fragmentShaderPath;
protected:
    void Read(cereal::BinaryInputArchive &archive) override;
    void Write(cereal::BinaryOutputArchive &archive) override;
    void CustomMark() override;
    ~Shader() override = default;
};


#endif //CANVAS_1_0_SHADER_H
