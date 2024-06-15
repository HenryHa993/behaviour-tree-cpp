#pragma once
#include "EnemyBT.h"

class SequenceNode;
class SetFloatNode;
class WaitNode;
class MoveInEntityDirectionNode;
class SetVelocityNode;

// Enemy which tries to ram the player
class EnemySquareBT :
    public EnemyBT
{
public:
    EnemySquareBT(Enemy* enemy);

private:
    std::shared_ptr<SequenceNode> sequence_;
    std::shared_ptr<SetFloatNode> aggressiveSpin_;
    std::shared_ptr<MoveInEntityDirectionNode> moveToPlayer_;
    std::shared_ptr<SetVelocityNode> resetVelocity_;
    std::shared_ptr<WaitNode> wait_;
    std::shared_ptr<SetFloatNode> calmSpin_;
};

