#include "TriangleEnemyBT.h"
#include "../../Enemy.h"
#include "../../Game.h"
#include "../Blackboard.h"
#include "../../Ship.h"
#include "DirectXMath.h"

#include "../TaskNodes/SetRandomVelocityNode.h"
#include "../TaskNodes/WaitNode.h"
#include "../TaskNodes/SetVelocityNode.h"
#include "../TaskNodes/ShootInDirectionNode.h"
#include "../TaskNodes/DirectionToEntityNode.h"
#include "../TaskNodes/FindRotationNode.h"

TriangleEnemyBT::TriangleEnemyBT(Enemy* enemy) :
	EnemyBT(enemy)
{
	std::shared_ptr<Blackboard> blackboard = GetBlackboard();

	directionToPlayerService_ = std::make_shared<DirectionToEntityNode>(blackboard->player_, blackboard->position_, &(blackboard->direction_));
	rotationToPlayerService_ = std::make_shared<FindRotationNode>(&(blackboard->direction_), blackboard->rotation_);

	sequence_ = std::make_shared<SequenceNode>();
	randomVelocity_ = std::make_shared<SetRandomVelocityNode>(blackboard->velocity_, -2.5f, 2.5f);
	waitNode_ = std::make_shared<WaitNode>(1.5f);
	resetVelocity_ = std::make_shared<SetVelocityNode>(blackboard->velocity_, XMFLOAT3(0.0f, 0.0f, 0.0f));
	shootPlayer_ = std::make_shared<ShootInDirectionNode>(blackboard->game_, blackboard->position_, &(blackboard->direction_));

	AddRootService(directionToPlayerService_);
	AddRootService(rotationToPlayerService_);

	SetRootChild(sequence_);

	sequence_->AddChild(randomVelocity_);
	sequence_->AddChild(waitNode_);
	sequence_->AddChild(resetVelocity_);
	sequence_->AddChild(shootPlayer_);
	sequence_->AddChild(waitNode_);
}
