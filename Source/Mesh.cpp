//
// Created by MisThe on 2023/6/4.
//

#include "../Include/Core/Invoker/Graphic/Elements/Mesh.h"
#include "../Include/General/Container/ContainSerialize/VectorSerialize.h"

void Mesh::Read(cereal::BinaryInputArchive &archive) {
    this->indices = VectorSerialize::Read<unsigned int>(archive);
    this->vertices = VectorSerialize::Read<float>(archive);
    this->normals = VectorSerialize::Read<float>(archive);
    this->tangents = VectorSerialize::Read<float>(archive);
    this->colors = VectorSerialize::Read<float>(archive);
    this->uv0s = VectorSerialize::Read<float>(archive);
    this->uv1s = VectorSerialize::Read<float>(archive);
    this->uv2s = VectorSerialize::Read<float>(archive);
}

void Mesh::Write(cereal::BinaryOutputArchive &archive) {
    VectorSerialize::Write(archive, this->indices);
    VectorSerialize::Write(archive, this->vertices);
    VectorSerialize::Write(archive, this->normals);
    VectorSerialize::Write(archive, this->tangents);
    VectorSerialize::Write(archive, this->colors);
    VectorSerialize::Write(archive, this->uv0s);
    VectorSerialize::Write(archive, this->uv1s);
    VectorSerialize::Write(archive, this->uv2s);
}

void Mesh::CustomMark() {
    CustomPtr::S_Mark(this->vertices);
    CustomPtr::S_Mark(this->indices);
}

int Mesh::Size() {
    int size = 0;
    if (this->vertices)
        size += this->vertices->MemorySize();
    if (this->normals)
        size += this->normals->MemorySize();
    if (this->tangents)
        size += this->tangents->MemorySize();
    if (this->colors)
        size += this->colors->MemorySize();
    if (this->uv0s)
        size += this->uv0s->MemorySize();
    if (this->uv1s)
        size += this->uv1s->MemorySize();
    if (this->uv2s)
        size += this->uv2s->MemorySize();
    return size;
}
