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
    void Cache(std::string file) override;
    int Size() const;
private:
    void LoadMesh(const std::string& file);
    void LoadMeshNode();
public:
    Vector<unsigned int>* indices;
    Vector<float>* vertices;
    Vector<float>* normals;
    Vector<float>* tangents;
    Vector<float>* colors;
    Vector<float>* uv0s;
    Vector<float>* uv1s;
    Vector<float>* uv2s;
};


#endif //CANVAS_1_0_MESH_H
