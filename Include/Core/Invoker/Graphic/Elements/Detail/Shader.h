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
        Float, Vector, Texture
    };
    struct ShaderInfo {
        std::string_view name;
        ShaderInfoType type;
    };
public:
    void Cache(std::string_view file) override;
    Shader();
public:
    Queue<ShaderInfo>* shaderInfo;
    std::string_view vertexShaderCode;
    std::string_view fragmentShaderCode;
protected:
    void Read(cereal::BinaryInputArchive &archive) override;
    void Write(cereal::BinaryOutputArchive &archive) override;
    void CustomMark() override;
    ~Shader() override = default;
private:
    void CompressShaderProperty(std::string_view & propertyPath);
};


#endif //CANVAS_1_0_SHADER_H
