//
// Created by MisThe on 2023/6/4.
//

#include "../Include/Core/Invoker/Graphic/Elements/Mesh.h"

void Mesh::Read(cereal::BinaryInputArchive &archive) {
    int size = -1;
    float fValue;
    unsigned int uiValue;
    archive(size);
    if (size >= 0) {
        this->vertices = new Vector<float>();
        for (int index = 0; index < size; ++index) {
            archive(fValue);
            this->vertices->Add(fValue);
        }
    }
    archive(size);
    if (size >= 0) {
        this->indices = new Vector<unsigned int>();
        for (int index = 0; index < size; ++index) {
            archive(uiValue);
            this->indices->Add(uiValue);
        }
    }
}

void Mesh::Write(cereal::BinaryOutputArchive &archive) {
    if (this->vertices != nullptr) {
        archive(this->vertices->Size());
        for (int index = 0; index < this->vertices->Size(); ++index) {
            archive(this->vertices->Get(index));
        }
    } else {
        archive(-1);
    }
    if (this->indices != nullptr) {
        archive(this->indices->Size());
        for (int index = 0; index < this->indices->Size(); ++index) {
            archive(this->indices->Get(index));
        }
    } else {
        archive(-1);
    }
}

void Mesh::CustomMark() {
    CustomPtr::S_Mark(this->vertices);
    CustomPtr::S_Mark(this->indices);
}
