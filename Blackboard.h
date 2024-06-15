#pragma once
#include <DirectXMath.h>

class Ship;
class Game;
// This is just a struct of values.
// Intended to be set up in behaviour tree
// Pointers are used to avoid going into specific classes to set things like velocity
struct Blackboard {
	Game* game_;

	Ship* player_;
	DirectX::XMFLOAT3* playerVelocity_;
	DirectX::XMFLOAT3* playerPosition_;

	DirectX::XMFLOAT3* velocity_;
	DirectX::XMFLOAT3* position_;
	DirectX::XMFLOAT3 direction_;
	DirectX::XMFLOAT3* forward_;
	float* rotation_;
	float* rotationSpeed_;

	float cooldown_;
	bool offCooldown_;


};

