#pragma once
#include "EnemyBT.h"

class MoveToEntity;
class SetFloatNode;
class ShootForSecondsNode;
class WaitNode;

// This enemy fires bullets in a spiral.
// Initially would only fire when player was in range, which was too strong.
// Goes to player location, and does a spinning shooting attack.
class EnemyPentagonBT :
    public EnemyBT
{
public:
    EnemyPentagonBT(Enemy* enemy);

private:

    std::shared_ptr<SequenceNode> sequence_;
    std::shared_ptr<MoveToEntity> moveToPlayerPosition_;
    std::shared_ptr<SetFloatNode> attackSpin_;
    std::shared_ptr<ShootForSecondsNode> shootSpin_;
    std::shared_ptr<SetFloatNode> calmSpin_;
    std::shared_ptr<WaitNode> wait_;
};

