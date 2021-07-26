// IO28_dlg.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "resource.h"
#include "IO28_dlg.h"

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CIO28_dlg 


CIO28_dlg::CIO28_dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIO28_dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CIO28_dlg)
		// HINWEIS: Der Klassen-Assistent fügt hier Elementinitialisierung ein
	//}}AFX_DATA_INIT
}


void CIO28_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIO28_dlg)
		// HINWEIS: Der Klassen-Assistent fügt hier DDX- und DDV-Aufrufe ein
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CIO28_dlg, CDialog)
	//{{AFX_MSG_MAP(CIO28_dlg)
		// HINWEIS: Der Klassen-Assistent fügt hier Zuordnungsmakros für Nachrichten ein
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen für Nachrichten CIO28_dlg 
