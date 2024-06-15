#include "ShootForSecondsNode.h"
#include "../../Game.h"
ShootForSecondsNode::ShootForSecondsNode(Game* game, DirectX::XMFLOAT3* posIn, DirectX::XMFLOAT3* dirIn, float durationIn, float intervalIn) :
	game_(game),
	positionIn_(posIn),
	directionIn_(dirIn),
	duration_(durationIn),
	interval_(intervalIn)
{

}

NodeTask ShootForSecondsNode::Evaluate(float deltaTime)
{
	float currentDurationTimer = duration_;
	float currentIntervalTimer = interval_;

	while (!(currentDurationTimer < 0))
	{
		currentDurationTimer -= deltaTime;
		currentIntervalTimer -= deltaTime;

		if (currentIntervalTimer < 0)
		{
			game_->SpawnBullet(DirectX::XMLoadFloat3(positionIn_), DirectX::XMLoadFloat3(directionIn_), false);
			currentIntervalTimer = interval_;
		}

		co_yield NodeState::RUNNING;
	}

	co_return NodeState::SUCCESS;
}
