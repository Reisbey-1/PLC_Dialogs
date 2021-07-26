// Md500_dlg.h : Header-Datei
#if !defined(AFX_MD500_DLG_H__F40702C7_6526_4912_B164_6533C52CBA58__INCLUDED_)
#define AFX_MD500_DLG_H__F40702C7_6526_4912_B164_6533C52CBA58__INCLUDED_

#include "Afxcmn.h"

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CMd500_dlg 

class CMd500_dlg : public CDialog
{
	friend class CMd500 ;
	CString m_csMessage;
	void MsgSlave();
	void MsgCPU();

	void InitMe();
	SlaveTable m_ST;
	void TabulatorSlaves(int bShow = 1);
	void TabulatorCPU(int bShow = 1);
protected :
	DPortLib::ISerialPort*	m_pISerPort;
	DPortLib::_ISerialPortEvents  *m_pSink;
	//BYTE *m_pReceiveBuffer;//[1028];
	BYTE m_szReceiveBuffer[LENGTH_DETEL_RECEIVE];
	TelegramFabricLib::IFabric * m_pIFabric;


// Konstruktion
public:
	CMd500_dlg(CWnd* pParent = NULL);   // Standardkonstruktor
	TelegramFabricLib::IFabric* GetFabric();

// Dialogfelddaten
	//{{AFX_DATA(CMd500_dlg)
	enum { IDD = IDD_DIALOG_MD500_CONFIGURATION };
	BYTE	m_nTableOffset;
	BYTE m_nSlaveAddress;

	CTreeCtrl	m_TreeCtrlMd500;
	//}}AFX_DATA


// Überschreibungen
	// Vom Klassen-Assistenten generierte virtuelle Funktionsüberschreibungen
	//{{AFX_VIRTUAL(CMd500_dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL



// Implementierung
protected:
	CImageList	m_il;
	int			m_nEBYTEcount;
	int			m_nEWORDcount;
	int			m_nProcessor;

	// Generierte Nachrichtenzuordnungsfunktionen
	//{{AFX_MSG(CMd500_dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonRetrieve();
	afx_msg void OnButtonDefault();
	afx_msg void OnSelchangedTreeMd500(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonReset();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	HBITMAP m_hBMDefault;
	HBITMAP m_hBMUpdate;
	HBITMAP m_hBMRetrive;
	HBITMAP m_hBMReset;
	///HBITMAP m_hBMHalt;
	///HBITMAP m_hBMContinue;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // AFX_MD500_DLG_H__F40702C7_6526_4912_B164_6533C52CBA58__INCLUDED_
