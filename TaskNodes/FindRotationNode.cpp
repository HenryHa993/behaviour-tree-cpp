#include "FindRotationNode.h"
#include <cmath>
FindRotationNode::FindRotationNode(DirectX::XMFLOAT3* dirIn, float* rotationOutput) :
	directionIn_(dirIn),
	rotationOutput_(rotationOutput)
{
}

NodeTask FindRotationNode::Evaluate(float deltaTime)
{
	float rotation = std::atan2(directionIn_->x, directionIn_->y);
	*(rotationOutput_) = -rotation;
	co_return NodeState::SUCCESS;
}
