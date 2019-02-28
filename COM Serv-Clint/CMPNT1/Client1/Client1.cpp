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

void trace(const char* msg) { cout << "������ 1:\t" << msg << endl; }

IUnknown* CallCreateInstance(wchar_t* name)
{
	// ��������� � ������� ������������ ���������� 
	HINSTANCE hComponent = ::LoadLibrary(name);
	if (hComponent == NULL)
	{
		cout << "CallCreateInstance:\t������: �� ���� ��������� ���������"
			<< endl;
		return NULL;
	}

	// �������� ����� ������� CreateInstance 
	CREATEFUNCPTR CreateInstance
		= (CREATEFUNCPTR)::GetProcAddress(hComponent, "CreateInstance");
	if (CreateInstance == NULL)
	{
		cout << "CallCreateInstance:\t������: "
			<< "�� ���� ����� ������� CreateInstance"
			<< endl;
		return NULL;
	}

	return CreateInstance();
}
// 
// ������1 
// 

int main()
{
	setlocale(LC_ALL, "rus");
	HRESULT hr;

	// ������� ��� ����������    
	wchar_t name[40];
	cout << "������� ��� ����� ���������� [Cmpnt?.dll]: ";
	std::wcin >> name;
	cout << endl;

	// ������� ��������� ������� ������� CreateInstance �� DLL 
	trace("�������� ��������� �� IUnknown");
	IUnknown* pIUnknown = CallCreateInstance(name);
	if (pIUnknown == NULL)
	{
		trace("����� CallCreateInstance ��������");
		return 1;
	}

	trace("�������� ��������� IX");

	IX* pIX;
	//��������! ��� ��� ������ ���������� IUnknown!!!

	hr = pIUnknown->QueryInterface(IID_IX, (void**)&pIX);

	//pIX �������� ����� ���������� IX, ����������� ������� Fx()

	if (SUCCEEDED(hr))
	{
		trace("IX ������� �������");
		pIX->Fx();          // ������������ ��������� IX 
		pIX->FF();
		pIX->Release();
	}
	else
	{
		trace("�� ���� �������� ��������� IX");
	}

	trace("���������� ��������� IUnknown");
	pIUnknown->Release();

	return 0;
}
