#include "TestBT.h"

#include "../TaskNodes/SetRandomVelocityNode.h"
#include "../TaskNodes/WaitNode.h"
#include "../TaskNodes/MoveToEntityNode.h"
#include "../TaskNodes/CheckBoolNode.h"
#include "../TaskNodes/CooldownNode.h"
#include "../TaskNodes/SetBoolNode.h"
#include "../TaskNodes/SetVelocityNode.h"
#include "../TaskNodes/ShootInDirectionNode.h"
#include "../TaskNodes/DirectionToEntityNode.h"
#include "../TaskNodes/FindRotationNode.h"
#include "../TaskNodes/SetFloatNode.h"

#include "../../Enemy.h"
#include "../../Game.h"
#include "../Blackboard.h"
#include "../../Ship.h"

TestBT::TestBT(Enemy* enemy) :
	BehaviourTree(enemy)
{
	SetBlackboard(std::make_shared<Blackboard>());
	SetupBlackboard();

	// I want to make setting it up more intuitive than pointing it to the variables owned by certain things. So a blackboard would be good here
	std::shared_ptr<Blackboard> blackboard = GetBlackboard();

	// Testing if behaviour tree works
	std::shared_ptr<SequenceNode> sequenceNode1_;
	std::shared_ptr<SetRandomVelocityNode> RandomVelocityNode_;
	std::shared_ptr<WaitNode> waitNode_;
	std::shared_ptr<MoveToEntity> moveToNode_;

	std::shared_ptr<SelectorNode> selector_;
	std::shared_ptr<SequenceNode> sequenceNode2_;
	std::shared_ptr<SetBoolNode> setBool_;
	std::shared_ptr<CheckBoolNode> checkBool_;
	std::shared_ptr<CooldownNode> cooldownService_;
	std::shared_ptr<SetVelocityNode> resetVelocity_;
	std::shared_ptr<DirectionToEntityNode> directionToPlayer_;
	std::shared_ptr<ShootInDirectionNode> shootPlayer_;
	std::shared_ptr<FindRotationNode> rotationService_;
	std::shared_ptr<SetFloatNode> setRotationSpeed_;
	std::shared_ptr<SetFloatNode> resetRotationSpeed_;
	std::shared_ptr<ShootInDirectionNode> shootForward_;
	// Set up behaviour tree
	//SetRootChild(sequenceNode1_);
	//sequenceNode1_->AddChild(moveToNode_);
	//sequenceNode1_->AddChild(waitNode_);


	//SetRootChild(selector_);
	//AddRootService(cooldownService_);
	//AddRootService(directionToPlayer_);
	//AddRootService(rotationService_);

	//selector_->AddChild(sequenceNode1_);
	//selector_->AddChild(sequenceNode2_);

	//sequenceNode1_->AddChild(checkBool_);
	//sequenceNode1_->AddChild(moveToNode_);
	//sequenceNode1_->AddChild(setBool_);
	//sequenceNode1_->AddChild(resetVelocity_);

	//// This can be a sort of rapid fire thing.
	//sequenceNode2_->AddChild(shootPlayer_);
	//sequenceNode2_->AddChild(waitNode_);
	//sequenceNode2_->AddChild(shootPlayer_);
	//sequenceNode2_->AddChild(waitNode_);

	
	SetRootChild(sequenceNode1_);

	//sequenceNode1_->AddChild(setRotationSpeed_);
	sequenceNode1_->AddChild(shootForward_);
	sequenceNode1_->AddChild(waitNode_);
}

// Blackboard setup during construction. This makes node initialisation less painful.
// As some bb pointers are updated elsewhere or through nodes, most values won't have to be updated as a service.
// For certain values, such as bool IsPlayerInRange, it's probably more intuitive to update as a root node service.
void TestBT::SetupBlackboard()
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
