
// InstallerDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Installer.h"
#include "InstallerDlg.h"
#include "afxdialogex.h"

#include <cstdlib>
#include <atlstr.h>
#include <iostream>
#include <afxwin.h>
#include <thread>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CInstallerDlg dialog



CInstallerDlg::CInstallerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INSTALLER_DIALOG, pParent)
	, Connect4_Flag(FALSE)
	, DaDa_Flag(FALSE)
	, BrainStompers_Flag(FALSE)
	, NeuroArcade_Flag(FALSE)
	, Travelink_Flag(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CInstallerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK1, Connect4_Flag);
	DDX_Check(pDX, IDC_CHECK2, DaDa_Flag);
	DDX_Check(pDX, IDC_CHECK3, BrainStompers_Flag);
	DDX_Check(pDX, IDC_CHECK4, NeuroArcade_Flag);
	DDX_Check(pDX, IDC_CHECK5, Travelink_Flag);
}

BEGIN_MESSAGE_MAP(CInstallerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_BROWSE, &CInstallerDlg::OnBnClickedButtonBrowse)
	ON_BN_CLICKED(IDC_PLATFORM_INSTALL, &CInstallerDlg::OnBnClickedButton_PlatformInstall)
	ON_BN_CLICKED(IDC_CHECK1, &CInstallerDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_APP_INSTALL, &CInstallerDlg::OnBnClickedAppInstall)
END_MESSAGE_MAP()


// CInstallerDlg message handlers

BOOL CInstallerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon


	// TODO: Add extra initialization here
	GetDlgItem(IDC_PATH_PLATFORM)->SetWindowTextW(platform_target_path);
	SetWindowText(_T("BCI Application Platform Installer"));

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CInstallerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CInstallerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CInstallerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void installPlatform(CString target_path)
{

}

void CInstallerDlg::OnBnClickedButtonBrowse()
{
	CFolderPickerDialog  dlg; // TRUE for file selection, FALSE for folder selection

	if (dlg.DoModal() == IDOK)
	{
		CString filePath = dlg.GetPathName();
		filePath += "\\PineappleSoftware\\BCI App Platform";

		platform_target_path = filePath;
		GetDlgItem(IDC_PATH_PLATFORM)->SetWindowTextW(filePath);
	}
}


void CInstallerDlg::OnBnClickedButton_PlatformInstall()
{
	installPlatform(platform_target_path);
}


void CInstallerDlg::OnBnClickedCheck1()
{
	// TODO: Add your control notification handler code here
}

CString GetExecutableDirectory()
{
	TCHAR buffer[MAX_PATH];
	GetModuleFileName(nullptr, buffer, MAX_PATH);
	CString executablePath(buffer);

	int lastSeparatorIndex = executablePath.ReverseFind('\\');
	if (lastSeparatorIndex != -1)
	{
		CString executableDirectory = executablePath.Left(lastSeparatorIndex);
		return executableDirectory;
	}

	return _T("");
}

void CInstallerDlg::OnBnClickedAppInstall()
{
	CString executableDirectory = GetExecutableDirectory();
	_wchdir(executableDirectory);


	CString installerBatchFile = _T("installer.bat");
	CString arguments;

	UpdateData(TRUE);
	if (Connect4_Flag == TRUE) arguments += " c4";
	if (DaDa_Flag == TRUE) arguments += " da";
	if (BrainStompers_Flag == TRUE) arguments += " bs";
	if (Travelink_Flag == TRUE) arguments += " ta";
	if (NeuroArcade_Flag == TRUE) arguments += " na";

	CString command;
	command += _T(".\\");
	command += installerBatchFile;
	command += arguments;

	//AfxMessageBox(command); //DEBUG

	int result = _wsystem(command);

	if (result == 0) {
		// Success
		// Do nothing
	}
	else {
		// Ur a failure
		AfxMessageBox(_T("Could not execute installer.bat. Try redownloading the installer"));
	}
}
