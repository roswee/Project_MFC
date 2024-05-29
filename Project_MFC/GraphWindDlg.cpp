#include "pch.h"
#include "framework.h"
#include "Project_MFC.h"
#include "GraphWindDlg.h"
#include "afxdialogex.h"



IMPLEMENT_DYNAMIC(CGraphWindDlg, CDialogEx)

CGraphWindDlg::CGraphWindDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GRAPH_WIND_DIALOG, pParent)
{
}

CGraphWindDlg::~CGraphWindDlg()
{
}

void CGraphWindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COLOR_COMBO, m_ColorCombo);
	DDX_Control(pDX, IDC_RADIUS_SLIDER, m_RadiusSlider);
	DDX_Control(pDX, IDC_LINE_TYPE_BUTTON, m_LineTypeButton);
}

BEGIN_MESSAGE_MAP(CGraphWindDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CGraphWindDlg::OnBnClickedOk)
END_MESSAGE_MAP()

BOOL CGraphWindDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Initialize color combo box
	m_ColorCombo.AddString(_T("Red"));
	m_ColorCombo.AddString(_T("Green"));
	m_ColorCombo.AddString(_T("Blue"));
	m_ColorCombo.SetCurSel(0);

	// Initialize radius slider
	m_RadiusSlider.SetRange(1, 10);
	m_RadiusSlider.SetTicFreq(1);
	m_RadiusSlider.SetPos(5);

	// Initialize line type button (for simplicity, using checkbox to indicate line type)
	m_LineTypeButton.SetCheck(BST_CHECKED);

	return TRUE;  // return TRUE unless you set the focus to a control
}

void CGraphWindDlg::OnBnClickedOk()
{
	CDialogEx::OnOK();
}

COLORREF CGraphWindDlg::GetSelectedColor()
{
	int sel = m_ColorCombo.GetCurSel();
	switch (sel)
	{
	case 0:
		return RGB(255, 0, 0);  // Red
	case 1:
		return RGB(0, 255, 0);  // Green
	case 2:
		return RGB(0, 0, 255);  // Blue
	default:
		return RGB(0, 0, 0);    // Default to black
	}
}

int CGraphWindDlg::GetRadius()
{
	return m_RadiusSlider.GetPos();
}

bool CGraphWindDlg::GetLineType()
{
	return (m_LineTypeButton.GetCheck() == BST_CHECKED);
}
