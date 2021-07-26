#if !defined(AFX_DIALOGITEMVALUE_H__794C5E23_57F6_4196_95E2_3AA0F87D04F9__INCLUDED_)
#define AFX_DIALOGITEMVALUE_H__794C5E23_57F6_4196_95E2_3AA0F87D04F9__INCLUDED_


// DialogItemValue.h : Header-Datei
//

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CDialogItemValue 

class CDialogItemValue : public CDialog
{
// Konstruktion
public:
	CDialogItemValue(int nItemValueByte, CWnd* pParent = NULL);   // Standardkonstruktor

// Dialogfelddaten
	//{{AFX_DATA(CDialogItemValue)
	enum { IDD = IDD_DIALOG_LIST_ITEM };
	int		m_nItemValueByte;
	//}}AFX_DATA


// Überschreibungen
	// Vom Klassen-Assistenten generierte virtuelle Funktionsüberschreibungen
	//{{AFX_VIRTUAL(CDialogItemValue)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:

	// Generierte Nachrichtenzuordnungsfunktionen
	//{{AFX_MSG(CDialogItemValue)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
class CDialogItemValueWord : public CDialog
{
// Konstruktion
public:
	CDialogItemValueWord(int nItemValueByte, CWnd* pParent = NULL);   // Standardkonstruktor

// Dialogfelddaten
	//{{AFX_DATA(CDialogItemValueWord)
	enum { IDD = IDD_DIALOG_LIST_ITEM };
	int		m_nItemValueByte;
	//}}AFX_DATA


// Überschreibungen
	// Vom Klassen-Assistenten generierte virtuelle Funktionsüberschreibungen
	//{{AFX_VIRTUAL(CDialogItemValueWord)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:

	// Generierte Nachrichtenzuordnungsfunktionen
	//{{AFX_MSG(CDialogItemValueWord)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // AFX_DIALOGITEMVALUE_H__794C5E23_57F6_4196_95E2_3AA0F87D04F9__INCLUDED_
