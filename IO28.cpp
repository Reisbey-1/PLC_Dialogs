// IO28.cpp : Implementierung von CIO28
#include "stdafx.h"
#include "Dialogs.h"
#include "IO28.h"

/////////////////////////////////////////////////////////////////////////////
// CIO28


STDMETHODIMP CIO28::Execute()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())
	
	CIO28_dlg dialog;
	dialog.DoModal(); 

	return S_OK;
}
