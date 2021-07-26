// TelegramFabric.h: Schnittstelle für die Klasse CTelegramFabric.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TELEGRAMFABRIC_H__D86B9A6F_94F8_45B4_AE7E_620142D5A8BE__INCLUDED_)
#define AFX_TELEGRAMFABRIC_H__D86B9A6F_94F8_45B4_AE7E_620142D5A8BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTelegramFabric  
{
public:
	CTelegramFabric();
	virtual ~CTelegramFabric();
public:
	static HRESULT SlaveIdentify(TELEGRAMFABRICLib::IMTelegram** ppTelegram);
	static HRESULT ReadSlaveTable(TELEGRAMFABRICLib::IMTelegram** ppTelegram,WORD slaveAddres,BYTE length = 128) ;
	static HRESULT UpdateSlaveTable(TELEGRAMFABRICLib::IMTelegram** ppTelegram,WORD slaveAddres,BYTE length = 128);

};

#endif // !defined(AFX_TELEGRAMFABRIC_H__D86B9A6F_94F8_45B4_AE7E_620142D5A8BE__INCLUDED_)
