// Md100.cpp : Implementierung von CMd100
#include "stdafx.h"
#include "Dialogs.h"
#include "Md100.h"
#include "Md100_dlg.h"

/////////////////////////////////////////////////////////////////////////////
// CMd100

CMd100::CMd100()
{
	m_pSerPort	= NULL;
	m_pSink		= NULL;
}


STDMETHODIMP CMd100::Execute(/*[in]*/ int hParent, /*[in]*/ int nProcessor)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

		CNonModalDlg<CMd100_dlg> dialog(NULL);
	//CNonModalDlg<CMd100_dlg> dialog;
	dialog.m_pISerPort = m_pSerPort;
	dialog.m_pSink= m_pSink;
	
	//dialog.m_szReceiveBuffer[LENGTH_DETEL_RECEIVE]; = m_pReceiveBuffer[LENGTH_DETEL_RECEIVE];//, 1028);
	
	///m_pszReceiveBuffer = dialog.m_szReceiveBuffer;// pointers points on dialogs buffer
	///m_pszReceiveBuffer = m_pSink->m_// pointers points on dialogs buffer

												  //memcpy(dialog.m_szReceiveBuffer, m_pszReceiveBuffer, LENGTH_DETEL_RECEIVE);
	dialog.m_nProcessor = nProcessor;
	dialog.DoModal();
	 

	return S_OK;
}

STDMETHODIMP CMd100::get_SerPort(IDispatch **pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// ZU ERLEDIGEN: Implementierungscode hier hinzufügen

	return S_OK;
}

STDMETHODIMP CMd100::put_SerPort(IDispatch **newVal)
{

	AFX_MANAGE_STATE(AfxGetStaticModuleState())
	IDispatch * pDumy = *newVal;
	HRESULT hr = pDumy->QueryInterface(DPortLib::IID_ISerialPort, (void**) &m_pSerPort);
	if (hr == S_OK)
	{
		int n = m_pSerPort->Release();
	}

	return S_OK;
}

STDMETHODIMP CMd100::put_Sink(IDispatch **newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	IDispatch * pDumy = *newVal;
	HRESULT hr = pDumy->QueryInterface(DPortLib::IID_ISerialSink, (void**) &m_pSink);
	if (hr == S_OK)
	{
		int n = m_pSink->Release();
	}

	return S_OK;
}




STDMETHODIMP CMd100::put_SinkBuffer(BYTE **newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	//m_pReceiveBuffer = (BYTE*)*newVal;
		m_pszReceiveBuffer = (BYTE*)*newVal;

	//memcpy(m_szReceiveBuffer, &newVal, LENGTH_DETEL_RECEIVE);

	return S_OK;
}

