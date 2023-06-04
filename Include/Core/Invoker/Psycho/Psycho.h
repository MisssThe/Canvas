//
// Created by MisThe on 2023/5/28.
//

#ifndef CANVAS_1_0_PSYCHO_H
#define CANVAS_1_0_PSYCHO_H


#include "../../Framework/CustomPtr.h"

class Psycho final : public CustomPtr
{
public:
    void Invoke();

protected:
    void CustomMark() override;
    ~Psycho() override = default;
};


#endif //CANVAS_1_0_PSYCHO_H
