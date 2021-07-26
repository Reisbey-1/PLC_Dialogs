#if !defined(AFX_PAGEMD100_H__DCCA9B58_D2D0_48DB_8CD8_68FAEF308289__INCLUDED_)
#define AFX_PAGEMD100_H__DCCA9B58_D2D0_48DB_8CD8_68FAEF308289__INCLUDED_

#include <afxdlgs.h>
// PageMD100.h : Header-Datei
//

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CPageMD100 

class CPageMD100 : public CPropertyPage
{
	DECLARE_DYNCREATE(CPageMD100)

// Konstruktion
public:
	CPageMD100();
	~CPageMD100();

// Dialogfelddaten
	//{{AFX_DATA(CPageMD100)
	enum { IDD = IDD_DIALOG_ME100_CONFIGURATION };
	//}}AFX_DATA


// Überschreibungen
	// Der Klassen-Assistent generiert virtuelle Funktionsüberschreibungen
	//{{AFX_VIRTUAL(CPageMD100)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:
	// Generierte Nachrichtenzuordnungsfunktionen
	//{{AFX_MSG(CPageMD100)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // AFX_PAGEMD100_H__DCCA9B58_D2D0_48DB_8CD8_68FAEF308289__INCLUDED_
