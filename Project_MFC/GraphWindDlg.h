#pragma once

#include "afxwin.h"
#include "afxcmn.h"
#include <afxdialogex.h>

class CGraphWindDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGraphWindDlg)

public:
	CGraphWindDlg(CWnd* pParent = nullptr);   // Standard constructor
	virtual ~CGraphWindDlg();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GRAPH_WIND_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_ColorCombo;
	CSliderCtrl m_RadiusSlider;
	CButton m_LineTypeButton;

	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();

	COLORREF GetSelectedColor();
	int GetRadius();
	bool GetLineType();
};