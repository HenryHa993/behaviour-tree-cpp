#pragma once
#include "../BehaviourTree.h"

class Enemy;
// This is the base class from which all enemy bts inherit from
// Blackboard setup for each enemy is the same
class EnemyBT :
    public BehaviourTree
{
public:
    EnemyBT(Enemy* enemy);
    void SetupBlackboard() override;
};

