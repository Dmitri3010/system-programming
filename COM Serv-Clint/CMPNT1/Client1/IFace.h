#pragma once
#pragma once
#include <Windows.h>
interface IX : IUnknown
{
	virtual void __stdcall Fx() = 0;
	virtual void __stdcall FF() = 0;
	virtual void __stdcall Time() = 0;
};

