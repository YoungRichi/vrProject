#pragma once
#include "../Unity/Unity.h"
#include "../Components/Transform/TransformComponent.h"
#include "../Components/Render/RenderComponent.h"
#include "../Components/Audio/AudioComponent.h"
#include "../Components/BaseComponent.h"
#include "../Components/Script/ScriptComponent.h"
#include "../System/RigidBody/RigidBody.h"
#include "../System/Input/InputSystem.h"
#include "../ResourceManager/ResourceManager.h"
#include <unordered_map> 



class GameObject
{
public:
	GameObject(std::string GameObjectName);
	~GameObject();

	void AddChild(GameObject* Obj);
	GameObject* FindGameObject(std::string ObjectName);

	// Create Component
	void AddComponent(Component_Definition Component);

	// Get Component from list
	BaseComponent *GetComponent(Component_Definition ComponentName);

	void Update(sf::Time dt);
	void RenderGO(sf::RenderWindow &win);


private:
	std::string GameObjectTag;
	std::unordered_map<Component_Definition, BaseComponent*> m_ComponentMap;
	std::unordered_map<std::string, GameObject*> ChildrenMap;

protected:
	GameObject* parent;
	std::vector<GameObject*> children;

private:
	void AddRenderComponent();
	void AddAudioComponent();
	void AddRigidBody();
	void AddScriptComponent();
};

