#include "CooldownNode.h"

CooldownNode::CooldownNode(bool* offCooldownOutput, float cooldown) :
	IsOffCooldownOutput_(offCooldownOutput),
	cooldownInSeconds_(cooldown),
	currentCooldown_(cooldownInSeconds_)
{
}

// This service should be reset elsewhere.
// If it reset itself, RUNNING nodes would mean other behaviours won't find out the instant off cooldown.
NodeTask CooldownNode::Evaluate(float deltaTime)
{
	if (*(IsOffCooldownOutput_) == true)
	{
		co_return NodeState::SUCCESS;
	}

	// Reset cooldown if another node elsewhere has reset the cooldown boolean to false.
	if (*(IsOffCooldownOutput_) == true && currentCooldown_ < 0)
	{
		currentCooldown_ = cooldownInSeconds_;
	}

	// On cooldown
	currentCooldown_ -= deltaTime;
	*(IsOffCooldownOutput_) = currentCooldown_ < 0;
	co_return NodeState::SUCCESS;
}

