
#include "LuaStateManager.h"
#include "_string.h"

#pragma comment(lib, "LuaPlus.lib")

LuaStateManager* LuaStateManager::s_pSingleton = NULL;

bool LuaStateManager::Create(void)
{
	if (s_pSingleton)
	{

		std::cout << "Overwriting LuaStateManager singleton" << std::endl;
		delete(s_pSingleton);
	}

	s_pSingleton = new LuaStateManager;
	if (s_pSingleton)
		return s_pSingleton->VInit();

	return false;
}

void LuaStateManager::Destroy(void)
{
	delete(s_pSingleton);
}

LuaStateManager::LuaStateManager(void)
{
	m_pLuaState = NULL;
}

LuaStateManager::~LuaStateManager(void)
{
	if (m_pLuaState)
	{
		LuaPlus::LuaState::Destroy(m_pLuaState);
		m_pLuaState = NULL;
	}
}

bool LuaStateManager::VInit(void)
{
	m_pLuaState = LuaPlus::LuaState::Create(true);
	if (m_pLuaState == NULL)
		return false;

	// register functions
	m_pLuaState->GetGlobals().RegisterDirect("ExecuteFile", (*this), &LuaStateManager::VExecuteFile);
	m_pLuaState->GetGlobals().RegisterDirect("ExecuteString", (*this), &LuaStateManager::VExecuteString);

	return true;
}

void LuaStateManager::VExecuteFile(const char* path)
{
	int result = m_pLuaState->DoFile(path);
	if (result != 0)
		SetError(result);
}

void LuaStateManager::VExecuteString(const char* chunk)
{
	int result = 0;

	// Most strings are passed straight through to the Lua interpreter
	if (strlen(chunk) <= 1 || chunk[0] != '=')
	{
		result = m_pLuaState->DoString(chunk);
		if (result != 0)
			SetError(result);
	}

	// If the string starts with '=', wrap the statement in the print() function.
	else
	{
		std::string buffer("print(");
		buffer += (chunk + 1);
		buffer += ")";
		result = m_pLuaState->DoString(buffer.c_str());
		if (result != 0)
			SetError(result);
	}
}

void LuaStateManager::SetError(int errorNum)
{
	// Note: If we get an error, we're hosed because LuaPlus throws an exception.  So if this function
	// is called and the error at the bottom triggers, you might as well pack it in.

	LuaPlus::LuaStackObject stackObj(m_pLuaState, -1);
	const char* errStr = stackObj.GetString();
	if (errStr)
	{
		m_lastError = errStr;
		ClearStack();
	}
	else
		m_lastError = "Unknown Lua parse error";

}

void LuaStateManager::ClearStack(void)
{
	m_pLuaState->SetTop(0);
}

LuaPlus::LuaObject LuaStateManager::GetGlobalVars(void)
{
	return m_pLuaState->GetGlobals();
}

LuaPlus::LuaState* LuaStateManager::GetLuaState(void) const
{
	return m_pLuaState;
}

LuaPlus::LuaObject LuaStateManager::CreatePath(const char* pathString, bool toIgnoreLastElement)
{
	StringVec splitPath;
	Split(pathString, splitPath, '.');
	if (toIgnoreLastElement)
		splitPath.pop_back();

	LuaPlus::LuaObject context = GetGlobalVars();
	for (auto it = splitPath.begin(); it != splitPath.end(); ++it)
	{
		// make sure we still have a valid context
		if (context.IsNil())
		{

			std::cout << "Something broke in CreatePath(); bailing out (element == " + (*it) + ")"<< std::endl;
			return context;  // this will be nil
		}

		// grab whatever exists for this element
		const std::string& element = (*it);
		LuaPlus::LuaObject curr = context.GetByName(element.c_str());

		if (!curr.IsTable())
		{
			// if the element is not a table and not nil, we clobber it
			if (!curr.IsNil())
			{
				std::cout << "Overwriting element"+ element + "' in table" << std::endl;
				context.SetNil(element.c_str());
			}

			// element is either nil or was clobbered so add the new table
			context.CreateTable(element.c_str());
		}

		context = context.GetByName(element.c_str());
	}

	// if we get here, we have created the path
	return context;
}

void LuaStateManager::ConvertVec2ToTable(const sf::Vector2f& vec, LuaPlus::LuaObject& outLuaTable) const
{
	outLuaTable.AssignNewTable(GetLuaState());
	outLuaTable.SetNumber("x", vec.x);
	outLuaTable.SetNumber("y", vec.y);
}


void LuaStateManager::ConvertTableToVec2(const LuaPlus::LuaObject& luaTable, sf::Vector2f& outVec2) const
{
	LuaPlus::LuaObject temp;

	// x
	temp = luaTable.Get("x");
	if (temp.IsNumber())
		outVec2.x = temp.GetFloat();
	else
		std::cout<<"luaTable.x is not a number"<<std::endl;

	// y
	temp = luaTable.Get("y");
	if (temp.IsNumber())
		outVec2.y = temp.GetFloat();
	else
		std::cout << "luaTable.y is not a number" << std::endl;


}

