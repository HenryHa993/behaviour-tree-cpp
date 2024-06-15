#pragma once
#include "../Node.h"
// Wait for given amount of seconds
class WaitNode :
    public Node
{
public:
    WaitNode(float waitTime);
    NodeTask Evaluate(float deltaTime) override;

private:
    float waitTime_;
};

