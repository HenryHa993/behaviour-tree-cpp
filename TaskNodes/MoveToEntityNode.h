#pragma once
#include "../Node.h"
#include <DirectXMath.h>
class GameEntity;

// Moves towards an entity.
class MoveToEntity :
    public Node
{
public:
    MoveToEntity(DirectX::XMFLOAT3* currentPositionInput, GameEntity* targetGameEntity, float speedInput, DirectX::XMFLOAT3* velocityOutput, float acceptableDifference);

    NodeTask Evaluate(float deltaTime) override;

private:
    DirectX::XMFLOAT3* currentPositionInput_;
   // DirectX::XMFLOAT3& targetPositionInput_;
    GameEntity* targetGameEntity_;
    float speedInput_;

    DirectX::XMFLOAT3* velocityOutput_;
    
    float acceptableDifference_;
};

