// stdafx.h : Include-Datei für Standard-System-Include-Dateien,
//      oder häufig verwendete, projektspezifische Include-Dateien,
//      die nur in unregelmäßigen Abständen geändert werden.

#if !defined(AFX_STDAFX_H__5B5ADA6D_32C9_4A89_BF8D_50A9A02C188A__INCLUDED_)
#define AFX_STDAFX_H__5B5ADA6D_32C9_4A89_BF8D_50A9A02C188A__INCLUDED_

#define WINVER 0x0700
#define _WIN32_WINNT _WIN32_WINNT_MAXVER
#define NO_WARN_MBCS_MFC_DEPRECATION

#define STRICT

#define _ATL_APARTMENT_THREADED

#include <afxwin.h>
#include <afxdisp.h>

#include <atlbase.h>
//Sie können eine Klasse von CComModule ableiten und diese verwenden, um etwas zu überschreiben,
//Sie sollten jedoch den Namen von _Module nicht ändern
extern CComModule _Module;
#include <atlcom.h>
#include <afxcmn.h>
#ifdef _DEBUG
#import "../../bin/alcod.tlb"  raw_interfaces_only, raw_native_types, named_guids//, no_namespace
#import "../../bin/DPortd.tlb"  raw_interfaces_only, raw_native_types, named_guids//, no_namespace
#import "../../bin/TelegramFabricd.tlb"   raw_interfaces_only, raw_native_types, named_guids 
#else
#import "../../bin/alco.tlb"  raw_interfaces_only, raw_native_types, named_guids//, no_namespace
#import "../../bin/DPort.tlb"  raw_interfaces_only, raw_native_types, named_guids//, no_namespace
#import "../../bin/TelegramFabric.tlb"   raw_interfaces_only, raw_native_types, named_guids 
#endif

using namespace TelegramFabricLib;

#include "AlcUtility_include.h"
using namespace AlcUtility;
/**/

#include "messanger_Include.h"
using namespace messanger ;

//#include "..\..\DVR\implement\resource.h"
#include "EagCommon_Include.h"
using namespace eag;

#include "MdCommon_Include.h"
using namespace MdCommon ;

#include "DvrDll_Include.h"
using namespace dvr;

#include "XmlDLL_include.h"
using namespace XmlDll;
#
#include "Globals_Include.h"
/*
*/

/**/
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // !defined(AFX_STDAFX_H__5B5ADA6D_32C9_4A89_BF8D_50A9A02C188A__INCLUDED)
