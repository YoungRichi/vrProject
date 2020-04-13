#include "../Unity/Unity.h"
#include "SystemInit.h"
#include "../Engine/OrangeEngine.h"


SystemInit::SystemInit()
{

}


bool SystemInit::Run()
{

	GCA = new GameCodeApp();
	if (GCA->InitInstance(proj) == false)
	{
		return false;
	}
	GCA->CheckStorage(checkSpace);
	GCA->CheckMemory(checkPhysMem, checkVirtualMem);
	GCA->ReadCPUSpeed();
	GCA->CheckArchitecture();
	return true;
}
