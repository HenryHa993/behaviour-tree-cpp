#include "SetBoolNode.h"

SetBoolNode::SetBoolNode(bool* boolInput, bool newBool) :
	boolInput_(boolInput),
	newBool_(newBool)
{
}

// If using this to reset cooldown, use this after your desired behaviour
// or it will tick down as you're running other behaviour.
NodeTask SetBoolNode::Evaluate(float deltaTime)
{
	*(boolInput_) = newBool_;
	co_return NodeState::SUCCESS;
}
