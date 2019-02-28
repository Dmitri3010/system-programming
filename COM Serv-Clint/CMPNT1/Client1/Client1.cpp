// Client1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <objbase.h> 
//#include "Create.cpp"
#include "Iface.h" 

using namespace std;
typedef IUnknown* (*CREATEFUNCPTR)();


extern const IID IID_IX;
// {32bb8320-b41b-11cf-a6bb-0080c7b2d682} 
extern const IID IID_IX =
{ 0x32bb8320, 0xb41b, 0x11cf,
{0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x82} };

void trace(const char* msg) { cout << "Клиент 1:\t" << msg << endl; }

IUnknown* CallCreateInstance(wchar_t* name)
{
	// Загрузить в процесс динамическую библиотеку 
	HINSTANCE hComponent = ::LoadLibrary(name);
	if (hComponent == NULL)
	{
		cout << "CallCreateInstance:\tОшибка: Не могу загрузить компонент"
			<< endl;
		return NULL;
	}

	// Получить адрес функции CreateInstance 
	CREATEFUNCPTR CreateInstance
		= (CREATEFUNCPTR)::GetProcAddress(hComponent, "CreateInstance");
	if (CreateInstance == NULL)
	{
		cout << "CallCreateInstance:\tОшибка: "
			<< "Не могу найти функцию CreateInstance"
			<< endl;
		return NULL;
	}

	return CreateInstance();
}
// 
// Клиент1 
// 

int main()
{
	setlocale(LC_ALL, "rus");
	HRESULT hr;

	// Считать имя компонента    
	wchar_t name[40];
	cout << "Введите имя файла компонента [Cmpnt?.dll]: ";
	std::wcin >> name;
	cout << endl;

	// Создать компонент вызовом функции CreateInstance из DLL 
	trace("Получить указатель на IUnknown");
	IUnknown* pIUnknown = CallCreateInstance(name);
	if (pIUnknown == NULL)
	{
		trace("Вызов CallCreateInstance неудачен");
		return 1;
	}

	trace("Получить интерфейс IX");

	IX* pIX;
	//Внимание! Вот где клиент использует IUnknown!!!

	hr = pIUnknown->QueryInterface(IID_IX, (void**)&pIX);

	//pIX получает адрес интерфейса IX, содержащего функцию Fx()

	if (SUCCEEDED(hr))
	{
		trace("IX получен успешно");
		pIX->Fx();          // Использовать интерфейс IX 
		pIX->FF();
		pIX->Release();
	}
	else
	{
		trace("Не могу получить интерфейс IX");
	}

	trace("Освободить интерфейс IUnknown");
	pIUnknown->Release();

	return 0;
}
