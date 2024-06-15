#include "ShootInDirectionNode.h"
#include "../../Game.h"
ShootInDirectionNode::ShootInDirectionNode(Game* game, DirectX::XMFLOAT3* positionInput, DirectX::XMFLOAT3* directionInput)
	:
	game_(game),
	positionInput_(positionInput),
	directionInput_(directionInput)
{
}

NodeTask ShootInDirectionNode::Evaluate(float deltaTime)
{
	game_->SpawnBullet(DirectX::XMLoadFloat3(positionInput_), DirectX::XMLoadFloat3(directionInput_), false);
	co_return NodeState::SUCCESS;
}
