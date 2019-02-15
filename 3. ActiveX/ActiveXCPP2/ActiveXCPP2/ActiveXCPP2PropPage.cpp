// ActiveXCPP2PropPage.cpp: ���������� ������ �������� ������� CActiveXCPP2PropPage.

#include "stdafx.h"
#include "ActiveXCPP2.h"
#include "ActiveXCPP2PropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CActiveXCPP2PropPage, COlePropertyPage)

// ����� ���������

BEGIN_MESSAGE_MAP(CActiveXCPP2PropPage, COlePropertyPage)
END_MESSAGE_MAP()

// ���������������� ������� ������ � guid

IMPLEMENT_OLECREATE_EX(CActiveXCPP2PropPage, "ACTIVEXCPP2.ActiveXCPP2PropPage.1",
	0x5be7bfed, 0x602a, 0x45c7, 0x9c, 0x9e, 0x32, 0xc8, 0x7d, 0xa7, 0x9, 0x27)

// CActiveXCPP2PropPage::CActiveXCPP2PropPageFactory::UpdateRegistry -
// ���������� ��� �������� ������� ���������� ������� ��� CActiveXCPP2PropPage

BOOL CActiveXCPP2PropPage::CActiveXCPP2PropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_ACTIVEXCPP2_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CActiveXCPP2PropPage::CActiveXCPP2PropPage - �����������

CActiveXCPP2PropPage::CActiveXCPP2PropPage() :
	COlePropertyPage(IDD, IDS_ACTIVEXCPP2_PPG_CAPTION)
{
}

// CActiveXCPP2PropPage::DoDataExchange - ������� ������ ����� ��������� � ����������

void CActiveXCPP2PropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// ����������� ��������� CActiveXCPP2PropPage
