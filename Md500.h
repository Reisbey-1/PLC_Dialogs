// Md500.h : Deklaration von CMd500

#ifndef __MD500_H_
#define __MD500_H_

#include "resource.h"       // Hauptsymbole
#include "Md500_dlg.h"

/////////////////////////////////////////////////////////////////////////////
// CMd500
class ATL_NO_VTABLE CMd500 : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CMd500, &CLSID_Md500>,
	public IDispatchImpl<IMd500, &IID_IMd500, &LIBID_DIALOGSLib>
{
public:
	CMd500();

DECLARE_REGISTRY_RESOURCEID(IDR_MD500)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CMd500)
	COM_INTERFACE_ENTRY(IMd500)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()
protected:
//	CMd500_dlg m_dialog;

	DPortLib::ISerialPort * m_pSerPort;
	DPortLib::_ISerialPortEvents  *m_pSink;
	
	//BYTE *m_pReceiveBuffer;//[1028];
	BYTE m_szReceiveBuffer[LENGTH_DETEL_RECEIVE];

	// IMd500
public:
	STDMETHOD(put_SinkBuffer)(/*[in]*/ BYTE** newVal);
	STDMETHOD(put_Sink)(/*[in]*/ IUnknown** newVal);
	STDMETHOD(get_SerPort)(/*[out, retval]*/ IDispatch* *pVal);
	STDMETHOD(put_SerPort)(/*[in]*/ IDispatch* *newVal);
	STDMETHOD(Execute)(/*[in]*/ int hParent,int nProcessor);
};

#endif //__MD500_H_
