#pragma once

class oRigidBody;

class PhysicsEngine
{
public:
	bool IsGrounded(oRigidBody* rb);

	PhysicsEngine();
	~PhysicsEngine();
};

