#include "mfc.h"
#include <iostream>
MyApp app;

BEGIN_MESSAGE_MAP(MyFrame,CFrameWnd)
	ON_WM_PAINT( )
END_MESSAGE_MAP()

BOOL MyApp::InitInstance()
{
	MyFrame *frame = new MyFrame;
	frame->ShowWindow(SW_NORMAL);
	frame->UpdateWindow();

	m_pMainWnd = frame;
	return TRUE;
}

MyFrame::MyFrame()
{
	Create(NULL,TEXT("MFC Window"));
}

void MyFrame::OnPaint()
{
	

	CPaintDC dc(this);

	// �ַ�����ش���
	// TEXT ����Ӧ����ת��
	// TCHAR ����Ӧ����ת��
//	MessageBox(L"Hello world");

	// ͳ���ַ�����
	char *p0 = "aaa";
	int num = strlen(p0);

	// ���ֽڳ���ͳ��
	wchar_t *pp00 = L"bbbbbb";
	num = wcslen(pp00);

	// CString char* String֮��ת�� char*������
	// 1.CString->char *
	CString str = L"liuxijiao���������";  
	wchar_t *pWChar = str.GetBuffer(); //��ȡstr�Ŀ��ַ������鱣��  
	str.ReleaseBuffer();  

	int nLen = str.GetLength(); //��ȡstr���ַ���  
	char *pChar = new char[nLen * 2 + 1];   
	memset(pChar, 0, nLen * 2 + 1);  
	int rtnVal = (int)wcstombs(pChar, pWChar, nLen * 2 + 1); //���ַ�ת��Ϊ���ֽ��ַ�  

	// 2.char *->string
	char *ch002 = "2.char *->string";
	std::string str002 = std::string(ch002);

	// 3.string->char *
	std::string str003 = "3.string->char *";
	char *ch003 = NULL;
	memset(ch003, 0, 100);
	strcpy(ch003, str003.c_str());
	
	// 4.char *->CString

	// 5.string->CString

	// 6.CString->string




	dc.TextOutW( 300, 300, ch003);
}

