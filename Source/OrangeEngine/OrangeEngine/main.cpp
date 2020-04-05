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

	engine.CreateObject("background");
	engine.SetTextureComponent("background", sf::Vector2f(1024, 720), sf::Color::White, "", ResHolder.background);

	engine.CreateObject("Player", -350.0f, -200.0f);
	engine.SetTextureComponent("Player", sf::Vector2f(50.f, 50.0f), sf::Color::White, "", ResHolder.bird);
	engine.SetPhysicsComponent("Player", 2.0f, true, sf::Vector2f(0.0f, 0.0f));
	engine.SetScriptComponent("Player", ResHolder.Jump);
	engine.SetAudioComponent("Player", ResHolder.bgm, true, true);
}