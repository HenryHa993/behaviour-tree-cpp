#include "CheckBoolNode.h"

CheckBoolNode::CheckBoolNode(bool* boolInput) :
	boolInput_(boolInput)
{
}

NodeTask CheckBoolNode::Evaluate(float deltaTime)
{
	if (*(boolInput_))
	{
		co_return NodeState::SUCCESS;
	}
	co_return NodeState::FAILURE;
}
