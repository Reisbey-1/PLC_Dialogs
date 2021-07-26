// Dialogs.cpp : Implementierung der DLL-Exporte.


// Hinweis: Proxy/Stub-Information
//      Um eine eigene Proxy/Stub-DLL zu erstellen, 
//      führen Sie nmake -f Dialogsps.mk im Projektverzeichnis aus.

#include "stdafx.h"
#include "resource.h"
#include <initguid.h>
#include "Dialogs.h"

#include "Dialogs_i.c"
#include "IO28.h"
#include "Md500.h"
#include "Md100.h"
#include "EmbeddedConfigurator.h"
#include "MdxxMonitor.h"


CComModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
OBJECT_ENTRY(CLSID_IO28, CIO28)
OBJECT_ENTRY(CLSID_Md100, CMd100)
OBJECT_ENTRY(CLSID_Md500, CMd500)
OBJECT_ENTRY(CLSID_EmbeddedConfigurator, CEmbeddedConfigurator)
OBJECT_ENTRY(CLSID_MdxxMonitor, CMdxxMonitor)
END_OBJECT_MAP()

class CDialogsApp : public CWinApp
{
public:

// Überladungen
	// Überladungen für vom Klassen-Assistenten generierte virtuelle Funktionen
	//{{AFX_VIRTUAL(CDialogsApp)
	public:
    virtual BOOL InitInstance();
    virtual int ExitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CDialogsApp)
		// HINWEIS - der Klassen-Assistent fügt hier Member-Funktionen hinzu oder löscht sie.
		//    BEARBEITEN SIE NICHT, was Sie in diesen generierten Code-Blöcken sehen !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CDialogsApp, CWinApp)
	//{{AFX_MSG_MAP(CDialogsApp)
		// HINWEIS - der Klassen-Assistent fügt hier Umsetzungsmakros hinzu oder löscht sie.
		//    BEARBEITEN SIE NICHT, was Sie in diesen generierten Code-Blöcken sehen !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CDialogsApp theApp;

BOOL CDialogsApp::InitInstance()
{
	_Module.Init(ObjectMap, m_hInstance, &LIBID_DIALOGSLib);
	HRESULT hr = CoInitialize(0);
	if (hr != S_OK && hr != S_FALSE)
	{
		LOG_OUT_ERROR("can not initialize com liblaries")
	}
	return CWinApp::InitInstance();
}

int CDialogsApp::ExitInstance()
{
 	
	 _Module.Term();

    return CWinApp::ExitInstance();
}

/////////////////////////////////////////////////////////////////////////////
// Verwendet, um zu entscheiden, ob die DLL von OLE aus dem Speicher entfernt werden kann

STDAPI DllCanUnloadNow(void)
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());
    return (AfxDllCanUnloadNow()==S_OK && _Module.GetLockCount()==0) ? S_OK : S_FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// Liefert eine Klassenfabrik zurück, um ein Objekt des angeforderten Typs anzulegen

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _Module.GetClassObject(rclsid, riid, ppv);
}

/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Fügt der Systemregistrierung Einträge hinzu

STDAPI DllRegisterServer(void)
{
    // Registriert Objekt, Typelib und alle Schnittstellen in Typelib
    return _Module.RegisterServer(TRUE);
}

/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Entfernt Einträge aus der Systemregistrierung

STDAPI DllUnregisterServer(void)
{
    return _Module.UnregisterServer(TRUE);
}


