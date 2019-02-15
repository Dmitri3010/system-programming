// ActiveXCPP2.cpp: ���������� CActiveXCPP2App � ����������� DLL.

#include "stdafx.h"
#include "ActiveXCPP2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CActiveXCPP2App theApp;

const GUID CDECL _tlid = { 0x67889EA8, 0x65A0, 0x492E, { 0x89, 0xC6, 0x58, 0xF2, 0x82, 0x33, 0x7B, 0x47 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CActiveXCPP2App::InitInstance - ������������� DLL

BOOL CActiveXCPP2App::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: �������� ����� ���� ��� ������������� ������.
	}

	return bInit;
}



// CActiveXCPP2App::ExitInstance - ���������� DLL

int CActiveXCPP2App::ExitInstance()
{
	// TODO: �������� ����� ���� ��� ���������� ������ ������.

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - ��������� ������ � ��������� ������

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - ������� ������ �� ���������� �������

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
