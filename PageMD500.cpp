// PageMD100.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include <afxdlgs.h>
#include "resource.h"
#include "PageMD500.h"


/////////////////////////////////////////////////////////////////////////////
// Eigenschaftenseite CPageMD100 

IMPLEMENT_DYNCREATE(CPageMD500, CPropertyPage)

CPageMD500::CPageMD500() : CPropertyPage(CPageMD500::IDD)
{
	//{{AFX_DATA_INIT(CPageMD500)
		// HINWEIS: Der Klassen-Assistent f�gt hier Elementinitialisierung ein
	//}}AFX_DATA_INIT
}

CPageMD500::~CPageMD500()
{
}

void CPageMD500::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageMD500)
		// HINWEIS: Der Klassen-Assistent f�gt hier DDX- und DDV-Aufrufe ein
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPageMD500, CPropertyPage)
	//{{AFX_MSG_MAP(CPageMD500)
		// HINWEIS: Der Klassen-Assistent f�gt hier Zuordnungsmakros f�r Nachrichten ein
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen f�r Nachrichten CPageMD500 
