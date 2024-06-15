#pragma once
#include "Node.h"
class GameEntity;
struct Blackboard;

class BehaviourTree {

public:
	BehaviourTree(GameEntity* owner);
  	~BehaviourTree() = default;
	void SetRootChild(std::shared_ptr<Node> rootChild);
	void AddRootService(std::shared_ptr<Node> service);
	NodeTask Evaluate(float deltaTime) const;

	void SetOwner(GameEntity* owner);
	GameEntity* GetOwner();

	// Every bt should have a blackboard setup
	void SetBlackboard(std::shared_ptr<Blackboard> blackboard);
	virtual void SetupBlackboard();
	std::shared_ptr<Blackboard> GetBlackboard();
private:
	std::shared_ptr<RootNode> root_;
	std::shared_ptr<Blackboard> blackboard_;
	GameEntity* ownerEntity_;
};