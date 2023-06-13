//
// Created by MisThe on 2023/6/4.
//

#ifndef CANVAS_1_0_MESH_H
#define CANVAS_1_0_MESH_H


#include "../../../Asset/Asset.h"
#include "../../../../General/Container/Vector.h"

class Mesh : public Asset
{
protected:
    void Read(cereal::BinaryInputArchive &archive) override;
    void Write(cereal::BinaryOutputArchive &archive) override;
    void CustomMark() override;
    ~Mesh() override = default;
public:
    Vector<float>* vertices;
    Vector<unsigned int>* indices;
    Vector<int>* normals;
//    Vector<int> normals;
public:
};


#endif //CANVAS_1_0_MESH_H
