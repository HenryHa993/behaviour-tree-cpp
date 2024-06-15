#include "EnemyBT.h"
#include "../../Enemy.h"
#include "../../Game.h"
#include "../Blackboard.h"
#include "../../Ship.h"

EnemyBT::EnemyBT(Enemy* enemy) :
	BehaviourTree(enemy)
{
	SetBlackboard(std::make_shared<Blackboard>());
	SetupBlackboard();
}

// Setup default blackboard for enemy
void EnemyBT::SetupBlackboard()
{
	std::shared_ptr<Blackboard> blackboard = GetBlackboard();

	blackboard->game_ = static_cast<Enemy*>(GetOwner())->GetGame();

	blackboard->player_ = blackboard->game_->GetPlayer();
	blackboard->playerVelocity_ = blackboard->player_->GetVelocityPtr();
	blackboard->playerPosition_ = blackboard->player_->GetPositionPtr();

	blackboard->position_ = GetOwner()->GetPositionPtr();
	blackboard->velocity_ = static_cast<Enemy*>(GetOwner())->GetDesiredVelocityPtr();
	blackboard->forward_ = static_cast<Enemy*>(GetOwner())->GetForwardPtr();
	blackboard->rotation_ = static_cast<Enemy*>(GetOwner())->GetRotationPtr();
	blackboard->rotationSpeed_ = static_cast<Enemy*>(GetOwner())->GetRotationSpeedPtr();

	blackboard->cooldown_ = 3.0f;
	blackboard->offCooldown_ = false;
}
