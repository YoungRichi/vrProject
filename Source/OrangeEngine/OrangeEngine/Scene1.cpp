#include <SFML/Graphics.hpp>
#include "Scene1.h"
#include "ScriptComponent.h"
#include "ShapeComponent.h"
#include "RectangleComponent.h"
#include "AudioComponent.h"
#include "oTransform.h"
#include <string>
#include "oRigidBody.h"
#include "../sol/sol.hpp"

Scene1::Scene1()
{

}


Scene1::~Scene1()
{
}

void Scene1::buildScene(OrangeEngine* Orange,sol::state &lua)
{
	
		
	sf::Time t1 = sf::seconds(0.1f);
	float milli = t1.asMilliseconds();

	//Actor* sun = new Actor(new oTransform(), new oRigidBody(Orange->GetPhysics()));
	////Actor* sun = new Actor(&ot, new oRigidBody(Orange->GetPhysics()));
	//sun->AddComponent(new ShapeComponent(30, 4, sf::Color::Red));
	////sun->AddComponent(new ScriptComponent("movement.lua"));
	//sun->GetTransform()->Translate(300, 0);
	////sun->GetTransform()->Scale(10, 10);
	//sun->Update(milli);
	
	
	/*if (sun->GetRigidbody()) {
		sun->GetRigidbody()->Integrate(milli);
		sun->GetRigidbody()->AddForce(sf::Vector2f(111, 1));
	}*/
	


	//Actor* moon = new Actor(new oTransform(), new oRigidBody(Orange->GetPhysics()));
	//moon->AddComponent(new ShapeComponent(50, 4, sf::Color::Blue));
	//moon->GetTransform()->Translate(0, 0);
	////moon->GetTransform()->Scale(1, 1);
	//sun->AddChild(moon);
	////sun->position->Translate(50, 50);
	//sun->GetTransform()->Rotate(90);

	/*Actor* moon = new Actor(new oTransform(), new oRigidBody(Orange->GetPhysics()));
	moon->AddComponent(new ShapeComponent(10, 6, sf::Color::Blue));
	//moon->AddComponent(new ScriptComponent("Assets/Scripts/ExampleScript.lua"));
	moon->GetTransform()->Translate(0, 0);
	moon->GetTransform()->Scale(1, 1);
	sun->AddChild(moon);
	//sun->position->Translate(50, 50);
	sun->GetTransform()->Rotate(90);*/

	Actor* star = new Actor(new oTransform(lua), new oRigidBody(Orange->GetPhysics()));

	star->AddComponent(new RectangleComponent(140, 100, sf::Color::Yellow,lua));
	star->AddComponent(new AudioComponent("Audio/file_example_WAV_1MG.wav"));
	star->AddComponent(new ScriptComponent("Audio/myScript.lua", lua));
	star->GetAudio()->PlayAudio();
	star->GetTransform()->Translate(-10, 0);
	star->SetMass(1000.f);
	star->GetRigidbody()->SetBounciness(.5f);
	
	//star->GetTransform()->Rotate(90.f);

	star->AddComponent(new RectangleComponent(40, 100, sf::Color::Yellow, lua));
	//star->Audio("Audio/file_example_WAV_1MG.wav");
	//sf::SoundBuffer  buffers;
	//sf::Sound sounds;
	//buffers.loadFromFile("Audio/file_example_WAV_1MG.wav");
	//sounds.setBuffer(buffers);
	//sounds.play();
	star->GetTransform()->Translate(100, 0);
	star->SetMass(0.1f);
	//star->GetInput()->GetKeyDown('D') ;
	//star->GetTransform()->Scale(0.5, 0.5);
	//moon->AddChild(star);
	//star->SetObeysGravity(false);

	Actor* platform = new Actor(new oTransform(lua), new oRigidBody(Orange->GetPhysics()));
	//platform->AddComponent(new ShapeComponent(300, 4, sf::Color::White));
	platform->AddComponent(new RectangleComponent(300, 40, sf::Color::White, lua));
	platform->GetTransform()->Translate(0, 300);
	platform->SetMass(1000.0f);
	//platform->GetTransform()->Scale(50, 4);
	platform->SetMass(0.f);
	platform->SetObeysGravity(false);
	//star->AddChild(platform);

	//Orange->AddActor(sun);
	//Orange->AddActor(moon);
	Orange->AddActor(star);
	Orange->AddActor(platform);

	//delete(sun);

	//delete(sun);
}



