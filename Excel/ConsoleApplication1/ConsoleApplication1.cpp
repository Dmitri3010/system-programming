// ConsoleApplication1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "iostream"
#include "../Excel/Header.h"

int main()
{
	std::cout << "Enter text in cell: ";
	wchar_t textInCell[256];
	std::wcin >> textInCell;
	OpenExcel(textInCell);
    return 0;
}