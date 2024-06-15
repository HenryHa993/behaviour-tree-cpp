#include "Node.h"

Node::Node() : ownerBT_(nullptr)
{
}

// Default behaviour for empty node
// Intended to be overriden, for the user to implement their own behaviours
NodeTask Node::Evaluate(float deltaTime)
{
	co_return NodeState::FAILURE;
}

// Service always return SUCCESS and allows the BT to track states during RUNNING
void Node::AddService(std::shared_ptr<Node> service)
{
	service->SetOwnerBT(GetOwnerBT());
	services_.emplace_back(service);
}

// Iterates through services, running them one by one
void Node::RunServices(float deltaTime)
{
	if (GetServices().empty())
	{
		return;
	}

	for (std::shared_ptr<Node> Service : GetServices())
	{
		NodeTask Task = Service->Evaluate(deltaTime);
		NodeState Result = Task.Run();
	}
}

void Node::SetOwnerBT(BehaviourTree* owner)
{
	ownerBT_ = owner;
}

// Add child to back of the list
void CompositeNode::AddChild(std::shared_ptr<Node> child)
{
	child->SetOwnerBT(GetOwnerBT());
	children_.emplace_back(child);
}

// Selector node
NodeTask SelectorNode::Evaluate(float deltaTime)
{
	for (std::shared_ptr<Node> Child : GetChildren())
	{
		NodeTask Task = Child->Evaluate(deltaTime);
		NodeState Result = Task.Run();

		switch (Result)
		{
		case NodeState::FAILURE:
			continue;

		case NodeState::SUCCESS:
			co_return NodeState::SUCCESS;

		case NodeState::RUNNING:
			while (Result == NodeState::RUNNING)
			{
				co_yield NodeState::RUNNING;
				Result = Task.Run();
			}

		}
	}

	co_return NodeState::FAILURE;
}

// Sequence node
NodeTask SequenceNode::Evaluate(float deltaTime)
{

	for (std::shared_ptr<Node> Child : GetChildren())
	{
		NodeTask Task = Child->Evaluate(deltaTime);
		NodeState Result = Task.Run();

		switch (Result)
		{
		case NodeState::SUCCESS:
			continue;

		case NodeState::FAILURE:
			co_return NodeState::FAILURE;

		case NodeState::RUNNING:
			while (Result == NodeState::RUNNING)
			{
				co_yield NodeState::RUNNING;
				Result = Task.Run();
			}
		}
	}

	co_return NodeState::SUCCESS;
}

RootNode::RootNode() : child_(nullptr)
{
}

void RootNode::SetChild(std::shared_ptr<Node> newChild)
{
	child_ = newChild;
}

// Evaluate root node
NodeTask RootNode::Evaluate(float deltaTime)
{
	NodeTask ChildTask = child_->Evaluate(deltaTime);

	// Run services here
	RunServices(deltaTime);
	NodeState Result = ChildTask.Run();

	// If initial state is RUNNING
	while (Result == NodeState::RUNNING)
	{
		// Return result and suspend the tree until the next tick where it will run again
		co_yield Result;

		// Also run services here
		RunServices(deltaTime);
		Result = ChildTask.Run();
	}
	co_return Result;
}