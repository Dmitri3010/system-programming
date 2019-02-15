// MFCActiveXControl1.cpp: реализаци€ CMFCActiveXControl1App и регистраци€ DLL.

#include "stdafx.h"
#include "MFCActiveXControl1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CMFCActiveXControl1App theApp;

const GUID CDECL _tlid = { 0x804CFE8, 0xDB55, 0x42FC, { 0x88, 0x82, 0x16, 0x98, 0x86, 0xF4, 0x46, 0x8A } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CMFCActiveXControl1App::InitInstance - инициализаци€ DLL

BOOL CMFCActiveXControl1App::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: ƒобавьте здесь свой код инициализации модул€.
	}

	return bInit;
}



// CMFCActiveXControl1App::ExitInstance - завершение DLL

int CMFCActiveXControl1App::ExitInstance()
{
	// TODO: ƒобавьте здесь свой код завершени€ работы модул€.

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - добавл€ет записи в системный реестр

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - удал€ет записи из системного реестра

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
