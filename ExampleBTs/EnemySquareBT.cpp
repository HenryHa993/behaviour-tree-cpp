#include "EnemySquareBT.h"
#include "../../Enemy.h"
#include "../../Game.h"
#include "../Blackboard.h"
#include "../../Ship.h"

#include "../TaskNodes/WaitNode.h"
#include "../TaskNodes/MoveInEntityDirectionNode.h"
#include "../TaskNodes/SetFloatNode.h"
#include "../TaskNodes/SetVelocityNode.h"

EnemySquareBT::EnemySquareBT(Enemy* enemy) :
	EnemyBT(enemy)
{
	std::shared_ptr<Blackboard> blackboard = GetBlackboard();

	sequence_ = std::make_shared<SequenceNode>();
	aggressiveSpin_ = std::make_shared<SetFloatNode>(blackboard->rotationSpeed_, 1000.0f);
	calmSpin_ = std::make_shared<SetFloatNode>(blackboard->rotationSpeed_, 100.0f);
	moveToPlayer_ = std::make_shared<MoveInEntityDirectionNode>(blackboard->position_, blackboard->player_, 4.0f, blackboard->velocity_);
	resetVelocity_ = std::make_shared<SetVelocityNode>(blackboard->velocity_, XMFLOAT3(0.0f, 0.0f, 0.0f));
	wait_ = std::make_shared<WaitNode>(1.5f);

	SetRootChild(sequence_);

	sequence_->AddChild(resetVelocity_);
	sequence_->AddChild(calmSpin_);
	sequence_->AddChild(wait_);
	sequence_->AddChild(aggressiveSpin_);
	sequence_->AddChild(moveToPlayer_);
	sequence_->AddChild(wait_);
}
