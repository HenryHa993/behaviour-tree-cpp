#pragma once
#include "../Node.h"
#include <DirectXMath.h>

class Game;

// This node lets you shoot continuosly for a given duration.
class ShootForSecondsNode :
    public Node
{
public:
    ShootForSecondsNode(Game* game, DirectX::XMFLOAT3* posIn, DirectX::XMFLOAT3* dirIn, float durationIn, float intervalIn);
    NodeTask Evaluate(float deltaTime) override;

private:
    Game* game_;
    DirectX::XMFLOAT3* positionIn_;
    DirectX::XMFLOAT3* directionIn_;
    float duration_;
    float interval_;
};

