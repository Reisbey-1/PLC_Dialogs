// Md100_dlg.h : Header-Datei
#if !defined(AFX_MD100_DLG_H__CD887BDD_8C7F_4209_8B04_132BEF989A5C__INCLUDED_)
#define AFX_MD100_DLG_H__CD887BDD_8C7F_4209_8B04_132BEF989A5C__INCLUDED_

#include <Afxcmn.h>

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CMd100_dlg 

///////////////////////////////////////////////
class CMd100_dlg : public CDialog
{
private:
	friend class CMd100 ;
	CString m_csMessage;
	void InitMe();
	void MsgCPU() ;
	void MsgReceived(); 
	void _ReadFromSymbolFile(CString csFile);
	void _UPDATE() ;

protected:
	DPortLib::ISerialPort*	m_pISerPort;  
	DPortLib::_ISerialPortEvents  *m_pSink;
	//BYTE *m_pReceiveBuffer;//[1028];
	BYTE m_szReceiveBuffer[LENGTH_DETEL_RECEIVE];
	TelegramFabricLib::IFabric * m_pIFabric;
	// Konstruktion
public:
	CMd100_dlg(CWnd* pParent = NULL);   // Standardkonstruktor
	TelegramFabricLib::IFabric* GetFabric() ;

// Dialogfelddaten
	//{{AFX_DATA(CMd100_dlg)
	enum { IDD = IDD_DIALOG_ME100_CONFIGURATION };
	CListCtrl	m_listEBYTE;
	CString	m_csBrs;
	CString	m_csEEPROMHexFile;
	//}}AFX_DATA


// Überschreibungen
	// Vom Klassen-Assistenten generierte virtuelle Funktionsüberschreibungen
	//{{AFX_VIRTUAL(CMd100_dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL
// Implementierung
protected:
	int m_nEBYTEcount;
	int m_nEWORDcount;
	int m_nProcessor;
	int m_nItemSelected ;
	// Generierte Nachrichtenzuordnungsfunktionen
	//{{AFX_MSG(CMd100_dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonRetrieve();
	afx_msg void OnButtonReset();
	afx_msg void OnDblclkListEbyte(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkListEword(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonEbyteUpdate();
	afx_msg void OnButtonEwordUpdate();
	afx_msg void OnButtonEbyteRead();
	afx_msg void OnButtonEbyteReadButch();
	afx_msg void OnButtonEwordRead();
	afx_msg void OnDestroy();
	afx_msg void OnButtonHalt();
	afx_msg void OnButtonContinue();
	afx_msg void OnButtonBrs();
	afx_msg void OnRadioBytes();
	afx_msg void OnRadioWords();
	afx_msg void OnButtonBrsEepromHex();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	HBITMAP m_hBMDefault;
	HBITMAP m_hBMUpdate;
	HBITMAP m_hBMRetrive;
	HBITMAP m_hBMReset;
	HBITMAP m_hBMHalt;
	HBITMAP m_hBMContinue;

public:
	afx_msg void OnCbnSelchangeComboTakt();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // AFX_MD100_DLG_H__CD887BDD_8C7F_4209_8B04_132BEF989A5C__INCLUDED_
