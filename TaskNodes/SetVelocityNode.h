#pragma once
#include "../Node.h"
#include <DirectXMath.h>

// Just set a given velocity to something else.
// Mainly used to reset velocity for specific attacks.
class SetVelocityNode :
    public Node
{
public:
    SetVelocityNode(DirectX::XMFLOAT3* velocityOutput, DirectX::XMFLOAT3 velocityInput);
    NodeTask Evaluate(float deltaTime) override;

private:
    DirectX::XMFLOAT3 velocityInput_;
    DirectX::XMFLOAT3* velocityOutput_;

};

