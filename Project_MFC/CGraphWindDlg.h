#pragma once

#include "afxwin.h"
#include "afxcmn.h"
#include <afxdialogex.h>
#include "Project_MFCDoc.h"

class CGraphWindDlg : public CDialogEx
{
    DECLARE_DYNAMIC(CGraphWindDlg)

public:
    CGraphWindDlg(CProjectMFCDoc* pDoc, CWnd* pParent = nullptr);   // Standard constructor
    virtual ~CGraphWindDlg();

    COLORREF m_Color;
    int m_Radius;
    bool m_LineType;

    void SetGraphSettings(COLORREF color, int radius, bool lineType);

    // Dialog Data
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_GRAPH_WIND_DIALOG };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);
    virtual BOOL OnInitDialog();

    DECLARE_MESSAGE_MAP()

public:
    CComboBox m_ColorCombo;
    CSliderCtrl m_RadiusSlider;
    CButton m_LineTypeButton;

    afx_msg void OnBnClickedOk();
    afx_msg void OnCbnSelchangeColorCombo();

    COLORREF GetSelectedColor();
    int GetRadius();
    bool GetLineType();

private:
    CProjectMFCDoc* m_pDoc;
};
