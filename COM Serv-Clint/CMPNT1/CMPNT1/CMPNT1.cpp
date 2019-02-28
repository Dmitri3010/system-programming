// CMPNT1.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "CMPNT1.h"
#include <iostream> 
#include <objbase.h> 
#include "IFace.h"
//#include "windows.h"
//#include "GUID.cpp"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif

extern const IID IID_IX;
// {32bb8320-b41b-11cf-a6bb-0080c7b2d682} 
extern const IID IID_IX =
{ 0x32bb8320, 0xb41b, 0x11cf,
{0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x82} };


// CCMPNT1App

BEGIN_MESSAGE_MAP(CCMPNT1App, CWinApp)
END_MESSAGE_MAP()


// CCMPNT1App construction

CCMPNT1App::CCMPNT1App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CCMPNT1App object

CCMPNT1App theApp;


// CCMPNT1App initialization

BOOL CCMPNT1App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
void trace(const char* msg) { printf(msg); }

// 
// Компонент 
// 
class CA : public IX
{
	// Реализация IUnknown 
	virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv);
	virtual ULONG __stdcall AddRef();
	virtual ULONG __stdcall Release();

	// Реализация интерфейса IX 
	virtual void __stdcall Fx() { printf("Call Fx()!"); }
	virtual void __stdcall FF() {
		int x, y;
		printf("enter x");
		std::cin >> x;
		printf("enter y");
		std::cin >> y;
		std::cout << "x+y=" << x + y;
	}

public:
	// Конструктор 
	CA() : m_cRef(0) {}

	// Деструктор 
	~CA() { trace("Ликвидировать себя"); }

private:
	long m_cRef;
};


HRESULT __stdcall CA::QueryInterface(const IID& iid, void** ppv)
{
	if (iid == IID_IUnknown)
	{
		trace("Возвратить указатель на IUnknown");
		*ppv = static_cast<IX*>(this);
	}
	else if (iid == IID_IX)
	{
		trace("Возвратить указатель на IX");
		*ppv = static_cast<IX*>(this);
	}
	else
	{
		trace("Интерфейс не поддерживается");
		*ppv = NULL;
		return E_NOINTERFACE;
	}
	reinterpret_cast<IUnknown*>(*ppv)->AddRef();
	return S_OK;
}

ULONG __stdcall CA::AddRef()
{
	return InterlockedIncrement(&m_cRef);
}

ULONG __stdcall CA::Release()
{
	if (InterlockedDecrement(&m_cRef) == 0)
	{
		delete this;
		return 0;
	}
	return m_cRef;
}

// 
// Функция создания 
// 
extern "C" IUnknown* CreateInstance()
{
	IUnknown* pI = static_cast<IX*>(new CA);
	pI->AddRef();
	return pI;
}
