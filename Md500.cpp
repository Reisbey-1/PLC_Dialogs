// Md500.cpp : Implementierung von CMd500
#include "stdafx.h"
#include "Dialogs.h"
#include "Md500.h"

/////////////////////////////////////////////////////////////////////////////
// CMd500

CMd500::CMd500()
{
	m_pSerPort	= NULL;
	m_pSink		= NULL;
}



STDMETHODIMP CMd500::Execute(/*[in]*/ int hParent,/*[in]*/ int nProcessor)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

/*
	CMd500_dlg dialog(CWnd::FromHandle((HWND)hParent));
	dialog.m_pISerPort = m_pSerPort;
	dialog.m_pSink= m_pSink;
	dialog.m_nProcessor = nProcessor;
	dialog.m_pReceiveBuffer = m_pReceiveBuffer;//, 1028);
	dialog.DoModal();
*/
	CNonModalDlg<CMd500_dlg> dialog(CWnd::FromHandle((HWND)hParent));
	dialog.m_pISerPort = m_pSerPort;
	dialog.m_pSink= m_pSink;
	//dialog.m_pReceiveBuffer = m_pReceiveBuffer;//, 1028);
	memcpy(dialog.m_szReceiveBuffer, m_szReceiveBuffer, LENGTH_DETEL_RECEIVE);

	
	dialog.m_nProcessor = nProcessor;
	dialog.DoModal();

	return S_OK;
}



STDMETHODIMP CMd500::get_SerPort(IDispatch **pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// ZU ERLEDIGEN: Implementierungscode hier hinzufügen

	return S_OK;
}

STDMETHODIMP CMd500::put_SerPort(IDispatch **newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())
	IDispatch * pDumy = *newVal;
	HRESULT hr = pDumy->QueryInterface(DPortLib::IID_ISerialPort, (void**) &m_pSerPort);
	if (hr == S_OK)
	{
		int n = m_pSerPort->Release();
	}
	//m_pSerPort = (DPORTLib::ISerPort* ) pDumy;
	return S_OK;
}

STDMETHODIMP CMd500::put_Sink(IUnknown **newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	m_pSink = (DPortLib::_ISerialPortEvents*) (*newVal);
	return S_OK;
}

STDMETHODIMP CMd500::put_SinkBuffer(BYTE **newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// ZU ERLEDIGEN: Implementierungscode hier hinzufügen
	//memcpy(m_dialog.m_ReceiveBuffer, m_ReceiveBuffer, 1028);
	
	memcpy(m_szReceiveBuffer, *newVal, LENGTH_DETEL_RECEIVE);
	return S_OK;
}
