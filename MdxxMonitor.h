// MdxxMonitor.h : Deklaration von CMdxxMonitor

#ifndef __MDXXMONITOR_H_
#define __MDXXMONITOR_H_

#include "resource.h"       // Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CMdxxMonitor
class ATL_NO_VTABLE CMdxxMonitor : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CMdxxMonitor, &CLSID_MdxxMonitor>,
	public IDispatchImpl<IMdxxMonitor, &IID_IMdxxMonitor, &LIBID_DIALOGSLib>
{
public:
	CMdxxMonitor()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_MDXXMONITOR)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CMdxxMonitor)
	COM_INTERFACE_ENTRY(IMdxxMonitor)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

protected:
	DPortLib::ISerialPort * m_pSerPort;
	DPortLib::ISerialSink *	m_pSink;
	TelegramFabricLib::IFabric * m_pIFabric ;

	
	IConnectionPoint* m_pConnectionPoint;
	
	// BYTE *m_pReceiveBuffer;//[LENGTH_DETEL_RECEIVE];
	BYTE m_szReceiveBuffer[LENGTH_DETEL_RECEIVE];
// IMdxxMonitor
public:
	STDMETHOD(put_Fabric)(/*[in]*/ IDispatch** newVal);
	STDMETHOD(put_Sink)(/*[in]*/ IDispatch** newVal);
	STDMETHOD(put_SerPort)(/*[in]*/ IDispatch** newVal);
	STDMETHOD(Execute)(/*[in]*/ int hParent,int nVm );
};

#endif //__MDXXMONITOR_H_
