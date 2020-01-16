#include "GameObject.h"



GameObject::GameObject()
{
	scene->AddChild(sun);
	sun->AddChild(earth);
	earth->AddChild(moon);
	
}


GameObject::~GameObject()
{
}
