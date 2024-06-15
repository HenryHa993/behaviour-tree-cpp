#pragma once
#include "../Node.h"
#include <DirectXMath.h>

class GameEntity;

// Similar to move to position, but it just sets the velocity to the entity and leaves.
// So it doesn't check if it has reach the destination, will just set a velocity towards it
class MoveInEntityDirectionNode :
    public Node
{
public:
    MoveInEntityDirectionNode(DirectX::XMFLOAT3* currentPositionInput, GameEntity* targetGameEntity, float speedInput, DirectX::XMFLOAT3* velocityOutput);
    NodeTask Evaluate(float deltaTime) override;

private:
    DirectX::XMFLOAT3* currentPositionInput_;
    GameEntity* targetGameEntity_;
    float speedInput_;

    DirectX::XMFLOAT3* velocityOutput_;
};

