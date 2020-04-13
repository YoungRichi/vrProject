#include "../OrangeEngine/Include/Unity/Unity.h"
#include "../OrangeEngine/Include/Engine/OrangeEngine.h"
#include "../OrangeEngine/Include/System/SystemInit.h"
#include "../OrangeEngine/Include/ResourceManager/ResourceManager.h"
#include "../../Include/JsonLoader/JsonParser.h"
#include <string>

using namespace std;
void CreateGameObjects(OrangeEngine &engine);
ResourceHolder ResHolder;
int main()
{
	//Initializing system check
	SystemInit* systemInit = nullptr;
	systemInit = new SystemInit();

	JsonParser jsonParser;

	if (systemInit->Run() == false)
	{
		MessageBox(NULL, _T("Multiple Instances Running!"), _T("Orange Engine"), NULL);
		return 0;
	}
	delete systemInit;

	//Creating window
	OrangeEngine GAME_ENGINE;

	GAME_ENGINE.SetTinyXML();

	CreateGameObjects(GAME_ENGINE);

	GAME_ENGINE.InitWindow();

	return 0;
}

void CreateGameObjects(OrangeEngine &engine)
{
	

	engine.CreateObject("Time", -450, -350.0f);
	engine.SetTextureComponent("Time", sf::Vector2f(0, 0), sf::Color::White, "Time: ");

	engine.CreateObject("background");
	engine.SetTextureComponent("background", sf::Vector2f(1024, 720), sf::Color::White, "", ResHolder.background);
	engine.SetObjectParent("background", "Time");

	engine.CreateObject("Bird", -350.0f, -200.0f);
	engine.SetTextureComponent("Bird", sf::Vector2f(50.f, 50.0f), sf::Color::White, "", ResHolder.bird);
	engine.SetPhysicsComponent("Bird", 2.0f, true, sf::Vector2f(0.0f, 0.0f));
	engine.SetScriptComponent("Bird", ResHolder.Jump);
	engine.SetAudioComponent("Bird", ResHolder.bgm, true, true);

	engine.CreateObject("gameOver", -250, 0);
	engine.SetTextureComponent("gameOver", sf::Vector2f(0, 0), sf::Color::Red, "", "", 100);


	float xPos = 0.0f;
	float Dist_X = 250.0f;
	float velocity = -80.f;

	engine.CreateObject("3Cloud1", xPos+500, 0.0f);
	engine.SetTextureComponent("3Cloud1", sf::Vector2f(90.f, 90.f), sf::Color::White, "", ResHolder.Cloud);
	engine.SetPhysicsComponent("3Cloud1", 0.0f, false, sf::Vector2f(velocity, 0.0f));
	engine.SetScriptComponent("3Cloud1", ResHolder.MoveToLeft);
	engine.SetObjectParent("background", "3Cloud1");



	engine.CreateObject("3Cloud2", xPos+200, -180.0f);
	engine.SetTextureComponent("3Cloud2", sf::Vector2f(90.f, 90.f), sf::Color::White, "", ResHolder.Cloud);
	engine.SetPhysicsComponent("3Cloud2", 0.0f, false, sf::Vector2f(velocity, 0.0f));
	engine.SetScriptComponent("3Cloud2", ResHolder.MoveToLeft);
	engine.SetObjectParent("background", "3Cloud2");

	engine.CreateObject("3Cloud3", xPos+100, 100.0f);
	engine.SetTextureComponent("3Cloud3", sf::Vector2f(90.f, 90.f), sf::Color::White, "", ResHolder.Cloud);
	engine.SetPhysicsComponent("3Cloud3", 0.0f, false, sf::Vector2f(velocity, 0.0f));
	engine.SetScriptComponent("3Cloud3", ResHolder.MoveToLeft);
	engine.SetObjectParent("background", "3Cloud3");

	xPos += Dist_X;

	engine.CreateObject("3RoadSign1", xPos, 330.0f);
	engine.SetTextureComponent("3RoadSign1", sf::Vector2f(90.f, 300.0f), sf::Color::White, "", ResHolder.RoadSign);
	engine.SetPhysicsComponent("3RoadSign1", 100.0f, false, sf::Vector2f(velocity, 0.0f));
	engine.SetScriptComponent("3RoadSign1", ResHolder.MoveToLeft);
	

	engine.CreateObject("3ground1", 0.0, 330.0f);
	engine.SetTextureComponent("3ground1", sf::Vector2f(1100.0f, 90.f), sf::Color::White, "", ResHolder.ground);
	engine.SetPhysicsComponent("3ground1", 100.0f, false, sf::Vector2f(0.0, 0.0f));
	engine.SetObjectParent("background", "3ground1");


	engine.CreateObject("3ground2", 0.0, -330.0f);
	engine.SetTextureComponent("3ground2", sf::Vector2f(1100.0f, 90.f), sf::Color::White, "", ResHolder.ground);
	engine.SetPhysicsComponent("3ground2", 100.0f, false, sf::Vector2f(0.0, 0.0f));
	engine.SetObjectParent("background", "3ground2");

}