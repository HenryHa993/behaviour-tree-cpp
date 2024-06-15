#include "InRangeNode.h"

InRangeNode::InRangeNode(DirectX::XMFLOAT3* posIn1, DirectX::XMFLOAT3* posIn2, float range) :
	positionIn1_(posIn1),
	positionIn2_(posIn2),
	range_(range)
{
}

NodeTask InRangeNode::Evaluate(float deltaTime)
{
	float xDiff = positionIn1_->x - positionIn2_->x;
	float yDiff = positionIn1_->y - positionIn2_->y;

	float distance = sqrtf(pow(xDiff, 2) + pow(yDiff, 2));

	if (distance < range_)
	{
		co_return NodeState::SUCCESS;
	}

	co_return NodeState::FAILURE;
}
