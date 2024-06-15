#pragma once
#include "../Node.h"
// Set a blackboard float pointer value
class SetFloatNode :
    public Node
{
public:
    SetFloatNode(float* targetFloat, float newFloat);
    NodeTask Evaluate(float deltaTime) override;

private:
    float* targetFloat_;
    float newFloat_;
};

