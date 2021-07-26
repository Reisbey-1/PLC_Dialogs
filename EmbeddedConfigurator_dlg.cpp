// EmbeddedConfigurator_dlg.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "resource.h"
#include "EmbeddedConfigurator_dlg.h"

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CEmbeddedConfigurator_dlg 


CEmbeddedConfigurator_dlg::CEmbeddedConfigurator_dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEmbeddedConfigurator_dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEmbeddedConfigurator_dlg)
		// HINWEIS: Der Klassen-Assistent fügt hier Elementinitialisierung ein
	//}}AFX_DATA_INIT
}


void CEmbeddedConfigurator_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEmbeddedConfigurator_dlg)
		// HINWEIS: Der Klassen-Assistent fügt hier DDX- und DDV-Aufrufe ein
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEmbeddedConfigurator_dlg, CDialog)
	//{{AFX_MSG_MAP(CEmbeddedConfigurator_dlg)
		// HINWEIS: Der Klassen-Assistent fügt hier Zuordnungsmakros für Nachrichten ein
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen für Nachrichten CEmbeddedConfigurator_dlg 
