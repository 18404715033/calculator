
// calculatorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "afxdialogex.h"
#include "iostream"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcalculatorDlg 对话框




CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CcalculatorDlg::IDD, pParent)
	, m_str(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_str);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_1, &CcalculatorDlg::OnBnClicked1)
	ON_BN_CLICKED(IDC_2, &CcalculatorDlg::OnBnClicked2)
	ON_BN_CLICKED(IDC_3, &CcalculatorDlg::OnBnClicked3)
	ON_BN_CLICKED(IDC_4, &CcalculatorDlg::OnBnClicked4)
	ON_BN_CLICKED(IDC_DOT, &CcalculatorDlg::OnBnClickedDot)
	ON_BN_CLICKED(IDC_clear, &CcalculatorDlg::OnBnClickedclear)
	ON_BN_CLICKED(IDC_ADD, &CcalculatorDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_dengyu, &CcalculatorDlg::OnBnClickeddengyu)
	ON_BN_CLICKED(IDC_reduce, &CcalculatorDlg::OnBnClickedreduce)
	ON_BN_CLICKED(IDC_ride, &CcalculatorDlg::OnBnClickedride)
	ON_BN_CLICKED(IDC_divide, &CcalculatorDlg::OnBnClickeddivide)
	ON_BN_CLICKED(IDC_0, &CcalculatorDlg::OnBnClicked0)
	ON_BN_CLICKED(IDC_10, &CcalculatorDlg::OnBnClicked10)
	ON_BN_CLICKED(IDC_6, &CcalculatorDlg::OnBnClicked6)
	ON_BN_CLICKED(IDC_7, &CcalculatorDlg::OnBnClicked7)
	ON_BN_CLICKED(IDC_8, &CcalculatorDlg::OnBnClicked8)
	ON_BN_CLICKED(IDC_9, &CcalculatorDlg::OnBnClicked9)
	ON_BN_CLICKED(IDC_clear2, &CcalculatorDlg::OnBnClickedclear2)
	ON_BN_CLICKED(IDC_clear3, &CcalculatorDlg::OnBnClickedclear3)
	ON_BN_CLICKED(IDC_clear4, &CcalculatorDlg::OnBnClickedclear4)
	ON_BN_CLICKED(IDC_clear5, &CcalculatorDlg::OnBnClickedclear5)
	ON_BN_CLICKED(IDC_clear6, &CcalculatorDlg::OnBnClickedclear6)
	ON_BN_CLICKED(IDC_clear7, &CcalculatorDlg::OnBnClickedclear7)
	ON_BN_CLICKED(IDC_clear8, &CcalculatorDlg::OnBnClickedclear8)
END_MESSAGE_MAP()


