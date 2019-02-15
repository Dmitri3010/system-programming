// MFCActiveXControl1PropPage.cpp: реализация класса страницы свойств CMFCActiveXControl1PropPage.

#include "stdafx.h"
#include "MFCActiveXControl1.h"
#include "MFCActiveXControl1PropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMFCActiveXControl1PropPage, COlePropertyPage)

// Схема сообщений

BEGIN_MESSAGE_MAP(CMFCActiveXControl1PropPage, COlePropertyPage)
END_MESSAGE_MAP()

// Инициализировать фабрика класса и guid

IMPLEMENT_OLECREATE_EX(CMFCActiveXControl1PropPage, "MFCACTIVEXCONT.MFCActiveXContPropPage.1",
	0xf21eaf74, 0x884, 0x4f9f, 0x9b, 0xd4, 0x3d, 0xc2, 0x81, 0x8, 0x35, 0xc7)

// CMFCActiveXControl1PropPage::CMFCActiveXControl1PropPageFactory::UpdateRegistry -
// Добавление или удаление записей системного реестра для CMFCActiveXControl1PropPage

BOOL CMFCActiveXControl1PropPage::CMFCActiveXControl1PropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_MFCACTIVEXCONTROL1_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CMFCActiveXControl1PropPage::CMFCActiveXControl1PropPage - Конструктор

CMFCActiveXControl1PropPage::CMFCActiveXControl1PropPage() :
	COlePropertyPage(IDD, IDS_MFCACTIVEXCONTROL1_PPG_CAPTION)
{
}

// CMFCActiveXControl1PropPage::DoDataExchange - перенос данных между страницей и свойствами

void CMFCActiveXControl1PropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// обработчики сообщений CMFCActiveXControl1PropPage
