// MFCActiveXControl1Ctrl.cpp: реализация класса CMFCActiveXControl1Ctrl элемента ActiveX.

#include "stdafx.h"
#include "MFCActiveXControl1.h"
#include "MFCActiveXControl1Ctrl.h"
#include "MFCActiveXControl1PropPage.h"
#include "afxdialogex.h"

#define M_PI 3.1415926535897932384626433832795

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMFCActiveXControl1Ctrl, COleControl)

// Схема сообщений

BEGIN_MESSAGE_MAP(CMFCActiveXControl1Ctrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// Схема подготовки к отправке

BEGIN_DISPATCH_MAP(CMFCActiveXControl1Ctrl, COleControl)
	DISP_FUNCTION_ID(CMFCActiveXControl1Ctrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CMFCActiveXControl1Ctrl, "TestMyMethod",DISPID_TEST_METHOD, TestMyMethod,VT_I4, VTS_I4 VTS_I4 VTS_BSTR)
END_DISPATCH_MAP()

// Схема событий

BEGIN_EVENT_MAP(CMFCActiveXControl1Ctrl, COleControl)
	EVENT_CUSTOM_ID("EventHandlerTest", eventidEventHandlerTest, EventHandlerTest, VTS_BSTR VTS_BSTR VTS_I4)
END_EVENT_MAP()

// Страницы свойств

// TODO: при необходимости добавьте дополнительные страницы свойств.  Не забудьте увеличить значение счетчика.
BEGIN_PROPPAGEIDS(CMFCActiveXControl1Ctrl, 1)
	PROPPAGEID(CMFCActiveXControl1PropPage::guid)
END_PROPPAGEIDS(CMFCActiveXControl1Ctrl)

// Инициализировать фабрику класса и guid

IMPLEMENT_OLECREATE_EX(CMFCActiveXControl1Ctrl, "MFCACTIVEXCONTRO.MFCActiveXControCtrl.1",
	0xd41da606, 0x3f8d, 0x4d4a, 0x85, 0xd5, 0xc7, 0xf, 0xd5, 0xde, 0xc0, 0xff)

// Введите ИД и версию библиотеки

IMPLEMENT_OLETYPELIB(CMFCActiveXControl1Ctrl, _tlid, _wVerMajor, _wVerMinor)

// ИД интерфейса

const IID IID_DMFCActiveXControl1 = { 0x6046BDAF, 0x7F4E, 0x44FF, { 0x95, 0xCB, 0xA, 0xB3, 0x32, 0xFB, 0xD2, 0x6 } };
const IID IID_DMFCActiveXControl1Events = { 0x9EDEA2EE, 0xC23E, 0x4BB4, { 0x9C, 0xDA, 0x59, 0x4, 0x3C, 0x9, 0xC9, 0x45 } };

// Сведения о типах элементов управления

static const DWORD _dwMFCActiveXControl1OleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CMFCActiveXControl1Ctrl, IDS_MFCACTIVEXCONTROL1, _dwMFCActiveXControl1OleMisc)

// CMFCActiveXControl1Ctrl::CMFCActiveXControl1CtrlFactory::UpdateRegistry -
// Добавление или удаление записей системного реестра для CMFCActiveXControl1Ctrl

BOOL CMFCActiveXControl1Ctrl::CMFCActiveXControl1CtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: убедитесь, что элементы управления следуют правилам модели изолированных потоков.
	// Дополнительные сведения см. в MFC TechNote 64.
	// Если элемент управления не соответствует правилам модели изоляции, то
	// необходимо модифицировать приведенный ниже код, изменив значение 6-го параметра с
	// afxRegApartmentThreading на 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_MFCACTIVEXCONTROL1,
			IDB_MFCACTIVEXCONTROL1,
			afxRegApartmentThreading,
			_dwMFCActiveXControl1OleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CMFCActiveXControl1Ctrl::CMFCActiveXControl1Ctrl - Конструктор

CMFCActiveXControl1Ctrl::CMFCActiveXControl1Ctrl()
{
	InitializeIIDs(&IID_DMFCActiveXControl1, &IID_DMFCActiveXControl1Events);
	// TODO: Инициализируйте здесь данные экземпляра элемента управления.
}

// CMFCActiveXControl1Ctrl::~CMFCActiveXControl1Ctrl - Деструктор

CMFCActiveXControl1Ctrl::~CMFCActiveXControl1Ctrl()
{
	// TODO: Выполните здесь очистку данных экземпляра элемента управления.
}

// CMFCActiveXControl1Ctrl::OnDraw - функция рисования

void CMFCActiveXControl1Ctrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO: Замените следующий код собственным кодом рисования.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// CMFCActiveXControl1Ctrl::DoPropExchange - поддержка сохранения

void CMFCActiveXControl1Ctrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Вызывать функции PX_ для каждого постоянного настраиваемого свойства.
}


// CMFCActiveXControl1Ctrl::OnResetState - сброс элемента управления к состоянию по умолчанию

void CMFCActiveXControl1Ctrl::OnResetState()
{
	COleControl::OnResetState();  // Сбрасывает значения по умолчанию, найденные в DoPropExchange

	// TODO: Сбросьте здесь состояние любого другого элемента управления.
}


// CMFCActiveXControl1Ctrl::AboutBox - показывает пользователю панель "О программе"

void CMFCActiveXControl1Ctrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_MFCACTIVEXCONTROL1);
	dlgAbout.DoModal();
}

LONG CMFCActiveXControl1Ctrl::TestMyMethod(LONG param1, LONG param2, BSTR param3)
{
	return M_PI*(param1*param1);
}

// обработчики сообщений CMFCActiveXControl1Ctrl
