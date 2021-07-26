// EmbeddedConfigurator.h : Deklaration von CEmbeddedConfigurator

#ifndef __EMBEDDEDCONFIGURATOR_H_
#define __EMBEDDEDCONFIGURATOR_H_

#include "resource.h"       // Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CEmbeddedConfigurator
class ATL_NO_VTABLE CEmbeddedConfigurator : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CEmbeddedConfigurator, &CLSID_EmbeddedConfigurator>,
	public IDispatchImpl<IEmbeddedConfigurator, &IID_IEmbeddedConfigurator, &LIBID_DIALOGSLib>
{
public:
	CEmbeddedConfigurator()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_EMBEDDEDCONFIGURATOR)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CEmbeddedConfigurator)
	COM_INTERFACE_ENTRY(IEmbeddedConfigurator)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IEmbeddedConfigurator
public:
	STDMETHOD(Execute)();
};

#endif //__EMBEDDEDCONFIGURATOR_H_
