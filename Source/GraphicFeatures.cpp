//
// Created by MisThe on 2023/6/4.
//

#include "../Include/Core/Invoker/Graphic/Feature/GraphicFeatures.h"

void GraphicFeatures::Register(Feature *feature) {
    if (feature == nullptr)
        return;
    GraphicFeatures::features->Push(feature);
}

void GraphicFeatures::Invoke(GraphicData *data) {
    GraphicFeatures::features->IteratorWithout([&data](Feature* feature) {
        feature->Prepare(data);
    });
    GraphicFeatures::features->IteratorWithout([&data](Feature* feature) {
        feature->Invoke(data);
    });
}
void GraphicFeatures::CustomMark() {
    CustomPtr::S_Mark(GraphicFeatures::features);
}

void GraphicFeatures::Read(cereal::BinaryInputArchive &archive) {
    int size;
    archive(size);
    for (int index = 0; index < size; ++index) {
//        this->features->Push()
    }
}

void GraphicFeatures::Write(cereal::BinaryOutputArchive &archive) {
    archive(this->features->Size());
    this->features->IteratorWithout([&archive](Feature* feature) {
        archive(*feature);
    });
}

GraphicFeatures::GraphicFeatures() {
    GraphicFeatures::features = new Queue<Feature*>();
}
