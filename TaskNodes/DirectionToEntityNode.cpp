#include "DirectionToEntityNode.h"
#include "../../GameEntity.h"
DirectionToEntityNode::DirectionToEntityNode(GameEntity* targetEntityInput, DirectX::XMFLOAT3* positionInput, DirectX::XMFLOAT3* directionOutput) :
	targetEntityInput_(targetEntityInput),
	positionInput_(positionInput),
	directionOutput_(directionOutput)
{
}

NodeTask DirectionToEntityNode::Evaluate(float deltaTime)
{
    // Get position of entity
    DirectX::XMFLOAT3 targetPosition;
    DirectX::XMStoreFloat3(&targetPosition, targetEntityInput_->GetPosition());

    // Calculate the distance and normals
    float xDiff = targetPosition.x - positionInput_->x;
    float yDiff = targetPosition.y - positionInput_->y;

    //float distance = sqrtf(pow(xDiff, 2) + pow(yDiff, 2));

    //float xNorm = xDiff / distance;
    //float yNorm = yDiff / distance;

    *(directionOutput_) = DirectX::XMFLOAT3(xDiff, yDiff, 0.0f);
    co_return NodeState::SUCCESS;
}
