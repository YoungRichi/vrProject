#pragma once
enum Component_Definition
{
	Transform_Component,
	Render_Component,
	Audio_Component,
	Physics_Component,
	Script_Component,
	Default
};
struct ResourceHolder
{
	//image path
	std::string Fart = "Assets/Images/Fart.png";
	std::string RoadSign = "Assets/Images/RoadSign.png";
	std::string bird = "Assets/Images/bird.png";
	std::string Splash = "Assets/Images/SplashScreen.PNG";
	std::string background = "Assets/Images/background.png";

	//background music path
	std::string bgm = "Assets/Audio/MarioBackgroundMusic.wav";
	std::string hit = "Assets/Audio/Hit.ogg";

	//font path
	std::string ShadowBrush = "Assets/Font/Shadow Brush.otf";

	//script
	std::string Jump = "Assets/Script/Jump.lua";
};