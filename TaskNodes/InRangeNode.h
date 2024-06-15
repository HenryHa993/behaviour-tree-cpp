#pragma once
#include "../Node.h"
#include <DirectXMath.h>

// Return SUCCESS if positions in range
// This was initially used for the pentagon, but it was too difficult fight against.
class InRangeNode :
    public Node
{
public:
    InRangeNode(DirectX::XMFLOAT3* posIn1, DirectX::XMFLOAT3* posIn2, float range);
    NodeTask Evaluate(float deltaTime) override;

private:
    DirectX::XMFLOAT3* positionIn1_;
    DirectX::XMFLOAT3* positionIn2_;
    float range_;
};

