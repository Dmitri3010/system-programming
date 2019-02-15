#define DISPID_TEST_METHOD (1025314) 
#pragma once

// ActiveXCPP2Ctrl.h: объявление класса элемента управления ActiveX для CActiveXCPP2Ctrl.


// CActiveXCPP2Ctrl: про реализацию см. ActiveXCPP2Ctrl.cpp.

#define DISPID_TEST_METHOD (1025314) //ДОБАВЛЕНО МНОЙ
#pragma once

// ActiveXCPP2Ctrl.h : Declaration of the CActiveXCPP2Ctrl ActiveX Control class.


// CActiveXCPP2Ctrl : See ActiveXCPP2Ctrl.cpp for implementation.

class CActiveXCPP2Ctrl : public COleControl
{
	DECLARE_DYNCREATE(CActiveXCPP2Ctrl)

	// Constructor
public:
	CActiveXCPP2Ctrl();

	// Overrides
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

	// Implementation
protected:
	~CActiveXCPP2Ctrl();

	DECLARE_OLECREATE_EX(CActiveXCPP2Ctrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CActiveXCPP2Ctrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CActiveXCPP2Ctrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CActiveXCPP2Ctrl)		// Type name and misc status

												// Message maps
	DECLARE_MESSAGE_MAP()

	// Dispatch maps
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();
	afx_msg LONG TestMyMethod(LONG param1, LONG param2, BSTR param3);//МНОЙ																	 // Event maps
	DECLARE_EVENT_MAP()
	// Dispatch and event IDs
public:          //Эти строки может создавать мастер ClassView
	enum {
		eventidEventHandlerTest = 1L
	};

protected:
	void EventHandlerTest(LPCTSTR name, LPCTSTR surname, LONG age)
	{
		FireEvent(eventidEventHandlerTest, EVENT_PARAM(VTS_BSTR VTS_BSTR VTS_I4), name, surname, age);
	}                      //ДОБАВЛЕНО МНОЙ
};
