#if !defined(AFX_EMBEDDEDCONFIGURATOR_DLG_H__E41284AC_8376_4EC7_89A5_3B603AA39D7B__INCLUDED_)
#define AFX_EMBEDDEDCONFIGURATOR_DLG_H__E41284AC_8376_4EC7_89A5_3B603AA39D7B__INCLUDED_

// _MSC_VER > 1000
// EmbeddedConfigurator_dlg.h : Header-Datei
//

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CEmbeddedConfigurator_dlg 

class CEmbeddedConfigurator_dlg : public CDialog
{
// Konstruktion
public:
	CEmbeddedConfigurator_dlg(CWnd* pParent = NULL);   // Standardkonstruktor

// Dialogfelddaten
	//{{AFX_DATA(CEmbeddedConfigurator_dlg)
	enum { IDD = IDD_DIALOG_EMBEDDED_32 };
		// HINWEIS: Der Klassen-Assistent f�gt hier Datenelemente ein
	//}}AFX_DATA


// �berschreibungen
	// Vom Klassen-Assistenten generierte virtuelle Funktions�berschreibungen
	//{{AFX_VIRTUAL(CEmbeddedConfigurator_dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterst�tzung
	//}}AFX_VIRTUAL

// Implementierung
protected:

	// Generierte Nachrichtenzuordnungsfunktionen
	//{{AFX_MSG(CEmbeddedConfigurator_dlg)
		// HINWEIS: Der Klassen-Assistent f�gt hier Member-Funktionen ein
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ f�gt unmittelbar vor der vorhergehenden Zeile zus�tzliche Deklarationen ein.

#endif // AFX_EMBEDDEDCONFIGURATOR_DLG_H__E41284AC_8376_4EC7_89A5_3B603AA39D7B__INCLUDED_
