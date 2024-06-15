#pragma once
#include "../Node.h"
#include <DirectXMath.h>

class GameEntity;

// A service which updates a direction variable to a given node.
// I could actually use this to make enemies point at the player... hmm
class DirectionToEntityNode : public Node
{
public:
	DirectionToEntityNode(GameEntity* targetEntityInput, DirectX::XMFLOAT3* positionInput, DirectX::XMFLOAT3* directionOutput);
	NodeTask Evaluate(float deltaTime) override;

private:
	GameEntity* targetEntityInput_;
	DirectX::XMFLOAT3* positionInput_;
	DirectX::XMFLOAT3* directionOutput_;
};

