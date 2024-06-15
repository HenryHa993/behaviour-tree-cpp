#pragma once
#include "../Node.h"

// This is a service node, so it should only ever return success.
// If it is off cooldown, it will change a boolean pointer value to true.
class CooldownNode :
    public Node
{
public:
    CooldownNode(bool* offCooldownOutput, float cooldown);
    NodeTask Evaluate(float deltaTime) override;

private:
    bool* IsOffCooldownOutput_;
    float cooldownInSeconds_;
    float currentCooldown_;
};

