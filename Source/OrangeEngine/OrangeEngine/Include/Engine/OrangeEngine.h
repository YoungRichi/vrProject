#pragma once
#include "../Unity/Unity.h"
#include "../GameObject/GameObject.h"
#include "../System/Physic/PhysicSystem.h"
#include "../System/Input/InputSystem.h"
#include "../System/Splash/SplashScreen.h"

class OrangeEngine
{
public:
	OrangeEngine();

	sf::Clock clock;
	sf::Time time;


	static sf::Time TimePerFrame;
	void gameLoop();

	bool multiWindow = false;
	void render();
	void eventprocessor();
	void InitWindow();

	//Functions to create game objects, and add components
	void CreateObject(std::string ObjectName, float x = 0.0f, float y = 0.0f);

	void SetObjectParent(std::string ObjParentName, std::string ObjChildName);

	//Add component functions
	void SetTextureComponent(std::string objName, sf::Vector2f size = sf::Vector2f(0.0f, 0.0f), sf::Color color = sf::Color::Black, std::string text = "", std::string texturePath = "", int FontSize = 24, std::string FontPath = "");

	void SetPhysicsComponent(std::string objName, float mass = 1.0f, bool hasGravity = true, sf::Vector2f Velocity = sf::Vector2f(0.0f, 0.0f));

	void SetAudioComponent(std::string objName, std::string filePath, bool playOnAwake = false, bool Loop = false);

	void SetScriptComponent(std::string objName, std::string scriptName);


	GameObject* SceneManager;
	PhysicSystem* PhysicsEngine;


protected:
	sf::RenderWindow _mainWindow;

private:
	void Update(float deltaTime);
	std::vector<GameObject*> script_objects;
	
	SplashScreen* Splash;

	float SplashClock = 0.0f;
	GameObject *Bird;
};





