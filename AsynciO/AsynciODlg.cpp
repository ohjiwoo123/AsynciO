
// AsynciODlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "AsynciO.h"
#include "AsynciODlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CAsynciODlg 대화 상자



CAsynciODlg::CAsynciODlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ASYNCIO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAsynciODlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAsynciODlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CAsynciODlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CAsynciODlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CAsynciODlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CAsynciODlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CAsynciODlg 메시지 처리기

BOOL CAsynciODlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CAsynciODlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CAsynciODlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CAsynciODlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

char strData[] =
"나룻배와 행인\r\n"
"			한용운\r\n"
"나는 나룻배\r\n"
"당신은 행인\r\n"
"당신은 흙발로 나를 짓밟습니다.\r\n"
"나는 당신을 안고 물을 건너갑니다.\r\n"
"나는 당신을 안으면 깊으나 얕으나 급한 여울이나 건너갑니다.\r\n"
"만일 당신이 아니 오시면 나는 바람을 쐬고 눈비를 맞으며\r\n"
"밤에서 낮까지 당신을 기다리고 있습니다.\r\n"
"당신은 물만 건너면 나를 보지도 않고 가십니다 그려.\r\n"
"그러나 당신이 언제든지 오실 줄만은 알아요.\r\n"
"나는 당신을 기다리면서 날마다 날마다 낡아 갑니다.\r\n"
"나는 나룻배\r\n"
"당신은 행인\r\n";

void CAsynciODlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 파일 저장
	// FILE_FLAG_OVERLAPPED 비동기로 개방 
	HANDLE hFile;
	DWORD dwWritten;
	

	// 비동기로 할 시 
	hFile = CreateFile(_T("c:\\temp\\event.txt"), GENERIC_WRITE,0,0,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_OVERLAPPED,0);

	OVERLAPPED ov1 = { 0, };
	ov1.Offset = (strlen(strData) * sizeof(char)) * 0;
	ov1.hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);

	OVERLAPPED ov2 = { 0, };
	ov2.Offset = (strlen(strData) * sizeof(char)) * 1;
	ov2.hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);

	OVERLAPPED ov3 = { 0, };
	ov3.Offset = (strlen(strData) * sizeof(char)) * 2;
	ov3.hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);

	BOOL bConnect = WriteFile(hFile, strData, sizeof(strData), &dwWritten, &ov1);
	bConnect = WriteFile(hFile, strData, sizeof(strData), &dwWritten, &ov2);
	bConnect = WriteFile(hFile, strData, sizeof(strData), &dwWritten, &ov3);
	// 동기로 할 시
	//hFile = CreateFile(_T("c:\\temp\\event.txt"), GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
	//BOOL bConnect = WriteFile(hFile, strData, sizeof(strData), &dwWritten, 0);
	CString strTemp;
	strTemp.Format(_T("1. 결과:%d, %d"), bConnect, dwWritten);
	AfxMessageBox(strTemp);

	HANDLE h[3] = { ov1.hEvent, ov2.hEvent, ov3.hEvent };

	// 기다려
	WaitForMultipleObjects(3, h, TRUE, INFINITE);

	//WaitForSingleObject(hFile, INFINITE);

	GetOverlappedResult(hFile, &ov1, &dwWritten, FALSE);
	strTemp.Format(_T("1. 결과:%d, %d"), bConnect, dwWritten);
	AfxMessageBox(strTemp);
	GetOverlappedResult(hFile, &ov2, &dwWritten, FALSE);
	strTemp.Format(_T("2. 결과:%d, %d"), bConnect, dwWritten);
	AfxMessageBox(strTemp);
	GetOverlappedResult(hFile, &ov3, &dwWritten, FALSE);
	strTemp.Format(_T("3. 결과:%d, %d"), bConnect, dwWritten);
	AfxMessageBox(strTemp);


	CloseHandle(hFile);
}

VOID WINAPI MyIOCPRoutine(DWORD errCode, DWORD dwByte, LPOVERLAPPED pOV)
{
	CString strTemp;
	strTemp.Format(_T("%s 완료 IO 결과완료 (바이트수:%d)"),pOV->hEvent, dwByte);
	AfxMessageBox(strTemp);
}

void CAsynciODlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	HANDLE hFile;
	DWORD dwWritten;

	// 비동기로 할 시 
	hFile = CreateFile(_T("c:\\temp\\callback.txt"), GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, 0);

	// BOOL bConnect = WriteFile(hFile, strData, sizeof(strData), &dwWritten, &ov1);
	OVERLAPPED ov1 = { 0, };
	ov1.Offset = (strlen(strData) * sizeof(char)) * 0;
	ov1.hEvent = (HANDLE)_T("겨울왕국");
	WriteFileEx(hFile, strData, sizeof(strData), &ov1, MyIOCPRoutine);
	//AfxMessageBox(_T("완료되었습니다."));

	OVERLAPPED ov2 = { 0, };
	ov2.Offset = (strlen(strData) * sizeof(char)) * 1;
	ov2.hEvent = (HANDLE)_T("여름왕국");
	WriteFileEx(hFile, strData, sizeof(strData), &ov2, MyIOCPRoutine);

	OVERLAPPED ov3 = { 0, };
	ov3.Offset = (strlen(strData) * sizeof(char)) * 3;
	ov3.hEvent = (HANDLE)_T("장화신은 고양이");
	WriteFileEx(hFile, strData, sizeof(strData), &ov3, MyIOCPRoutine);

	SleepEx(0, TRUE); // 알림 가능한 상태로 변경함 
	CloseHandle(hFile);
}

#define MEGA 1048576
HANDLE hBigFile;
DWORD len;
char* buf;
char* p;
HANDLE hEvent;

DWORD WINAPI MakeDataThread(LPVOID param)
{
	hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	buf = (char*)calloc(50, MEGA); // calloc = MEGA 사이즈를 50개 잡아주세요 
	if (buf == NULL)
	{
		AfxMessageBox(_T("메모리 할당을 실패했습니다."));
		return 0;
	}
	p = buf;
	char sTmp[256];
	int tlen;
	for (int i = 1;; i++)
	{
		/*w*/sprintf_s(sTmp, sizeof(sTmp), ("%dLine : this file is a test\r\n"), i);
		tlen = /*l*/strlen(sTmp);
		if (p - buf + tlen >= 50 * MEGA) break;
			strcpy_s(p, sizeof(sTmp), sTmp);
		///*l*/strcpy_s(p, sTmp);
		
		p += tlen;
	}
	len = p - buf;	// size 

	AfxMessageBox(_T("자료만들기를 완료했습니다."));
	SetEvent(hEvent);

	return 0;
}

// c:\\temp\\bigData.txt
#define _CRT_SECURE_NO_WARNINGS

DWORD WINAPI WriteDataThread(LPVOID param)
{
	WaitForSingleObject(hEvent, INFINITE);
	HANDLE hFile;
	DWORD dwWritten;
	hFile = CreateFile(_T("c:\\temp\\bigData.txt"), GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, 0);
	OVERLAPPED ov = { 0, };
	CString strTemp;
	WriteFile(hFile, buf, len, &dwWritten, &ov);
	WaitForSingleObject(hFile, INFINITE);
	AfxMessageBox(_T("파일쓰기를 완료했습니다."));
	CloseHandle(hFile);
	return 0;
}

void CAsynciODlg::OnBnClickedButton4()	// Big Data
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	DWORD id;
	// hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	// hBigFile = CreateThread(0, 0, MakeDataThread, 0, 0, &id);
	CreateThread(0, 0, MakeDataThread, 0, 0, &id);
	CreateThread(0, 0, WriteDataThread, 0, 0, &id);	//WriteFile();
	
}


void CAsynciODlg::OnBnClickedButton5()	// Copy
{
	//-----------------------------
	// 1. 원본파일 처리
	HANDLE hSrc;
	hSrc = CreateFile(_T("c:\\temp\\bigdata.txt"), GENERIC_READ,
		0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

	// 1) 사이즈를 구한다.
	LARGE_INTEGER llFileSize = { 0 };
	GetFileSizeEx(hSrc,&llFileSize);

	// 2) MMF를 구한다.
	// 1. 파일 매핑 객체를 생성한다.
	HANDLE hFMap = CreateFileMapping(hSrc, NULL, PAGE_READONLY, 0, 0, NULL);
	// 2. 파일 매핑 객체를 주소공간에 연결한다(파일뷰)
	BYTE* pBuf = (BYTE*)MapViewOfFile(hFMap, FILE_MAP_READ, 0, 0, 0);

	//-----------------------------
	// 2. 타겟파일 처리
	HANDLE hDestFile;
	hDestFile = CreateFile(_T("c:\\temp\\copycopy.txt"), GENERIC_READ | GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, 0);
	OVERLAPPED ov = { 0, };
	WriteFileEx(hDestFile, pBuf, llFileSize.QuadPart,&ov, MyIOCPRoutine);
	SleepEx(0, TRUE);

	//-----------------------------
	// 3. 뒷정리한다.
	UnmapViewOfFile(pBuf);
	CloseHandle(hFMap);
	CloseHandle(hSrc);
	CloseHandle(hDestFile);

}
