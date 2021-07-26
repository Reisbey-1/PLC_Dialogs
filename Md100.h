// Md100.h : Deklaration von CMd100

#ifndef __MD100_H_
#define __MD100_H_

#include "resource.h"       // Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CMd100
class ATL_NO_VTABLE CMd100 : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CMd100, &CLSID_Md100>,
	public IDispatchImpl<IMd100, &IID_IMd100, &LIBID_DIALOGSLib>
{
public:
	CMd100();

DECLARE_REGISTRY_RESOURCEID(IDR_MD100)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CMd100)
	COM_INTERFACE_ENTRY(IMd100)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

protected:
	DPortLib::ISerialPort * m_pSerPort;
	DPortLib::_ISerialPortEvents  *m_pSink;
	
	BYTE *m_pszReceiveBuffer;//[1028];
	//BYTE m_szReceiveBuffer[LENGTH_DETEL_RECEIVE];

	int   m_nProcessor;

// IMd100
public:
	STDMETHOD(put_SinkBuffer)(/*[in]*/ BYTE ** newVal);
	STDMETHOD(put_Sink)(/*[in]*/ IDispatch** newVal);
	STDMETHOD(get_SerPort)(/*[out, retval]*/ IDispatch** pVal);
	STDMETHOD(put_SerPort)(/*[in]*/ IDispatch** newVal);
	STDMETHOD(Execute)(/*[in]*/ int hParent,int nProcessor);
};

#endif //__MD100_H_
