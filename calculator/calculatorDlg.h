
// calculatorDlg.h : ͷ�ļ�
//

#pragma once


// CcalculatorDlg �Ի���
class CcalculatorDlg : public CDialogEx
{
// ����
public:
	CcalculatorDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CALCULATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClicked1();
	afx_msg void OnBnClicked2();
	afx_msg void OnBnClicked3();
	afx_msg void OnBnClicked4();
	afx_msg void OnBnClickedDot();
	afx_msg void OnBnClickedclear();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickeddengyu();
	CString m_str;
	double temp;
	int flag;
	afx_msg void OnBnClickedreduce();
	afx_msg void OnBnClickedride();
	afx_msg void OnBnClickeddivide();
	afx_msg void OnBnClicked0();
	afx_msg void OnBnClicked10();
	afx_msg void OnBnClicked6();
	afx_msg void OnBnClicked7();
	afx_msg void OnBnClicked8();
	afx_msg void OnBnClicked9();
	afx_msg void OnBnClickedclear2();
	afx_msg void OnBnClickedclear3();
	afx_msg void OnBnClickedclear4();
	afx_msg void OnBnClickedclear5();
	afx_msg void OnBnClickedclear6();
	double f;
	int flag2;
	afx_msg void OnBnClickedclear7();
	afx_msg void OnBnClickedclear8();
};
