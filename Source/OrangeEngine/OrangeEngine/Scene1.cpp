#include <SFML/Graphics.hpp>
#include "Scene1.h"
#include "ScriptingSystem.h"
#include "ShapeComponent.h"
#include "oTransform.h"
#include "../../OrangeEngine.h"
#include "oRigidBody.h"

Scene1::Scene1()
{
	
}


Scene1::~Scene1()
{
}

void Scene1::buildScene()
{
	OrangeEngine* Orange = OrangeEngine::GetInstance();

	sf::Time t1 = sf::seconds(0.1f);
	float milli = t1.asMilliseconds();
	
	sf::Transformable t;
	oTransform ot;
	ot.SetTransform(&t);

	//Actor* sun = new Actor(new oTransform(), new oRigidBody(Orange->GetPhysics()));
	Actor* sun = new Actor(&ot, new oRigidBody(Orange->GetPhysics()));
	sun->AddComponent(new ShapeComponent(10, 10, sf::Color::Red));
	//sun->AddComponent(new ScriptComponent("movement.lua"));
	sun->GetTransform()->Translate(300, 0);
	sun->GetTransform()->Scale(10, 10);
	sun->Update(milli);
	
	
	/*if (sun->GetRigidbody()) {
		sun->GetRigidbody()->Integrate(milli);
		sun->GetRigidbody()->AddForce(sf::Vector2f(111, 1));
	}*/
	

	Actor* moon = new Actor(new oTransform(), new oRigidBody(Orange->GetPhysics()));
	moon->AddComponent(new ShapeComponent(10, 6, sf::Color::Blue));
	moon->GetTransform()->Translate(0, 0);
	moon->GetTransform()->Scale(1, 1);
	sun->AddChild(moon);
	//sun->position->Translate(50, 50);
	sun->GetTransform()->Rotate(90);

	Actor* star = new Actor(new oTransform(), new oRigidBody(Orange->GetPhysics()));
	star->AddComponent(new ShapeComponent(10, 5, sf::Color::Yellow));
	star->GetTransform()->Translate(-0, -0);
	star->GetTransform()->Scale(0.5, 0.5);
	moon->AddChild(star);

	Orange->AddActor(sun);
	Orange->AddActor(moon);
	Orange->AddActor(star);

	Orange->Run();
	delete(sun);

}

/*void Scene1::update(sf::Time elapsedTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		// left key is pressed: move our character
		//sun.move(1, 0);
		exit(0);
	}
}*/

