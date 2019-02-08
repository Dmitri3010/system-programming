#include <iostream>
#include <objbase.h>

interface IX :IUnknown
{
	virtual void __stdcall Fx() = 0;
};

interface IY :IUnknown
{
	virtual void __stdcall Fy() = 0;
	virtual void __stdcall FF() = 0;
};