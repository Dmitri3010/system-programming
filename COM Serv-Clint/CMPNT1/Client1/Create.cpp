#include "pch.h"
#include <iostream> 
#include <unknwn.h>    // Объявление IUnknown 

using namespace std;

typedef IUnknown* (*CREATEFUNCPTR)();
#ifdef UNICODE 
typedef wstring STRING;
#else
typedef string STRING;
#endif


