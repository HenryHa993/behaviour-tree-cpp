#pragma once
#include "../Node.h"
// Just set a boolean pointer value to another
class SetBoolNode :
    public Node
{
public:
    SetBoolNode(bool* boolInput, bool newBool);
    NodeTask Evaluate(float deltaTime) override;

private:
    bool* boolInput_;
    bool newBool_;
};

