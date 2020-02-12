#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/System/Vector2.hpp"
#include "LuaPlus.h"
#include "_string.h"


class IScriptManager
{
public:
	virtual ~IScriptManager(void) {}
	virtual bool VInit(void) = 0;
	virtual void VExecuteFile(const char* resource) = 0;
	virtual void VExecuteString(const char* str) = 0;
};

//---------------------------------------------------------------------------------------------------------------------
// LuaStateManager                              - Chapter 12, page 367
//---------------------------------------------------------------------------------------------------------------------
class LuaStateManager : public IScriptManager
{
	static LuaStateManager* s_pSingleton;
	LuaPlus::LuaState* m_pLuaState;
	std::string m_lastError;

public:
	// Singleton functions
	static bool Create(void);
	static void Destroy(void);
	static LuaStateManager* Get(void) { return s_pSingleton; }

	// IScriptManager interface
	virtual bool VInit(void) override;
	virtual void VExecuteFile(const char* resource) override;
	virtual void VExecuteString(const char* str) override;

	LuaPlus::LuaObject GetGlobalVars(void);
	LuaPlus::LuaState* GetLuaState(void) const;

	// public helpers
	LuaPlus::LuaObject CreatePath(const char* pathString, bool toIgnoreLastElement = false);
	void ConvertVec2ToTable(const sf::Vector2f& vec, LuaPlus::LuaObject& outLuaTable) const;
	void ConvertTableToVec2(const LuaPlus::LuaObject& luaTable, sf::Vector2f& outVec2) const;

private:
	void SetError(int errorNum);
	void ClearStack(void);

	// private constructor & destructor; call the static Create() and Destroy() functions instead
	explicit LuaStateManager(void);
	virtual ~LuaStateManager(void);
};

