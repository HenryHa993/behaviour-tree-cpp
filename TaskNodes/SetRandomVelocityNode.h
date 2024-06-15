#pragma once
#include "../Node.h"
#include <DirectXMath.h>

// Set random velocity with given ranges
class SetRandomVelocityNode :
    public Node
{
public:
    SetRandomVelocityNode(DirectX::XMFLOAT3* velocityOutput, float minRange, float maxRange);
    NodeTask Evaluate(float deltaTime) override;

private:
    DirectX::XMFLOAT3* velocityOutput_;
    float maxRange_;
    float minRange_;
};

