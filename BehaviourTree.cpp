#include "BehaviourTree.h"
#include "../GameEntity.h"
#include "Blackboard.h"

BehaviourTree::BehaviourTree(GameEntity* owner) :
	root_(new RootNode),
	ownerEntity_(owner),
	blackboard_(nullptr)
{
	root_->SetOwnerBT(this);
}

void BehaviourTree::SetRootChild(std::shared_ptr<Node> rootChild)
{
	rootChild->SetOwnerBT(this);
	root_->SetChild(rootChild);
}

void BehaviourTree::AddRootService(std::shared_ptr<Node> service)
{
	service->SetOwnerBT(this);
	root_->AddService(service);
}

// Evaluate entire tree
NodeTask BehaviourTree::Evaluate(float deltaTime) const
{
	// This loop allows the behaviour tree to refresh -- as coroutine handlers themselves cannot do so
	// Setup and run new coroutine
	while (true)
	{
		NodeTask RootTask = root_->Evaluate(deltaTime);

		NodeState Result = RootTask.Run();

		while (Result == NodeState::RUNNING)
		{
			// Return result and suspend till next tick
			co_yield Result;
			Result = RootTask.Run();
		}
		co_yield Result;
	}
	co_return NodeState::FAILURE;
}

void BehaviourTree::SetOwner(GameEntity* owner)
{
	ownerEntity_ = owner;
}

GameEntity* BehaviourTree::GetOwner()
{
	return ownerEntity_;
}

void BehaviourTree::SetBlackboard(std::shared_ptr<Blackboard> blackboard)
{
	blackboard_ = blackboard;
}

void BehaviourTree::SetupBlackboard()
{
}

std::shared_ptr<Blackboard> BehaviourTree::GetBlackboard()
{
	return blackboard_;
}
