#include "MoveToEntityNode.h"
#include "../../GameEntity.h"

MoveToEntity::MoveToEntity(DirectX::XMFLOAT3* currentPositionInput, GameEntity* targetGameEntity, float speedInput, DirectX::XMFLOAT3* velocityOutput, float acceptableDifference) :
	currentPositionInput_(currentPositionInput),
    targetGameEntity_(targetGameEntity),
	speedInput_(speedInput),
	velocityOutput_(velocityOutput),
    acceptableDifference_(acceptableDifference)
{
}

// This should set the velocity and wait for target location reached
// A follow function would change velocity each frame
NodeTask MoveToEntity::Evaluate(float deltaTime)
{
    // Get position of entity
    DirectX::XMFLOAT3 targetPosition;
    DirectX::XMStoreFloat3(&targetPosition, targetGameEntity_->GetPosition());

    // Calculate the distance and normals
    float xDiff = targetPosition.x - currentPositionInput_->x;
    float yDiff = targetPosition.y - currentPositionInput_->y;

    float distance = sqrtf(pow(xDiff, 2) + pow(yDiff, 2));

    float xNorm = xDiff / distance;
    float yNorm = yDiff / distance;

    *(velocityOutput_) = DirectX::XMFLOAT3(xNorm * speedInput_, yNorm * speedInput_, 0.0f);

    bool isAtLocation = distance < acceptableDifference_;

    // If does not work
    while (!isAtLocation)
    {
        xDiff = targetPosition.x - currentPositionInput_->x;
        yDiff = targetPosition.y - currentPositionInput_->y;

        distance = sqrtf(pow(xDiff, 2) + pow(yDiff, 2));

        isAtLocation = distance < acceptableDifference_;
        co_yield NodeState::RUNNING;

    }

    *(velocityOutput_) = DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f);
    co_return NodeState::SUCCESS;
}
