#include "EnemyPentagonBT.h"

#include "../TaskNodes/WaitNode.h"
#include "../TaskNodes/ShootForSecondsNode.h"
#include "../TaskNodes/SetFloatNode.h"
#include "../TaskNodes/MoveToEntityNode.h"

#include "../../Enemy.h"
#include "../../Game.h"
#include "../Blackboard.h"
#include "../../Ship.h"

EnemyPentagonBT::EnemyPentagonBT(Enemy* enemy) :
	EnemyBT(enemy)
{
	std::shared_ptr<Blackboard> blackboard = GetBlackboard();

	sequence_ = std::make_shared<SequenceNode>();

	moveToPlayerPosition_ = std::make_shared<MoveToEntity>(blackboard->position_, blackboard->player_, 4.0f, blackboard->velocity_, 50.0f);
	attackSpin_ = std::make_shared<SetFloatNode>(blackboard->rotationSpeed_, 500.0f);
	shootSpin_ = std::make_shared<ShootForSecondsNode>(blackboard->game_, blackboard->position_, blackboard->forward_, 1.0f, 0.06f);
	calmSpin_ = std::make_shared<SetFloatNode>(blackboard->rotationSpeed_, 200.0f);
	wait_ = std::make_shared<WaitNode>(1.5f);

	SetRootChild(sequence_);

	sequence_->AddChild(moveToPlayerPosition_);
	sequence_->AddChild(wait_);
	sequence_->AddChild(attackSpin_);
	sequence_->AddChild(shootSpin_);
	sequence_->AddChild(calmSpin_);
	sequence_->AddChild(wait_);
}
