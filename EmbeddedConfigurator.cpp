// EmbeddedConfigurator.cpp : Implementierung von CEmbeddedConfigurator
#include "stdafx.h"
#include "Dialogs.h"
#include "EmbeddedConfigurator.h"
#include "EmbeddedConfigurator_dlg.h"

/////////////////////////////////////////////////////////////////////////////
// CEmbeddedConfigurator


STDMETHODIMP CEmbeddedConfigurator::Execute()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())
	
	CEmbeddedConfigurator_dlg dialog;
	dialog.DoModal(); 

	return S_OK;
}
