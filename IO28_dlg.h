#if !defined(AFX_IO28_DLG_H__598980FA_8737_489C_8407_95B5816C9EEF__INCLUDED_)
#define AFX_IO28_DLG_H__598980FA_8737_489C_8407_95B5816C9EEF__INCLUDED_


// _MSC_VER > 1000
// IO28_dlg.h : Header-Datei
//

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CIO28_dlg 

class CIO28_dlg : public CDialog
{
// Konstruktion
public:
	CIO28_dlg(CWnd* pParent = NULL);   // Standardkonstruktor

// Dialogfelddaten
	//{{AFX_DATA(CIO28_dlg)
	enum { IDD = IDD_DIALOG_SLAVE_IO28 };
		// HINWEIS: Der Klassen-Assistent f�gt hier Datenelemente ein
	//}}AFX_DATA


// �berschreibungen
	// Vom Klassen-Assistenten generierte virtuelle Funktions�berschreibungen
	//{{AFX_VIRTUAL(CIO28_dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterst�tzung
	//}}AFX_VIRTUAL

// Implementierung
protected:
		// Generierte Nachrichtenzuordnungsfunktionen
	//{{AFX_MSG(CIO28_dlg)
		// HINWEIS: Der Klassen-Assistent f�gt hier Member-Funktionen ein
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ f�gt unmittelbar vor der vorhergehenden Zeile zus�tzliche Deklarationen ein.

#endif // AFX_IO28_DLG_H__598980FA_8737_489C_8407_95B5816C9EEF__INCLUDED_