// CcalculatorDlg 消息处理程序

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CcalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CcalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcalculatorDlg::OnBnClicked1()
{
	// TODO: 在此添加控件通知处理程序代码
	//UpdateData(true);
	if(flag2==1)
	{
		OnBnClickedclear();
        UpdateData(false);
		flag2=0;
	}
	m_str=m_str+L"1";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked2()
{
	// TODO: 在此添加控件通知处理程序代码
	//UpdateData(true);
	if(flag2==1)
	{
		OnBnClickedclear();
        UpdateData(false);
		flag2=0;
	}
	m_str=m_str+L"2";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked3()
{
	// TODO: 在此添加控件通知处理程序代码
	//UpdateData(true);
	if(flag2==1)
	{
		OnBnClickedclear();
        UpdateData(false);
		flag2=0;
	}
	m_str=m_str+L"3";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked4()
{
	// TODO: 在此添加控件通知处理程序代码
	//UpdateData(true);
	if(flag2==1)
	{
		OnBnClickedclear();
        UpdateData(false);
		flag2=0;
	}
	m_str=m_str+L"4";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedDot()
{
	// TODO: 在此添加控件通知处理程序代码
	//UpdateData(true);
	if(m_str.Find(L".")==-1)
		m_str=m_str+L".";
	//m_str=m_str+L".";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedclear()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str="";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	flag=1;
	UpdateData(true);
	temp=_ttof(m_str);
	UpdateData(false);
	m_str="";
}


void CcalculatorDlg::OnBnClickeddengyu()
{
	// TODO: 在此添加控件通知处理程序代码
	//TRACE(L"****         %lf\n",temp);
	//UpdateData(true);
	if(flag==1)
    {
		temp=temp+_ttof(m_str);
	}
	 else
	{
		if(flag==2)
	    {
			temp=temp-_ttof(m_str);
	    }
		else
		{
			if(flag==3)
			{
				temp=temp*_ttof(m_str);
			}
			else
			{
				if(_ttof(m_str)==0)
				{
					//temp=temp/_ttof(m_str);
					OnBnClickedclear();
					MessageBox(L"Worry!Retry.");
				}
				else
				{
					//OnBnClickedclear();
					//MessageBox(L"Worry!Retry.");
					if(flag==4)
					{
						temp=temp/_ttof(m_str);
					}
					else
					{
						temp=_ttof(m_str);
					}
				}
			}
		}
	}
	flag2=1;
	flag=0;
	m_str.Format(L"%lf",temp);
	m_str.Right(1)=="0";
	m_str.Delete(m_str.GetLength()-4,7);
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedreduce()
{
	// TODO: 在此添加控件通知处理程序代码
	flag=2;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedride()
{
	// TODO: 在此添加控件通知处理程序代码
	flag=3;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickeddivide()
{
	// TODO: 在此添加控件通知处理程序代码
	flag=4;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	//UpdateData(false);
}


void CcalculatorDlg::OnBnClicked0()
{
	// TODO: 在此添加控件通知处理程序代码
	//UpdateData(true);
	if(flag2==1)
	{
		OnBnClickedclear();
        UpdateData(false);
		flag2=0;
	}
	m_str=m_str+L"0";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked10()
{
	// TODO: 在此添加控件通知处理程序代码
	//UpdateData(true);
	if(flag2==1)
	{
		OnBnClickedclear();
        UpdateData(false);
		flag2=0;
	}
	m_str=m_str+L"5";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked6()
{
	// TODO: 在此添加控件通知处理程序代码
	//UpdateData(true);
	if(flag2==1)
	{
		OnBnClickedclear();
        UpdateData(false);
		flag2=0;
	}
	m_str=m_str+L"6";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked7()
{
	// TODO: 在此添加控件通知处理程序代码
	//UpdateData(true);
	if(flag2==1)
	{
		OnBnClickedclear();
        UpdateData(false);
		flag2=0;
	}
	m_str=m_str+L"7";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked8()
{
	// TODO: 在此添加控件通知处理程序代码
	//UpdateData(true);
	if(flag2==1)
	{
		OnBnClickedclear();
        UpdateData(false);
		flag2=0;
	}
	m_str=m_str+L"8";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked9()
{
	// TODO: 在此添加控件通知处理程序代码
	//UpdateData(true);
	if(flag2==1)
	{
		OnBnClickedclear();
        UpdateData(false);
		flag2=0;
	}
	m_str=m_str+L"9";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedclear2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str.Delete (m_str.GetLength()-1,1);
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedclear3()
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_str.Left(1)=="-")
	m_str.Delete(0,1);
	else
		m_str=L"-"+m_str;
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedclear4()
{
	// TODO: 在此添加控件通知处理程序代码
	if(_ttof(m_str)==0)
	{
		OnBnClickedclear();
		MessageBox(L"Worry!Retry.");
	}
	m_str.Format(L"%lf",temp*_ttof(m_str)/100);
	if(flag==1||flag==2||flag==3||flag==4)
	{

		if(flag==1)
    {
		temp=temp+_ttof(m_str);
	}
	 else
	{
		if(flag==2)
	    {
			temp=temp-_ttof(m_str);
	    }
		else
		{
			if(flag==3)
			{
				temp=temp*_ttof(m_str);
			}
			else
			{
				if(_ttof(m_str)!=0)
				{
					temp=temp/_ttof(m_str);
				}
				else
				{
					OnBnClickedclear();
					MessageBox(L"Worry!Retry.");
				}
			}
		}
	}
	}
	//m_str.Format(L"%lf",temp*_ttof(m_str)/100);
	flag2=1;
	m_str.Format(L"%lf",temp);
	m_str.Right(1)=="0";
	m_str.Delete(m_str.GetLength()-4,7);
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedclear5()
{
	// TODO: 在此添加控件通知处理程序代码
	if(_ttof(m_str)==0)
	{
		OnBnClickedclear();
		MessageBox(L"Worry!Retry.");
	}
	m_str.Format(L"%lf",1.0/_ttof(m_str));//转化
	flag2=1;
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedclear6()
{
	// TODO: 在此添加控件通知处理程序代码
	if(_ttof(m_str)<0)
	{
		OnBnClickedclear();
		MessageBox(L"Worry!Retry.");
	}
	//m_str.Format(L"%lf",temp);
	temp=_ttof(m_str);
	double f =sqrt(temp);
	/*if(f-int(f)<= 102000000)
	{
		m_str.Format(L"%d",(int)f);
	}
	else
	{
		m_str.Format(L"%f",f);
	}*/
	flag2=1;
	m_str.Format(L"%f",f);
	m_str.Right(1)=="0";
	m_str.Delete(m_str.GetLength()-4,7);
	UpdateData(false);

}


void CcalculatorDlg::OnBnClickedclear7()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str.Format(L"%lf",_ttof(m_str)*_ttof(m_str));
	m_str.Right(1)=="0";
	m_str.Delete(m_str.GetLength()-4,7);
	flag2=1;
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedclear8()
{
	// TODO: 在此添加控件通知处理程序代码
	if(flag2==1)
	{
		OnBnClickedclear();
        UpdateData(false);
		flag2=0;
	}
	m_str=m_str+L"00";
	UpdateData(false);
}
