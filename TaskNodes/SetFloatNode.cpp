#include "SetFloatNode.h"

SetFloatNode::SetFloatNode(float* targetFloat, float newFloat) :
	targetFloat_(targetFloat),
	newFloat_(newFloat)
{
}

NodeTask SetFloatNode::Evaluate(float deltaTime)
{
	*(targetFloat_) = newFloat_;
	co_return NodeState::SUCCESS;
}
