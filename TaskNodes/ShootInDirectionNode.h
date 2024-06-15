#pragma once
#include "../Node.h"
#include <DirectXMath.h>
class Game;

// Shoot an enemy bullet with a given direction and position.
class ShootInDirectionNode :
    public Node
{
public:
    ShootInDirectionNode(Game* game, DirectX::XMFLOAT3* positionInput, DirectX::XMFLOAT3* directionInput);
    NodeTask Evaluate(float deltaTime) override;

private:
    Game* game_;
    DirectX::XMFLOAT3* directionInput_;
    DirectX::XMFLOAT3* positionInput_;
};

