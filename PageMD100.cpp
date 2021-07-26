// PageMD100.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "resource.h"
#include "PageMD100.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Eigenschaftenseite CPageMD100 

IMPLEMENT_DYNCREATE(CPageMD100, CPropertyPage)

CPageMD100::CPageMD100() : CPropertyPage(CPageMD100::IDD)
{
	//{{AFX_DATA_INIT(CPageMD100)
		// HINWEIS: Der Klassen-Assistent fügt hier Elementinitialisierung ein
	//}}AFX_DATA_INIT
}

CPageMD100::~CPageMD100()
{
}

void CPageMD100::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageMD100)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPageMD100, CPropertyPage)
	//{{AFX_MSG_MAP(CPageMD100)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()




/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen für Nachrichten CPageMD100 

