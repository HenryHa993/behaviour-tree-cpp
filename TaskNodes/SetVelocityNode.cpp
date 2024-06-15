#include "SetVelocityNode.h"

SetVelocityNode::SetVelocityNode(DirectX::XMFLOAT3* velocityOutput, DirectX::XMFLOAT3 velocityInput) :
	velocityInput_(velocityInput),
	velocityOutput_(velocityOutput)
{
}

NodeTask SetVelocityNode::Evaluate(float deltaTime)
{
	*(velocityOutput_) = velocityInput_;
	co_return NodeState::SUCCESS;
}
