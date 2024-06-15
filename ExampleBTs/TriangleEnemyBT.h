#pragma once
#include "EnemyBT.h"

class DirectionToEntityNode;
class FindRotationNode;

class SetRandomVelocityNode;
class WaitNode;
class SetVelocityNode;
class ShootInDirectionNode;

// Triangle enemy moves randomly and stops to shoot.
class TriangleEnemyBT :
    public EnemyBT
{
public:
    TriangleEnemyBT(Enemy* enemy);

private:
    std::shared_ptr<DirectionToEntityNode> directionToPlayerService_;
    std::shared_ptr<FindRotationNode> rotationToPlayerService_;
    std::shared_ptr<SequenceNode> sequence_;
    std::shared_ptr<SetRandomVelocityNode> randomVelocity_;
    std::shared_ptr<WaitNode> waitNode_;
    std::shared_ptr<SetVelocityNode> resetVelocity_;
    std::shared_ptr<ShootInDirectionNode> shootPlayer_;

};

