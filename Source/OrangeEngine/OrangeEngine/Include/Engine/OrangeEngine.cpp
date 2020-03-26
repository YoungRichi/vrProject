#include "OrangeEngine.h"



sf::Time OrangeEngine::TimePerFrame = sf::seconds(1.f / 20.f);

OrangeEngine::OrangeEngine()
{
	//Create Render System (Window)
	Splash->Splash(_mainWindow, time);

	//Create Physics Engine
	PhysicsEngine = new PhysicSystem();

	//Create Game Object Manager
	SceneManager = new GameObject("ObjectManager");

	//Set Object Manager in the center of the world (Window)	
	sf::Vector2f WindowCenter(_mainWindow.getSize().x * 0.5f, _mainWindow.getSize().y * 0.5f);
	SceneManager->GetComponent(Transform_Component)->setPosition(WindowCenter);


	InputSystem::GetInstance()->AddAction(Space, sf::Keyboard::Key::Space);


}

void OrangeEngine::gameLoop()
{

	//time = clock.getElapsedTime();	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (_mainWindow.isOpen())
	{
		sf::Time dt = clock.restart();
		timeSinceLastUpdate += dt;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			if (SplashClock > 3.5f)
			{
				
				render();
				eventprocessor();
				PhysicsEngine->UpdatePhysics(TimePerFrame.asSeconds());
				SceneManager->Update(TimePerFrame);
			}
		}

		Update(TimePerFrame.asSeconds());
		SplashClock += dt.asSeconds();
		render();

	}
}

void OrangeEngine::render()
{
	if (SplashClock <= 3.0f)
	{
		_mainWindow.clear();
		_mainWindow.display();
	}
	else
	{

		_mainWindow.clear();
		
		SceneManager->RenderGO(_mainWindow);
		_mainWindow.display();

	}

}

void OrangeEngine::eventprocessor()
{
	sf::Event event;
	while (_mainWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			_mainWindow.close();

	}
}

void OrangeEngine::InitWindow()
{
	Bird = SceneManager->FindGameObject("Bird");
	gameLoop();
}

void OrangeEngine::Update(float dt)
{


	auto input = InputSystem::GetInstance();

	if (input->IsActionTriggered(Input_ID::Space))
	{
		float jumpHeight = 0.3f;

		for (std::vector<GameObject*>::iterator it = script_objects.begin(); it != script_objects.end(); ++it)
		{
			float mass = (*it)->GetComponent(Physics_Component)->GetObjectMass();
			float jumpImpulse = (*it)->GetComponent(Script_Component)->RunScript("jumpImpulse", mass, jumpHeight);
			(*it)->GetComponent(Physics_Component)->AddForce(sf::Vector2f(0.0f, jumpImpulse));
		}
	}

}



//Create Game Objects
void OrangeEngine::CreateObject(std::string ObjectName, float x, float y)
{
	//Create new Object
	GameObject *ChildObj = new GameObject(ObjectName);

	//Get position coordinates and set object at position updating its transform (Default coords = 0,0)
	sf::Vector2f ObjectPosition(x, y);
	ChildObj->GetComponent(Transform_Component)->setPosition(ObjectPosition);

	//Add Child to GameManager graph
	SceneManager->AddChild(ChildObj);

	ChildObj->AddComponent(Render_Component);
	ChildObj->GetComponent(Render_Component)->setColor(sf::Color::Green);
}

//Find object with parent name in graph and assign it as parent to object  child name
void OrangeEngine::SetObjectParent(std::string ObjParentName, std::string ObjChildName)
{
	GameObject *ParentObject = SceneManager->FindGameObject(ObjParentName);
	//If we didnt find our desired parent object then no need to keep searching
	if (!ParentObject)
		return;

	GameObject *ChildObject = SceneManager->FindGameObject(ObjChildName);
	//If we didnt find child object then there is nothing to assign to parent
	if (!ChildObject)
		return;

	ParentObject->AddChild(ChildObject);
}

//Find object with name in graph and add specified component to it

void OrangeEngine::SetTextureComponent(std::string objName, sf::Vector2f size, sf::Color color, std::string text, std::string texturePath, int FontSize, std::string FontPath)
{
	GameObject *gameObject = SceneManager->FindGameObject(objName);
	if (!gameObject)
		return;

	gameObject->GetComponent(Render_Component)->SetTexture(texturePath);
	gameObject->GetComponent(Render_Component)->SetFont(FontPath);

	gameObject->AddComponent(Render_Component);
	gameObject->GetComponent(Render_Component)->setSize(size);
	gameObject->GetComponent(Render_Component)->SetText(text);
	gameObject->GetComponent(Render_Component)->SetTextSize(FontSize);
	gameObject->GetComponent(Render_Component)->setColor(color);
	gameObject->GetComponent(Render_Component)->SetTextColor(color);
}

void OrangeEngine::SetPhysicsComponent(std::string objName, float mass, bool hasGravity, sf::Vector2f Velocity)
{
	GameObject *gameObject = SceneManager->FindGameObject(objName);
	if (!gameObject)
		return;

	gameObject->AddComponent(Physics_Component);
	gameObject->GetComponent(Physics_Component)->AddRigidBodyToPhysicsSystem(*PhysicsEngine);
	gameObject->GetComponent(Physics_Component)->setPosition(gameObject->GetComponent(Transform_Component)->getPosition());
	gameObject->GetComponent(Physics_Component)->AddRenderComponentToRigidBody(gameObject->GetComponent(Render_Component));
	gameObject->GetComponent(Physics_Component)->SetObjectMass(mass);
	gameObject->GetComponent(Physics_Component)->SetHasGravity(hasGravity);
	gameObject->GetComponent(Physics_Component)->SetCurrentVelocity(Velocity);
}

void OrangeEngine::SetAudioComponent(std::string objName, std::string filePath, bool playOnAwake, bool Loop)
{
	
	GameObject *gameObject = SceneManager->FindGameObject(objName);
	if (!gameObject)
		return;

	gameObject->AddComponent(Audio_Component);
	gameObject->GetComponent(Audio_Component)->loadSound(filePath);
	gameObject->GetComponent(Audio_Component)->LoopSound(Loop);

	if (playOnAwake)
		gameObject->GetComponent(Audio_Component)->playSound();

}

void OrangeEngine::SetScriptComponent(std::string objName, std::string scriptName)
{
	GameObject *gameObject = SceneManager->FindGameObject(objName);
	if (!gameObject)
		return;

	gameObject->AddComponent(Script_Component);
	gameObject->GetComponent(Script_Component)->SetScriptName(scriptName);

	script_objects.push_back(gameObject);
}
