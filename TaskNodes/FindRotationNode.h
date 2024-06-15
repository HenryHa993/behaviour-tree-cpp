#pragma once
#include "../Node.h"
#include <DirectXMath.h>
// Service that returns a rotation for a direction against the y axis
class FindRotationNode : public Node
{
public:
	FindRotationNode(DirectX::XMFLOAT3* dirIn, float* rotationOutput);
	NodeTask Evaluate(float deltaTime) override;
private:
	DirectX::XMFLOAT3* directionIn_;
	float* rotationOutput_;

};

