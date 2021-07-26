#if !defined(PAGEMD100_H_289__INCLUDED_)
#define PAGEMD100_H_289__INCLUDED_


// PageMD500.h : Header-Datei
//

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CPageMD100 

class CPageMD500 : public CPropertyPage
{
	DECLARE_DYNCREATE(CPageMD500)

// Konstruktion
public:
	CPageMD500();
	~CPageMD500();

// Dialogfelddaten
	//{{AFX_DATA(CPageMD500)
	enum { IDD = IDD_DIALOG_MD500_CONFIGURATION };
		// HINWEIS - Der Klassen-Assistent fügt hier Datenelemente ein.
		//    Innerhalb dieser generierten Quellcodeabschnitte NICHTS BEARBEITEN!
	//}}AFX_DATA


// Überschreibungen
	// Der Klassen-Assistent generiert virtuelle Funktionsüberschreibungen
	//{{AFX_VIRTUAL(CPageMD500)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:
	// Generierte Nachrichtenzuordnungsfunktionen
	//{{AFX_MSG(CPageMD500)
		// HINWEIS: Der Klassen-Assistent fügt hier Member-Funktionen ein
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // PAGEMD100_H_289__INCLUDED_
