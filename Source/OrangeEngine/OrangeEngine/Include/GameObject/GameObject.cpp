#include "GameObject.h"


GameObject::GameObject(std::string GameObjectName)
{
	parent = nullptr;

	GameObjectTag = GameObjectName;
	//All objects are created with default transform component
	TransformComponent *transformComponent = new TransformComponent();
	//Map component to gameobject component list
	m_ComponentMap[Transform_Component] = transformComponent;
}
GameObject::~GameObject()
{
	for (unsigned int i = 0; i < children.size(); i++)
	{
		delete children[i];
	}
}

void GameObject::AddChild(GameObject * Obj)
{
	ChildrenMap[Obj->GameObjectTag] = Obj;
	Obj->parent = this;
}

//Update Parent of game object
GameObject* GameObject::FindGameObject(std::string ObjectName)
{
	GameObject *ObjectReference = nullptr;

	if (this->GameObjectTag == ObjectName)
	{
		return this;
	}
	else if (ChildrenMap.size() > 0) //If this is not the game object we are looking for
	{
		try
		{
			ObjectReference = ChildrenMap.at(ObjectName); //Sneak Peek the map and see if object is there

			if (ObjectReference)
			{
				return ObjectReference;
			}

		}
		catch (...)
		{
			std::cout << "Object not found in " << this->GameObjectTag << std::endl;
		}

	}

	for (std::unordered_map<std::string, GameObject*>::iterator it = ChildrenMap.begin(); it != ChildrenMap.end(); ++it)
	{
		ObjectReference = it->second->FindGameObject(ObjectName);

		if (ObjectReference)
		{
			return ObjectReference;
		}
	}

	return ObjectReference;
}



//Add component to the game object
void GameObject::AddComponent(Component_Definition Component)
{
	switch (Component)
	{
	case Render_Component:
		AddRenderComponent();
		break;
	case Audio_Component:
		AddAudioComponent();
		break;
	case Physics_Component:
		AddRigidBody();
		break;
	case Script_Component:
		AddScriptComponent();
		break;
	default:
		break;
	}
}

// Return Component from list to access its members
BaseComponent *GameObject::GetComponent(Component_Definition ComponentName)
{
	if (m_ComponentMap[ComponentName])
		return m_ComponentMap[ComponentName];
}

//Update Game Objects in list and components
void GameObject::Update(sf::Time dt)
{
	if (m_ComponentMap[Physics_Component])
	{
		GetComponent(Transform_Component)->setPosition(m_ComponentMap[Physics_Component]->GetRigidBodyPosition());
	}

	//Update Transform Component if any
	if (parent)
		GetComponent(Transform_Component)->Update(dt, &parent->GetComponent(Transform_Component)->getWorldTransform());
	else
		GetComponent(Transform_Component)->Update(dt);


	for (std::unordered_map<std::string, GameObject*>::iterator it = ChildrenMap.begin(); it != ChildrenMap.end(); ++it)
	{
		it->second->Update(dt);
	}
}

//Specifically update the render component if any in the game object
void GameObject::RenderGO(sf::RenderWindow &win)
{
	//If Game Object has a render component, pass the object position and the render window to draw its content
	if (m_ComponentMap[Render_Component])
	{
		m_ComponentMap[Render_Component]->RenderObject(win, GetComponent(Transform_Component)->getWorldTransform());
	}

	for (std::unordered_map<std::string, GameObject*>::iterator it = ChildrenMap.begin(); it != ChildrenMap.end(); ++it)
	{
		it->second->RenderGO(win);
	}
}

void GameObject::AddRenderComponent()
{
	//If we already have a render component dont do anything
	if (m_ComponentMap[Render_Component])
		return;

	//Create Render Component that has default values
	RenderComponent *renderComponent = new RenderComponent();
	//Map component to gameobject component list
	m_ComponentMap[Render_Component] = renderComponent;
}

void GameObject::AddAudioComponent()
{
	//If we already have a Audio component dont do anything
	if (m_ComponentMap[Audio_Component])
		return;

	//Create Audio Component that has default values
	AudioComponent *audioComponent = new AudioComponent();
	//Map component to gameobject component list
	m_ComponentMap[Audio_Component] = audioComponent;
}

void GameObject::AddRigidBody()
{
	if (m_ComponentMap[Physics_Component])
		return;

	RigidBody *RigidBodyComponent = new RigidBody();

	//Map component to gameobject component list
	m_ComponentMap[Physics_Component] = RigidBodyComponent;
}

void GameObject::AddScriptComponent()
{
	if (m_ComponentMap[Script_Component])
		return;

	ScriptComponent* Script = new ScriptComponent();

	//Map component to gameobject component list
	m_ComponentMap[Script_Component] = Script;
}
