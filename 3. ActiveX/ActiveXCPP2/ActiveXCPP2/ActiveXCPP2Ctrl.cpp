// ActiveXCPP2Ctrl.cpp: реализация класса CActiveXCPP2Ctrl элемента ActiveX.

#include "stdafx.h"
#include "ActiveXCPP2.h"
#include "ActiveXCPP2Ctrl.h"
#include "ActiveXCPP2PropPage.h"
#include "afxdialogex.h"
#include <math.h>

#define M_PI 3.1415926535897932384626433832795

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CActiveXCPP2Ctrl, COleControl)



// Message map

BEGIN_MESSAGE_MAP(CActiveXCPP2Ctrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()



// Dispatch map

BEGIN_DISPATCH_MAP(CActiveXCPP2Ctrl, COleControl)
	DISP_FUNCTION_ID(CActiveXCPP2Ctrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)

	DISP_FUNCTION_ID(CActiveXCPP2Ctrl, "TestMyMethod",
		DISPID_TEST_METHOD, TestMyMethod,
		VT_I4, VTS_I4 VTS_I4 VTS_BSTR)


END_DISPATCH_MAP()



// Event map

BEGIN_EVENT_MAP(CActiveXCPP2Ctrl, COleControl)
	EVENT_CUSTOM_ID("EventHandlerTest", eventidEventHandlerTest, EventHandlerTest, VTS_BSTR VTS_BSTR VTS_I4)
END_EVENT_MAP()



// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CActiveXCPP2Ctrl, 1)
	PROPPAGEID(CActiveXCPP2PropPage::guid)
END_PROPPAGEIDS(CActiveXCPP2Ctrl)



// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CActiveXCPP2Ctrl, "ACTIVEXCPP2.ActiveXCPP2Ctrl.1",
	0x79956383, 0x66f5, 0x4671, 0x90, 0xb9, 0x62, 0x7, 0xc9, 0x89, 0x3b, 0x9f)



	// Type library ID and version

	IMPLEMENT_OLETYPELIB(CActiveXCPP2Ctrl, _tlid, _wVerMajor, _wVerMinor)



	// Interface IDs

	const IID IID_DActiveXCPP2 = { 0xB1F9D80, 0x811, 0x4B3D,{ 0xA0, 0x91, 0xF3, 0x3D, 0xE, 0x37, 0x86, 0xFC } };
const IID IID_DActiveXCPP2Events = { 0x421B2096, 0x8D11, 0x4871,{ 0xAD, 0x81, 0x58, 0x73, 0xDB, 0x31, 0x2B, 0xBA } };


// Control type information

static const DWORD _dwActiveXCPP2OleMisc =
OLEMISC_ACTIVATEWHENVISIBLE |
OLEMISC_SETCLIENTSITEFIRST |
OLEMISC_INSIDEOUT |
OLEMISC_CANTLINKINSIDE |
OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CActiveXCPP2Ctrl, IDS_ACTIVEXCPP2, _dwActiveXCPP2OleMisc)



// CActiveXCPP2Ctrl::CActiveXCPP2CtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CActiveXCPP2Ctrl

BOOL CActiveXCPP2Ctrl::CActiveXCPP2CtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_ACTIVEXCPP2,
			IDB_ACTIVEXCPP2,
			afxRegApartmentThreading,
			_dwActiveXCPP2OleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}



// CActiveXCPP2Ctrl::CActiveXCPP2Ctrl - Constructor

CActiveXCPP2Ctrl::CActiveXCPP2Ctrl()
{
	InitializeIIDs(&IID_DActiveXCPP2, &IID_DActiveXCPP2Events);
	// TODO: Initialize your control's instance data here.
}



// CActiveXCPP2Ctrl::~CActiveXCPP2Ctrl - Destructor

CActiveXCPP2Ctrl::~CActiveXCPP2Ctrl()
{
	// TODO: Cleanup your control's instance data here.
}



// CActiveXCPP2Ctrl::OnDraw - Drawing function

void CActiveXCPP2Ctrl::OnDraw(
	CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;

	// TODO: Replace the following code with your own drawing code.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}



// CActiveXCPP2Ctrl::DoPropExchange - Persistence support

void CActiveXCPP2Ctrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.
}



// CActiveXCPP2Ctrl::OnResetState - Reset control to default state

void CActiveXCPP2Ctrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

								  // TODO: Reset any other control state here.
}



// CActiveXCPP2Ctrl::AboutBox - Display an "About" box to the user

void CActiveXCPP2Ctrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_ACTIVEXCPP2);
	dlgAbout.DoModal();
}

LONG CActiveXCPP2Ctrl::TestMyMethod(LONG param1, LONG param2, BSTR param3)
{
	return M_PI*(param1*param1) ;
}
