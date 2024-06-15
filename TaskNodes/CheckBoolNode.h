#pragma once
#include "../Node.h"

// Checks if given boolean is true or false.
// Will return SUCCESS or FAILURE to inputs respectively.
class CheckBoolNode : public Node
{
public:
	CheckBoolNode(bool* boolInput);
	NodeTask Evaluate(float deltaTime) override;
private:
	bool* boolInput_;
};