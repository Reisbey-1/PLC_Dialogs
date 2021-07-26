// MdxxMonitor.cpp : Implementierung von CMdxxMonitor
#include "stdafx.h"
#include "Dialogs.h"
#include "MdxxMonitor.h"
#include "MdxxMonitor_dlg.h"

/////////////////////////////////////////////////////////////////////////////
// CMdxxMonitor


STDMETHODIMP CMdxxMonitor::Execute(int hParent, int nVm)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	CMdxxMonitor_dlg dialog(CWnd::FromHandle((HWND)hParent));

	dialog.m_pISerPort	= m_pSerPort;
	dialog.m_pSink		= m_pSink;
	//dialog.m_pIFabric	= m_pIFabric;
	dialog.m_pIFabric	= NULL;



	dialog.m_nVm = nVm;
	dialog.DoModal();
/*

	CNonModalDlg<CMdxxMonitor_dlg> nmdMonitor(CWnd::FromHandle((HWND)hParent));
	nmdMonitor.m_pISerPort = m_pSerPort;
	nmdMonitor.m_nVm = nVm;
	nmdMonitor.DoModal();
*/

	return S_OK;

}

STDMETHODIMP CMdxxMonitor::put_Sink(IDispatch** newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	m_pSink = (DPortLib::ISerialSink*) (*newVal);
	return S_OK;
}


STDMETHODIMP CMdxxMonitor::put_SerPort(IDispatch **newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())
	//IDispatch * pDumy = newVal;
	m_pSerPort = (DPortLib::ISerialPort *) (*newVal);
	/*
	HRESULT hr = m_pSerPort->QueryInterface(DPORTLib::IID_ISerialPort, (void**) &m_pSerPort);

	if (hr == S_OK)
	{
		int n = m_pSerPort->Release();
	}
	*/
	return S_OK;
}

STDMETHODIMP CMdxxMonitor::put_Fabric(IDispatch **newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())
	m_pIFabric = (TelegramFabricLib::IFabric *) (*newVal);
/*
	HRESULT hr = m_pIFabric->QueryInterface(TelegramFabricLib::IID_IFabric, (void**) &m_pIFabric);
	if (hr == S_OK)
	{
		int n = m_pSerPort->Release();
	}
*/
	return S_OK;
}

