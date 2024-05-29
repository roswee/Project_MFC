
// Project_MFCDoc.h : interface of the CProjectMFCDoc class
//


#pragma once

#include "MyData.h"
#include "Except1.h"


class CProjectMFCDoc : public CDocument
{
protected: // create from serialization only
	CProjectMFCDoc() noexcept;
	DECLARE_DYNCREATE(CProjectMFCDoc)

// Attributes
public:
	MY_DATA* pDat;
	CExcept1App* pExcept;

// Operations
public:
	COLORREF m_Color;
	int m_Radius;
	bool m_LineType;

	void SetGraphSettings(COLORREF color, int radius, bool lineType);
	COLORREF GetColor() const { return m_Color; }
	int GetRadius() const { return m_Radius; }
	bool GetLineType() const { return m_LineType; }
// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CProjectMFCDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
