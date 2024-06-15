#pragma once
#include "../BehaviourTree.h"
class SetRandomVelocityNode;
class WaitNode;
class MoveToEntity;
class Enemy;
class CheckBoolNode;
class SetBoolNode;
class CooldownNode;
class SetVelocityNode;
class DirectionToEntityNode;
class ShootInDirectionNode;
class FindRotationNode;
class SetFloatNode;

// This is my behaviour tree playground.
// I test out some nodes and some basic behaviours here.
class TestBT :
    public BehaviourTree
{
public:
    TestBT(Enemy* enemy);
    void SetupBlackboard() override;

private:
    std::shared_ptr<SequenceNode> sequenceNode1_;
    std::shared_ptr<SetRandomVelocityNode> RandomVelocityNode_;
    std::shared_ptr<WaitNode> waitNode_;
    std::shared_ptr<MoveToEntity> moveToNode_;

    std::shared_ptr<SequenceNode> sequenceNode2_;
    std::shared_ptr<SelectorNode> selector_;
    std::shared_ptr<CooldownNode> cooldownService_;
    std::shared_ptr<CheckBoolNode> checkBool_;
    std::shared_ptr<SetBoolNode> setBool_;
    std::shared_ptr<SetVelocityNode> resetVelocity_;
    std::shared_ptr<DirectionToEntityNode> directionToPlayer_;
    std::shared_ptr<ShootInDirectionNode> shootPlayer_;
    std::shared_ptr<FindRotationNode> rotationService_;

    std::shared_ptr<SetFloatNode> resetRotationSpeed_;
    std::shared_ptr<SetFloatNode> setRotationSpeed_;
    std::shared_ptr<ShootInDirectionNode> shootForward_;
};

