#include "Scene1.h"
#include <SFML/Graphics.hpp>
#include "ScriptingSystem.h"
#include "ShapeComponent.h"
#include "Transform.h"
#include "../../OrangeEngine.h"

Scene1::Scene1()
{
	
}


Scene1::~Scene1()
{
}

void Scene1::buildScene()
{
	OrangeEngine* Orange = OrangeEngine::GetInstance();

	Actor* sun = new Actor();
	sun->AddComponent(new ShapeComponent(10, 10, sf::Color::Red));
	sun->position->Translate(100, 0);
	sun->position->Scale(10, 10);

	Actor* moon = new Actor();
	moon->AddComponent(new ShapeComponent(10, 6, sf::Color::Blue));
	moon->position->Translate(0, 0);
	moon->position->Scale(0.3, 0.3);
	sun->AddChild(moon);
	//sun->position->Translate(50, 50);
	sun->position->Rotate(90);

	Actor* star = new Actor();
	star->AddComponent(new ShapeComponent(10, 5, sf::Color::Yellow));
	star->position->Translate(-0, -0);
	star->position->Scale(0.5, 0.5);
	moon->AddChild(star);

	Orange->AddActor(sun);
	Orange->AddActor(moon);
	Orange->AddActor(star);

	Orange->Run();
	delete(sun);

}
