// TelegramFabric.cpp: Implementierung der Klasse CTelegramFabric.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TelegramFabric.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Konstruktion/Destruktion
//////////////////////////////////////////////////////////////////////

CTelegramFabric::CTelegramFabric()
{

}

CTelegramFabric::~CTelegramFabric()
{

}


HRESULT CTelegramFabric::SlaveIdentify(DPORTLib::IMTelegram** ppTelegram)
{
	HRESULT hr = CoCreateInstance(
		DPORTLib::CLSID_MTelegram,
		NULL,
		CLSCTX_INPROC_SERVER,
		DPORTLib::IID_IMTelegram,
		(void**) ppTelegram
		) ;
	
	if(hr == S_OK)
	{
		// Type
		CString csType = "SP_SL01";
		BSTR bstType = CStringUtility::cStringToBSTR(csType);
		(*ppTelegram)->put_type(bstType);
		
		// command
		(*ppTelegram)->put_cmd(SP_SL01);
	}

	return hr;

}


HRESULT CTelegramFabric::ReadSlaveTable(DPORTLib::IMTelegram** ppTelegram, WORD slaveAddres, BYTE length)
{
	HRESULT hr = CoCreateInstance(
		DPORTLib::CLSID_MTelegram,
		NULL,
		CLSCTX_INPROC_SERVER,
		DPORTLib::IID_IMTelegram,
		(void**) ppTelegram
		) ;
	
	if(hr == S_OK)
	{
		// Type
		CString csType = "SP_SLRT";
		BSTR bstType = CStringUtility::cStringToBSTR(csType);
		(*ppTelegram)->put_type(bstType);
		
		// command
		(*ppTelegram)->put_cmd(SP_SLRT);
		
		// adress
		(*ppTelegram)->put_Address(slaveAddres);

		// length
		(*ppTelegram)->put_rs0(length);
	
	}

	return hr;

}

HRESULT CTelegramFabric::UpdateSlaveTable(DPORTLib::IMTelegram** ppTelegram, WORD slaveAddres, BYTE length)
{
	HRESULT hr = CoCreateInstance(
		DPORTLib::CLSID_MTelegram,
		NULL,
		CLSCTX_INPROC_SERVER,
		DPORTLib::IID_IMTelegram,
		(void**) ppTelegram
		) ;
	
	if(hr == S_OK)
	{
		// Type
		CString csType = "SP_SLUT";
		BSTR bstType = CStringUtility::cStringToBSTR(csType);
		(*ppTelegram)->put_type(bstType);
		
		// command
		(*ppTelegram)->put_cmd(SP_SLUT);
		
		// adress
		(*ppTelegram)->put_Address(slaveAddres);

		// length
		(*ppTelegram)->put_rs0(length);

	}

	return hr;

}