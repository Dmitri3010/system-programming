#include "pch.h"
#include <iostream> 
#include <unknwn.h>    // ���������� IUnknown 

using namespace std;

typedef IUnknown* (*CREATEFUNCPTR)();
#ifdef UNICODE 
typedef wstring STRING;
#else
typedef string STRING;
#endif


