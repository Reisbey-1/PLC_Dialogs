// IO28.h : Deklaration von CIO28

#ifndef __IO28_H_
#define __IO28_H_

#include "resource.h"       // Hauptsymbole
#include "IO28_dlg.h"

/////////////////////////////////////////////////////////////////////////////
// CIO28
class ATL_NO_VTABLE CIO28 : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CIO28, &CLSID_IO28>,
	public IDispatchImpl<IIO28, &IID_IIO28, &LIBID_DIALOGSLib>
{
public:
	CIO28()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_IO28)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CIO28)
	COM_INTERFACE_ENTRY(IIO28)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

protected:
//CIO28_dlg m_dialog;
// IIO28
public:
	STDMETHOD(Execute)();
};

#endif //__IO28_H_
