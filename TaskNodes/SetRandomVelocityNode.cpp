#include "SetRandomVelocityNode.h"
#include "../BehaviourTree.h"
#include <random>

// Pass in a reference. Trying to avoid coupling Character class to node tasks.
SetRandomVelocityNode::SetRandomVelocityNode(DirectX::XMFLOAT3* velocityOutput, float minRange, float maxRange) :
    velocityOutput_(velocityOutput),
    maxRange_(maxRange),
    minRange_(minRange)
{
}

NodeTask SetRandomVelocityNode::Evaluate(float deltaTime)
{
    DirectX::XMFLOAT3 velocity = DirectX::XMFLOAT3(((float)rand() / RAND_MAX) * (maxRange_ - minRange_) + minRange_, ((float)rand() / RAND_MAX) * (maxRange_ - minRange_) + minRange_, 0.0f);
    *(velocityOutput_) = velocity;
    co_return NodeState::SUCCESS;
}
