
// InstallerDlg.h : header file
//

#pragma once


// CInstallerDlg dialog
class CInstallerDlg : public CDialogEx
{
// Construction
public:
	CInstallerDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INSTALLER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CCheckListBox m_checkListBox;

	CString platform_target_path = L"C:\\Program Files\\PineappleSoftware\\BCI App Platform";

	afx_msg void OnBnClickedButtonBrowse();
	afx_msg void OnBnClickedButton_PlatformInstall();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedAppInstall();

	BOOL Connect4_Flag;
	BOOL DaDa_Flag;
	BOOL BrainStompers_Flag;
	BOOL NeuroArcade_Flag;
	BOOL Travelink_Flag;
};
