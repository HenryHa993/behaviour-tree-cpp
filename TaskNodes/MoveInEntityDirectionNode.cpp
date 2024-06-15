#include "MoveInEntityDirectionNode.h"
#include "../../GameEntity.h"

MoveInEntityDirectionNode::MoveInEntityDirectionNode(DirectX::XMFLOAT3* currentPositionInput, GameEntity* targetGameEntity, float speedInput, DirectX::XMFLOAT3* velocityOutput) :
	currentPositionInput_(currentPositionInput),
	targetGameEntity_(targetGameEntity),
	speedInput_(speedInput),
	velocityOutput_(velocityOutput)
{
}

NodeTask MoveInEntityDirectionNode::Evaluate(float deltaTime)
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
    co_return NodeState::SUCCESS;
}
