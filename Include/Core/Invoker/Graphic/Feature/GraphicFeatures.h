//
// Created by MisThe on 2023/6/4.
//

#ifndef CANVAS_1_0_GRAPHICFEATURES_H
#define CANVAS_1_0_GRAPHICFEATURES_H


#include "Feature.h"
#include "../../../../General/Container/Queue.h"
#include "../GraphicData.h"
#include "../../../Asset/Asset.h"

class GraphicFeatures final : public Asset
{
public:
protected:
    void Read(cereal::BinaryInputArchive &archive) override;
    void Write(cereal::BinaryOutputArchive &archive) override;
    ~GraphicFeatures() override = default;
public:
    GraphicFeatures();
    void Register(Feature* feature);
    void Invoke(GraphicData* data);
protected:
    void CustomMark() override;
private:
    Queue<Feature*>* features;
};


#endif //CANVAS_1_0_GRAPHICFEATURES_H
