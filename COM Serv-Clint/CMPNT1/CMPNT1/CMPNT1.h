// CMPNT1.h : main header file for the CMPNT1 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CCMPNT1App
// See CMPNT1.cpp for the implementation of this class
//

class CCMPNT1App : public CWinApp
{
public:
	CCMPNT1App();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
