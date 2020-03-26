#pragma once
#include "../Unity/Unity.h"
#include "../ResourceManager/ResourceManager.h"

class PhysicSystem;

class BaseComponent
{

public:
	//*****************************************//
	// GENERAL COMPONENT FUNCTIONS			   //	
	// FUNCTIONS THAT ALL COMPONENTS COULD HAVE//
	//*****************************************//
	//virtual  Component_Definition GetComponentType() { return Default; }		

	virtual void setPosition(sf::Vector2f newPosition) {} // TRANSFORM && PHYSICS

	//******************************************//
	// COMPONENT FUNCTIONS						//

	// TRANSFORM COMPONENT

	virtual sf::Vector2f getPosition() { return sf::Vector2f(); }
	virtual sf::Transformable *GetTransform() { return &sf::Transformable(); }
	virtual sf::Transform getWorldTransform() { return sf::Transform(); }

	virtual void setWorldTransform(sf::Transform worldTransform) {}

	virtual void rotate(float angleValue) {}
	virtual void move(sf::Vector2f moveVector) {}

	virtual  void Update(sf::Time dt, sf::Transform *parentWorldTransform = nullptr) {}

	// INPUT COMPONENT
	//virtual void GetInstance();


	// RENDER COMPONENT
	virtual void setSize(sf::Vector2f x) {}
	virtual void setColor(sf::Color color) {}
	virtual void setPosition(sf::Transformable p) {}
	virtual sf::RectangleShape getShape() { return sf::RectangleShape(); }
	virtual sf::FloatRect GetBounds() { return sf::FloatRect(); }
	virtual void RenderObject(sf::RenderWindow &win, sf::Transform WorldTransform) {};
	virtual void SetTexture(std::string path) {};
	//Text
	virtual void SetFont(std::string fontPath) {};
	virtual void SetText(std::string text) {};
	virtual void SetTextSize(int textSize) {};
	virtual void SetTextColor(sf::Color textColor) {};
	virtual void SetTextPosition(sf::Vector2f textPos) {};
	//AUDIO COMPONENT
	virtual void loadSound(std::string filePath) {}
	virtual void playSound() {}
	virtual void pauseSound() {}
	virtual void LoopSound(bool loop) {}

	//virtual void		handleEvent(const sf::Event& event) = 0;

	//RIGIDBODY COMPONENT
	virtual void AddRigidBodyToPhysicsSystem(PhysicSystem& PhysicsSystem) {}
	virtual sf::Vector2f GetRigidBodyPosition() { return sf::Vector2f(); }
	virtual void SetCurrentVelocity(sf::Vector2f velocity) {}
	virtual void AddRenderComponentToRigidBody(BaseComponent* renderComponent) {}
	virtual void AddForce(sf::Vector2f force) {}
	virtual float GetObjectMass() { return 0.0f; }
	virtual void SetObjectMass(float objMass) {}
	virtual void SetHasGravity(bool hasGravity) {}
	virtual bool GetTriggeredCollision() { return false; }
	virtual void SetTriggeredCollision(bool collision) {}

	//SCRIPT COMPONENT
	virtual void  SetScriptName(std::string scriptName) {}
	virtual float RunScript(std::string functionName, float mass, float height) { return 0.0f; }
	virtual bool  RunScript(std::string functionName, float objectPosX) { return false; }
private:

};




