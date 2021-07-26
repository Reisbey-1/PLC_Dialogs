#if !defined(MDXXMONITOR_DLG_H__D432A978_A846_458F_83D8_4F410B787576__INCLUDED_)
#define MDXXMONITOR_DLG_H__D432A978_A846_458F_83D8_4F410B787576__INCLUDED_


// MdxxMonitor_dlg.h : Header-Datei
//

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CMdxxMonitor_dlg 

class CMdxxMonitor_dlg : public CDialog
{
private:
	friend class CMdxxMonitor ;
	CString m_csMessage;
	void InitMe();
	void FillList() ;
protected:
	TelegramFabricLib::IFabric * m_pIFabric ;

// Konstruktion
public:
	CMdxxMonitor_dlg(CWnd* pParent = NULL, int nVm = VM_16);   // Standardkonstruktor
	TelegramFabricLib::IFabric* GetFabric();

// Dialogfelddaten
	//{{AFX_DATA(CMdxxMonitor_dlg)
	enum { IDD = IDD_DIALOG_MDxx_MONITOR };
	CString	m_csSymbolFile;
	//}}AFX_DATA


// Überschreibungen
	// Vom Klassen-Assistenten generierte virtuelle Funktionsüberschreibungen
	//{{AFX_VIRTUAL(CMdxxMonitor_dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:
	DPortLib::ISerialPort *			m_pISerPort;
	DPortLib::ISerialSink *         m_pSink;
	
	IConnectionPoint* m_pConnectionPoint;
	DWORD m_dwCokie;
	IConnectionPointContainer* m_pContainer;
	int m_nWaitDurationForShutDown;

	int m_nVm;
	// 
	// thread specifics.
	// a thread which reads device over RS232 
	// is started. it runs parallel to the dialog. 
	// It will be ended as the dialog is destroyed.
	// 
	static  UINT Rs232Thread(LPVOID pParam);
	void  RunMe();
	CWinThread*		m_pThread;
	HANDLE	m_hThreadStartet;
	HANDLE  m_hShutdownEvent;
	HANDLE  m_hThreadEndedEvent;

	bool    m_bStart;
	// synchronisation objects
	CRITICAL_SECTION	m_csCommunicationSync;

	//BYTE *m_pReceiveBuffer;//[1028];
	BYTE m_szReceiveBuffer[LENGTH_DETEL_RECEIVE];

	// Generierte Nachrichtenzuordnungsfunktionen
	//{{AFX_MSG(CMdxxMonitor_dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg void OnButtonBrowse();
	afx_msg void OnButtonStart();
	afx_msg void OnButtonStop();
	afx_msg void OnDblclkListRamBild(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnCancel();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // MDXXMONITOR_DLG_H__D432A978_A846_458F_83D8_4F410B787576__INCLUDED_
