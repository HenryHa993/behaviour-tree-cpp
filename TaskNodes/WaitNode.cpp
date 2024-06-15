#include "WaitNode.h"

// Wait a given amount of time in seconds.
WaitNode::WaitNode(float waitTime) :
	waitTime_(waitTime)
{
}

NodeTask WaitNode::Evaluate(float deltaTime)
{
    float timer = 0;
    bool timerDone = std::abs(waitTime_ - timer) < 0.01f;

    while (!timerDone)
    {
        timer += deltaTime;
        timerDone = std::abs(waitTime_ - timer) < 0.01f;
        co_yield NodeState::RUNNING;
    }

    co_return NodeState::SUCCESS;
}
