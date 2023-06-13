//
// Created by MisThe on 2023/6/13.
//

#ifndef CANVAS_1_0_VECTORSERIALIZE_H
#define CANVAS_1_0_VECTORSERIALIZE_H

#include <cereal/archives/binary.hpp>
#include "../Vector.h"

class VectorSerialize {
public:
    template<class T> static void Read(cereal::BinaryInputArchive& archive, Vector<T>* vector) {
        if (vector == nullptr)
            return;
        int size = -1;
        T value;
        archive(size);
        if (size >= 0) {
            for (int index = 0; index < size; ++index) {
                archive(value);
                vector->Add(value);
            }
        }
    }
    template<class T> static Vector<T>* Read(cereal::BinaryInputArchive& archive) {
        int size = -1;
        T value;
        archive(size);
        Vector<T>* vector = nullptr;
        if (size >= 0) {
            vector = new Vector<T>();
            for (int index = 0; index < size; ++index) {
                archive(value);
                vector->Add(value);
            }
        }
        return vector;
    }
    template<class T> static void Write(cereal::BinaryOutputArchive& archive, Vector<T>* vector) {
        if (vector != nullptr) {
            archive(vector->Size());
            for (int index = 0; index < vector->Size(); ++index) {
                archive(vector->Get(index));
            }
        } else {
            archive(-1);
        }
    }
};


#endif //CANVAS_1_0_VECTORSERIALIZE_H
