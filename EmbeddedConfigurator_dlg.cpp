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
		// HINWEIS: Der Klassen-Assistent f�gt hier Elementinitialisierung ein
	//}}AFX_DATA_INIT
}


void CEmbeddedConfigurator_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEmbeddedConfigurator_dlg)
		// HINWEIS: Der Klassen-Assistent f�gt hier DDX- und DDV-Aufrufe ein
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEmbeddedConfigurator_dlg, CDialog)
	//{{AFX_MSG_MAP(CEmbeddedConfigurator_dlg)
		// HINWEIS: Der Klassen-Assistent f�gt hier Zuordnungsmakros f�r Nachrichten ein
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen f�r Nachrichten CEmbeddedConfigurator_dlg 
