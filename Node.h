#pragma once
#include "NodeTask.h"
#include <vector>
#include <memory>
class BehaviourTree;

class Node
{
public:
	Node();
	~Node() = default;
	virtual NodeTask Evaluate(float deltaTime);
	void AddService(std::shared_ptr<Node> service);
	void RunServices(float deltaTime);
	const std::vector<std::shared_ptr<Node>>& GetServices() const { return services_; }
	void SetOwnerBT(BehaviourTree* owner);
	BehaviourTree* GetOwnerBT() const { return ownerBT_; }
private:
	std::vector<std::shared_ptr<Node>> services_;
	BehaviourTree* ownerBT_;
};

// Composite nodes have multiple children
class CompositeNode : public Node
{
private:
	std::vector<std::shared_ptr<Node>> children_;

public:
	const std::vector<std::shared_ptr<Node>>& GetChildren() const { return children_; }
	void AddChild(std::shared_ptr<Node> child);
};

// Flow Control nodes
// Selector returns true when the first child does
class SelectorNode : public CompositeNode
{
public:
	virtual NodeTask Evaluate(float deltaTime) override;
};

//Fails when any child fails
class SequenceNode : public CompositeNode
{
public:
	virtual NodeTask Evaluate(float deltaTime) override;
};

class RootNode : public Node
{
private:
	std::shared_ptr<Node> child_;

public:
	RootNode();
	void SetChild(std::shared_ptr<Node> newChild);
	NodeTask Evaluate(float deltaTime) override;
};

