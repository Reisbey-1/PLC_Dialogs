// Md500_dlg.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "resource.h"
#include "Md500_dlg.h"
/*
#include "TelegramFabric.h"

CString Processor[3]= {"Mega08", "Mega16", "Mega32"};
CString Module[5] = {"MD-50", "MD-100", "MD-300", "MD-500", "MD-700" };
CString Frequency[9] = {"1-MHz", "2-MHz", "4-MHz", "8-MHz", "12-MHz", "16-MHz", "20-MHz", "24-MHz", "32-MHz" };
CString Baud[7] = {"1200", "2400", "4800", "9600", "14400", "19200", "38400" };
*/
/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CMd500_dlg 

CMd500_dlg::CMd500_dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMd500_dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMd500_dlg)
	m_nTableOffset = 0xA0;
	m_nSlaveAddress = 0;
	//}}AFX_DATA_INIT

	m_pISerPort = NULL;
	m_hBMDefault	= 0;
	m_hBMUpdate		= 0;
	m_hBMRetrive	= 0;
	m_hBMReset		= 0;
//	m_hBMHalt		= 0;
//	m_hBMContinue	= 0;

}


void CMd500_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMd500_dlg)
	DDX_Control(pDX, IDC_TREE_MD500, m_TreeCtrlMd500);

	DDX_Text(pDX, IDC_EDIT_TABLE_OFFSET, m_nTableOffset);
	DDV_MinMaxByte(pDX, m_nTableOffset, 0, 255);
	DDX_Text(pDX, IDC_EDIT_SLAVE_ADDRESS, m_nSlaveAddress);
	DDV_MinMaxByte(pDX, m_nSlaveAddress, 0, 255);
	
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMd500_dlg, CDialog)
	//{{AFX_MSG_MAP(CMd500_dlg)
	ON_BN_CLICKED(IDC_BUTTON_RETRIEVE, OnButtonRetrieve)
	ON_BN_CLICKED(IDC_BUTTON_DEFAULT, OnButtonDefault)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_MD500, OnSelchangedTreeMd500)
	ON_BN_CLICKED(IDC_BUTTON_RESET, OnButtonReset)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen für Nachrichten CMd500_dlg 

BOOL CMd500_dlg::OnInitDialog()   
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	CDialog::OnInitDialog();

	BOOL b = m_il.Create(IDB_BITMAP1,16,16,RGB(170,0,170));
	//CImageList*			m_pIl = new CImageList;
	

	if (b == TRUE)
	{
		m_TreeCtrlMd500.SetImageList(&m_il,TVSIL_NORMAL);
	}

	else 
	{
///		AfxMessageBox("hooo - 2");
	}

	
	HTREEITEM hItemRoot = m_TreeCtrlMd500.InsertItem(L"Md500", 0,0, TVI_ROOT);
		HTREEITEM hIos = m_TreeCtrlMd500.InsertItem(L"IO's",1,7, hItemRoot);
			HTREEITEM hSlaves_00 = m_TreeCtrlMd500.InsertItem(L"IO-00",2,6, hIos);
			HTREEITEM hSlaves_01 = m_TreeCtrlMd500.InsertItem(L"IO-01",2,6, hIos);
			HTREEITEM hSlaves_02 = m_TreeCtrlMd500.InsertItem(L"IO-02",2,6, hIos);
			HTREEITEM hSlaves_03 = m_TreeCtrlMd500.InsertItem(L"IO-03",2,6, hIos);
			HTREEITEM hSlaves_04 = m_TreeCtrlMd500.InsertItem(L"IO-04",2,6, hIos);
			HTREEITEM hSlaves_05 = m_TreeCtrlMd500.InsertItem(L"IO-05",2,6, hIos);
			HTREEITEM hSlaves_06 = m_TreeCtrlMd500.InsertItem(L"IO-06",2,6, hIos);
			HTREEITEM hSlaves_07 = m_TreeCtrlMd500.InsertItem(L"IO-07",2,6, hIos);
			//HTREEITEM hSlaves_08 = m_TreeCtrlMd500.InsertItem("IO-08",2,6, hIos);

		HTREEITEM hCpu = m_TreeCtrlMd500.InsertItem(L"CPU",1,7, hItemRoot);

	InitMe();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX-Eigenschaftenseiten sollten FALSE zurückgeben
}

void CMd500_dlg::OnButtonRetrieve() 
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	LOG_OUT_INFO("CMd500_dlg::OnButtonRetrieve - begins")
		TelegramFabricLib::IMTelegram* pIMTelegram ;
//	IFabric* pIFabric = NULL;
	HRESULT hr;
	
	// see if valid ISerPort pointer
	if(m_pISerPort == NULL)
		return;

	if(m_pISerPort->CanDo() == S_FALSE)
	{
		LOG_OUT_WARNING("can not sent telegram.")
		return;
	}
	
	// get selected project
	HTREEITEM item = m_TreeCtrlMd500.GetSelectedItem();
	
	CString csItem = m_TreeCtrlMd500.GetItemText(item);
	
	WORD slvAdress = 0;
	int nCase = 0;

	if (csItem.CompareNoCase(L"IO-00")==0)
	{
		slvAdress = 1;
		nCase = 1;
	}

	else if (csItem.CompareNoCase(L"IO-01")==0)
	{
		slvAdress = 2;
		nCase = 2;
	}
	
	else if (csItem.CompareNoCase(L"IO-02")==0)
	{	slvAdress = 4;
		nCase = 3;
	}

	else if (csItem.CompareNoCase(L"IO-03")==0)
	{	slvAdress = 8;
		nCase = 4;
	}

	else if (csItem.CompareNoCase(L"IO-04")==0)
	{	slvAdress = 16;
		nCase = 5;
	}
	
	else if (csItem.CompareNoCase(L"IO-05")==0)
	{	slvAdress = 32;
		nCase = 6;
	}
	
	else if (csItem.CompareNoCase(L"IO-06")==0)
	{	slvAdress = 64;
		nCase = 7;
	}
	
	else if (csItem.CompareNoCase(L"IO-07")==0)
	{	slvAdress = 128;
		nCase = 8;
	}

	else if (csItem.CompareNoCase(L"CPU")==0)
	{	
		nCase = 9;
	}
	
	BeginWaitCursor();
	
	
	try
	{
	
	
		switch (nCase)
		{
		
		case  1 :
		case  2 :
		case  3 :
		case  4 :
		case  5 :
		case  6 :
		case  7 :
		case  8 :
		
		    // get fabric
			//GetFabric(&pIFabric) ;
			if (GetFabric())
			{
				
				hr = m_pIFabric->ReadSlaveTable(slvAdress, (IUnknown**)&pIMTelegram);
				{
					if (S_OK ==	m_pISerPort->SendDeTelTelegram(pIMTelegram))
					{
						MsgSlave();	
					}
					else 
					{
						//LOG_OUT_WARNING("can not send Telegram ");
					}
					
					// release telegram
					pIMTelegram->Release();
					
				}	
			
			// kill fabric 
			m_pIFabric->Kill();
			m_pIFabric = NULL;
			}
			else 
			{
				LOG_OUT_WARNING("can not create fabric")
			}

			break;
	
			

		case  9 :

		    // get fabric
			if (GetFabric())
			{
				hr = m_pIFabric->ReadMasterTable((IUnknown**)&pIMTelegram);
				{
					if (S_OK ==	m_pISerPort->SendDeTelTelegram(pIMTelegram))
					{
						MsgCPU();	
					}
					else 
					{
						//LOG_OUT_WARNING("can not send Telegram ");
					}
					
					// release telegram
					pIMTelegram->Release();
					
				}	
			
			// kill fabric 
			m_pIFabric->Kill();
			m_pIFabric = NULL;
			}
			else 
			{
				LOG_OUT_WARNING("can not create fabric")
			}

			break;


		default :
			;
		
		}

	 
	
	
	
	}
	
	catch(...)
	{
		LOG_OUT_ERROR("CMd500_dlg::OnButtonRetrieve - exception error")
	}
	

}

void CMd500_dlg::MsgCPU() 
{
	CEdit* pProcessor = (CEdit*) GetDlgItem(IDC_EDIT_PROCESSOR);
	CEdit* pModule    = (CEdit*) GetDlgItem(IDC_EDIT_MODULE);
	CEdit* pTakt      = (CEdit*) GetDlgItem(IDC_EDIT_TAKT_CPU);
	
	CString cs;
	// format coming values
	m_csMessage.Empty();
	for (int i = 0; i< 1028; i++)
	{
		cs.Format(L"%02x ", m_szReceiveBuffer[i]);
		if (i > 2 && i< 11)
			cs = "** ";
		m_csMessage += cs;
		if (m_szReceiveBuffer[i] == XOF)
			break;
	
	}


	// Processor
	try
	{
		if (m_szReceiveBuffer[tDEVL + 1] < 3)
		{
			pProcessor->SetWindowText(gsProcessor[m_szReceiveBuffer[tDEVL + 1]]);
			pModule->SetWindowText(gsModule[m_szReceiveBuffer[tDEVH + 1]]);
			pTakt->SetWindowText(gsFrequency[m_szReceiveBuffer[tFRQN + 1]]);
		
		}
	}
	catch(...)
	{
	
	}

	LOG_OUT_NOTIFY(m_csMessage) 

}

void CMd500_dlg::MsgSlave() 
{
	CComboBox* pSlaveType   = (CComboBox*) GetDlgItem(IDC_COMBO_SLAVE_TYPE); 
	CComboBox* pSlaveOffset = (CComboBox*) GetDlgItem(IDC_COMBO_SLAVE_OFFSET); 
	CComboBox* pBaud        = (CComboBox*) GetDlgItem(IDC_COMBO_BAUD); 
	CComboBox* pSlaveTakt   = (CComboBox*) GetDlgItem(IDC_COMBO_TAKT); 
	CComboBox* pParity      = (CComboBox*) GetDlgItem(IDC_COMBO_PARITY); 
	CComboBox* pFrequency   = (CComboBox*) GetDlgItem(IDC_COMBO_TAKT); 
	
	CButton* pRefVolVcc = (CButton*) GetDlgItem(IDC_RADIO_VCC); 
	CButton* pRefVol256 = (CButton*) GetDlgItem(IDC_RADIO_RV256); 



	CString cs;
	// format coming values
	m_csMessage.Empty();
	for (int i = 0; i< 1028; i++)
	{
		cs.Format(L"%02x ", m_szReceiveBuffer[i]);
		m_csMessage += cs;
		if (m_szReceiveBuffer[i] == XOF)
			break;
	}

	if (m_szReceiveBuffer[6]== 0xA0)
	{
		
		// slave address 
		m_nSlaveAddress = m_szReceiveBuffer[2];
		CDialog::OnInitDialog();

		// slave type
		pSlaveType->SetCurSel(m_szReceiveBuffer[1]);
		
		
		// ref voltage
		if (m_szReceiveBuffer[3]==0)
		{
			pRefVolVcc->SetCheck(1);
			pRefVol256->SetCheck(0);
		}
		else if(m_szReceiveBuffer[3]==1)
		{
			pRefVolVcc->SetCheck(0);
			pRefVol256->SetCheck(1);
		
		}
		
		// slave offset
		pSlaveOffset->SetCurSel((m_szReceiveBuffer[5]-1)/2);
		
		// baud
		pBaud->SetCurSel(m_szReceiveBuffer[7]);
		
		// frequency
		pFrequency->SetCurSel(m_szReceiveBuffer[9]);
		
		LOG_OUT_NOTIFY(m_csMessage) 
	}
	else
	{
		LOG_OUT_ERROR("corrupted slave table ! try it again")
	}

}	

TelegramFabricLib::IFabric* CMd500_dlg::GetFabric()
{

	HRESULT hr = S_OK;
	try
	{
		if (m_pIFabric == NULL)
		{
			hr = CoCreateInstance(
				TelegramFabricLib::CLSID_Fabric,
			NULL,
			CLSCTX_INPROC_SERVER,
				TelegramFabricLib::IID_IFabric,
			(void**) &m_pIFabric
			) ;	
		}
	}
	catch (...)
	{
		m_pIFabric = NULL;	
	}
	return m_pIFabric;
}


void CMd500_dlg::InitMe()
{
	CDialog::OnInitDialog();
	CComboBox* pSlaveType   = (CComboBox*) GetDlgItem(IDC_COMBO_SLAVE_TYPE); 
	CComboBox* pSlaveOffset = (CComboBox*) GetDlgItem(IDC_COMBO_SLAVE_OFFSET); 
	CComboBox* pBaud        = (CComboBox*) GetDlgItem(IDC_COMBO_BAUD); 
	CComboBox* pSlaveTakt   = (CComboBox*) GetDlgItem(IDC_COMBO_TAKT); 
	CComboBox* pParity      = (CComboBox*) GetDlgItem(IDC_COMBO_PARITY); 

	CButton* pButtonDefault = (CButton*) GetDlgItem(IDC_BUTTON_DEFAULT); 
	CButton* pButtonUpdate = (CButton*) GetDlgItem(IDC_BUTTON_UPDATE); 
	CButton* pButtonRetrieve = (CButton*) GetDlgItem(IDC_BUTTON_RETRIEVE); 
	CButton* pButtonReSet = (CButton*) GetDlgItem(IDC_BUTTON_RESET); 

	// Store the current resource handle
	HINSTANCE hClientResources = AfxGetResourceHandle();
	
	// get dvr resource 
	GET_DVR_RESOURCE(hDVRmdl)

	if (hDVRmdl)
	{
		AfxSetResourceHandle(hDVRmdl);
		m_hBMDefault	= LoadBitmap(hDVRmdl, MAKEINTRESOURCE(IDB_DEFAULT));
		m_hBMUpdate		= LoadBitmap(hDVRmdl, MAKEINTRESOURCE(IDB_EEPROM_UPDATE));
		m_hBMRetrive	= LoadBitmap(hDVRmdl, MAKEINTRESOURCE(IDB_EEPROM_RETRIEVE));
		m_hBMReset		= LoadBitmap(hDVRmdl, MAKEINTRESOURCE(IDB_RESET));
//		m_hBMHalt		= LoadBitmap(hDVRmdl, MAKEINTRESOURCE(IDB_HALT));
//		m_hBMContinue	= LoadBitmap(hDVRmdl, MAKEINTRESOURCE(IDB_CONTINUE));

		pButtonDefault->SetBitmap(m_hBMDefault);
		pButtonUpdate->SetBitmap(m_hBMUpdate);
		pButtonRetrieve->SetBitmap(m_hBMRetrive);
		pButtonReSet->SetBitmap(m_hBMReset);
//		pButtonHalt->SetBitmap(m_hBMHalt);
//		pButtonContinue->SetBitmap(m_hBMContinue);

		// Restore the client application resource handle
		AfxSetResourceHandle(hClientResources);
	}




	pSlaveType->ResetContent();
	pSlaveOffset->ResetContent();
	pBaud->ResetContent();
	pSlaveTakt->ResetContent();
	pParity->ResetContent();

	// slave type
	pSlaveType->AddString(L"SLO7");
	pSlaveType->AddString(L"SLI8");
	pSlaveType->AddString(L"OPI8");
	pSlaveType->AddString(L"IO28");
	pSlaveType->SetCurSel(3);
	m_ST.SLTY = 3;
	
	// slave address
	m_ST.SLAD = 0;

	// anolog voltage
	CButton* pButton256 = (CButton*) GetDlgItem(IDC_RADIO_RV256); 
	pButton256->SetCheck(1);
	m_ST.SLRV = 1;      // 2.54 Volt as default
	
	// communication protocol
	CButton* pComProtocol = (CButton*) GetDlgItem(IDC_RADIO_SPI500); 
	pComProtocol->SetCheck(1);
	m_ST.SLCP = 0;


	// slave offset
	pSlaveOffset->AddString(L"0x00");
	pSlaveOffset->AddString(L"0x01");
	pSlaveOffset->AddString(L"0x02");
	pSlaveOffset->AddString(L"0x03");
	pSlaveOffset->AddString(L"0x04");
	pSlaveOffset->AddString(L"0x05");
	pSlaveOffset->AddString(L"0x06");
	pSlaveOffset->AddString(L"0x07");

	pSlaveOffset->SetCurSel(0);
	m_ST.SLOF = 0;

	// table offseet 
	m_ST.TBOF = m_nTableOffset;

	
	//  baud
	pBaud->AddString(L"1200");
	pBaud->AddString(L"2400");
	pBaud->AddString(L"4800");
	pBaud->AddString(L"9600");
	pBaud->AddString(L"14400");
	pBaud->AddString(L"19200");
	pBaud->AddString(L"38400");
	pBaud->SetCurSel(3);
	m_ST.BAUD = 3;


	// parity
	pParity->AddString(L"NONE");
	pParity->AddString(L"ODD");
	pParity->AddString(L"EVEN");
	pParity->AddString(L"MARK");
	pParity->AddString(L"SPACE");
	pParity->SetCurSel(0);
	m_ST.PARITY = 0;  // none

	// takt
	pSlaveTakt->AddString(L"01 Mhz");
	pSlaveTakt->AddString(L"02 Mhz");
	pSlaveTakt->AddString(L"04 Mhz");
	pSlaveTakt->AddString(L"08 Mhz");
	pSlaveTakt->AddString(L"12 Mhz");
	pSlaveTakt->AddString(L"16 Mhz");
	pSlaveTakt->AddString(L"20 Mhz");
	pSlaveTakt->AddString(L"24 Mhz");
	pSlaveTakt->AddString(L"36 Mhz");
	pSlaveTakt->SetCurSel(3);
	//m_ST.TAKT = 3;  // 08 Mhz

}

void CMd500_dlg::OnButtonDefault() 
{
	InitMe();	
}

void CMd500_dlg::OnSelchangedTreeMd500(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Code für die Behandlungsroutine der Steuerelement-Benachrichtigung hier einfügen
	HTREEITEM item = m_TreeCtrlMd500.GetSelectedItem();
	CString csItem = m_TreeCtrlMd500.GetItemText(item);
	if (csItem.CompareNoCase(L"CPU")==0)
	{
		TabulatorSlaves(0);
		TabulatorCPU(1);
	}
	else if(   csItem.CompareNoCase(L"IO-00")==0
			|| csItem.CompareNoCase(L"IO-01")==0
			|| csItem.CompareNoCase(L"IO-02")==0
			|| csItem.CompareNoCase(L"IO-03")==0
			|| csItem.CompareNoCase(L"IO-04")==0
			|| csItem.CompareNoCase(L"IO-05")==0
			|| csItem.CompareNoCase(L"IO-06")==0
			|| csItem.CompareNoCase(L"IO-07")==0
		)
	{
		TabulatorCPU(0);
		TabulatorSlaves(1);
	}
	else
	{
	
		//TabulatorSlaves(0);
		//TabulatorCPU(0);
	}

	// TODO: End	
	*pResult = 0;
}

void CMd500_dlg::TabulatorSlaves(int bShow)
{
	// Combos
	CDialog::OnInitDialog();
	CComboBox* pSlaveType   = (CComboBox*) GetDlgItem(IDC_COMBO_SLAVE_TYPE); 
	CComboBox* pSlaveOffset = (CComboBox*) GetDlgItem(IDC_COMBO_SLAVE_OFFSET); 
	CComboBox* pBaud        = (CComboBox*) GetDlgItem(IDC_COMBO_BAUD); 
	CComboBox* pSlaveTakt   = (CComboBox*) GetDlgItem(IDC_COMBO_TAKT); 
	CComboBox* pParity      = (CComboBox*) GetDlgItem(IDC_COMBO_PARITY); 
	CComboBox* pSpiTakt   = (CComboBox*) GetDlgItem(IDC_COMBO_SPI_TAKT); 
	CComboBox* pTwiTakt  = (CComboBox*) GetDlgItem(IDC_COMBO_TWI_TAKT); 

	// Edits
	CEdit* pSlaveAddress     = (CEdit*) GetDlgItem(IDC_EDIT_SLAVE_ADDRESS); 
	CEdit* pTableOffset      = (CEdit*) GetDlgItem(IDC_EDIT_TABLE_OFFSET); 

	// Statics
	CStatic * pStSlaveType     = (CStatic*) GetDlgItem(IDC_STATIC_SLAVETYPE); 
	CStatic * pStSlaveAddres   = (CStatic*) GetDlgItem(IDC_STATIC_SLAVEADDRESS); 
	CStatic * pStRefVol        = (CStatic*) GetDlgItem(IDC_STATIC_REFVOL); 
	CStatic * pStComPro        = (CStatic*) GetDlgItem(IDC_STATIC_COMPRO); 
	CStatic * pStSlaveOffsett  = (CStatic*) GetDlgItem(IDC_STATIC_SLAVEOFFSET); 
	CStatic * pStTableOffsett  = (CStatic*) GetDlgItem(IDC_STATIC_TABLEOFFSET); 
	CStatic * pStBaud          = (CStatic*) GetDlgItem(IDC_STATIC_BAUD); 

	CStatic * pStParity        = (CStatic*) GetDlgItem(IDC_STATIC_PARITY); 
	CStatic * pStSlaveTakt     = (CStatic*) GetDlgItem(IDC_STATIC_TAKT); 
	CStatic * pStSpiTakt       = (CStatic*) GetDlgItem(IDC_STATIC_SPI_TAKT);  
	CStatic * pStTwiTakt       = (CStatic*) GetDlgItem(IDC_STATIC_TWI_TAKT);  
	CStatic * pStTwiComment    = (CStatic*) GetDlgItem(IDC_STATIC_TWI_COMMENT);  
	CStatic * pStSpiComment    = (CStatic*) GetDlgItem(IDC_STATIC_SPI_COMMENT);  
	
	CStatic * pStLine1    = (CStatic*) GetDlgItem(IDC_STATIC_LINE1);  
	CStatic * pStLine2    = (CStatic*) GetDlgItem(IDC_STATIC_LINE2);  
	CStatic * pStLine3    = (CStatic*) GetDlgItem(IDC_STATIC_LINE3);  

	// Radio buttons
	CButton* pRefVolVcc = (CButton*) GetDlgItem(IDC_RADIO_VCC); 
	CButton* pRefVol256 = (CButton*) GetDlgItem(IDC_RADIO_RV256); 
	
	CButton* pSpi500 = (CButton*) GetDlgItem(IDC_RADIO_SPI500); 
	CButton* pSpi500_R = (CButton*) GetDlgItem(IDC_RADIO_SPI500_R); 
	CButton* pTwi = (CButton*) GetDlgItem(IDC_RADIO_TWI); 
	CButton* pTwi_R = (CButton*) GetDlgItem(IDC_RADIO_TWI_R); 

	
	// Combos
	pSlaveType->ShowWindow(bShow);
	pSlaveOffset->ShowWindow(bShow);
	pBaud->ShowWindow(bShow);
	pSlaveTakt->ShowWindow(bShow);
	pParity->ShowWindow(bShow);
	pSpiTakt->ShowWindow(bShow);
	pTwiTakt->ShowWindow(bShow);

	// Edits
	pSlaveAddress->ShowWindow(bShow);
	pTableOffset->ShowWindow(bShow);

	// Radio buttons
	pRefVolVcc->ShowWindow(bShow);
	pRefVol256->ShowWindow(bShow);
	pSpi500->ShowWindow(bShow);
	pSpi500_R->ShowWindow(bShow);
	pTwi->ShowWindow(bShow);
	pTwi_R->ShowWindow(bShow);


	// Statics
	pStSlaveType->ShowWindow(bShow);
	pStSlaveAddres->ShowWindow(bShow);
	pStRefVol->ShowWindow(bShow);
	pStComPro->ShowWindow(bShow);
	pStSlaveOffsett->ShowWindow(bShow);
	pStTableOffsett->ShowWindow(bShow);
	pStBaud->ShowWindow(bShow);

	pStParity->ShowWindow(bShow);
	pStSlaveTakt->ShowWindow(bShow);
	pStSpiTakt->ShowWindow(bShow);
	pStTwiTakt->ShowWindow(bShow);
	pStTwiComment->ShowWindow(bShow);
	pStSpiComment->ShowWindow(bShow);
	
	pStLine1->ShowWindow(bShow); 
	pStLine2->ShowWindow(bShow);
	pStLine3->ShowWindow(bShow);


	// Buttons
	CButton* pButtonDefault = (CButton*) GetDlgItem(IDC_BUTTON_DEFAULT); 
	CButton* pButtonUpdate = (CButton*) GetDlgItem(IDC_BUTTON_UPDATE); 
	CButton* pButtonRetrieve = (CButton*) GetDlgItem(IDC_BUTTON_RETRIEVE); 
	
	pButtonDefault->ShowWindow(bShow);
	pButtonUpdate->ShowWindow(bShow);
	pButtonRetrieve->ShowWindow(bShow);

}


void CMd500_dlg::TabulatorCPU(int bShow)
{
	CStatic * pStSlaveType  = (CStatic*) GetDlgItem(IDC_STATIC_SLAVETYPE); 
	CComboBox* pSlaveType   = (CComboBox*) GetDlgItem(IDC_COMBO_SLAVE_TYPE); 
	//CEdit* pSlaveType   = (CEdit*) GetDlgItem(IDC_EDIT_SLAVE_TYPE); 
	RECT rect1, rect2;
	pStSlaveType->GetWindowRect(&rect1);
	ScreenToClient(&rect1);
	pSlaveType->GetWindowRect(&rect2);
	ScreenToClient(&rect2);

	int nX1 = rect1.left;
	int nY1 = rect1.top;
	int L1  = rect1.right-rect1.left;
	int H1  = rect1.bottom - rect1.top;
	
	int nX2 = rect2.left;
	int nY2 = rect2.top;
	int L2  = rect2.right-rect2.left;
	int H2  = rect2.bottom - rect2.top;

	int DH  =  24;

/**/
	// processor
	CStatic * pStProcessor   = (CStatic*) GetDlgItem(IDC_STATIC_PROCESSOR); 
	CEdit *   pEditProcessor = (CEdit*) GetDlgItem(IDC_EDIT_PROCESSOR); 
	pStProcessor->MoveWindow(nX1,nY1, L1, H1);
	pStProcessor->ShowWindow(bShow);
	pEditProcessor->MoveWindow(nX2,nY2, L2, H2);
	pEditProcessor->ShowWindow(bShow);
	
	// module
	CStatic   * pStModule    = (CStatic*) GetDlgItem(IDC_STATIC_MODULE); 
	CEdit * pEditModule      = (CEdit*) GetDlgItem(IDC_EDIT_MODULE); 
	pStModule->MoveWindow(nX1,nY1+DH, L1, H1);
	pStModule->ShowWindow(bShow);
	pEditModule->MoveWindow(nX2,nY2+DH, L2, H2);
	pEditModule->ShowWindow(bShow);

	// takt CPU
	CStatic * pStTaktCPU	 = (CStatic*) GetDlgItem(IDC_STATIC_TAKT_CPU); 
	CEdit	* pEditTaktCPU   = (CEdit*) GetDlgItem(IDC_EDIT_TAKT_CPU); 
	pStTaktCPU->MoveWindow(nX1,nY1+2*DH, L1, H1);
	pStTaktCPU->ShowWindow(bShow);
	pEditTaktCPU->MoveWindow(nX2,nY2+2*DH, L2, H2);
	pEditTaktCPU->ShowWindow(bShow);


	// line 2
	CStatic * pStLine2    = (CStatic*) GetDlgItem(IDC_STATIC_LINE2);  
	pStLine2->ShowWindow(bShow);


	// buttons
	CButton* pButtonDefault  = (CButton*) GetDlgItem(IDC_BUTTON_DEFAULT); 
	CButton* pButtonUpdate	 = (CButton*) GetDlgItem(IDC_BUTTON_UPDATE); 
	CButton* pButtonRetrieve = (CButton*) GetDlgItem(IDC_BUTTON_RETRIEVE); 
	

	pButtonDefault->ShowWindow(!bShow);
	pButtonUpdate->ShowWindow(!bShow);
	
	pButtonRetrieve->ShowWindow(bShow);


}

void CMd500_dlg::OnButtonReset() 
{
//	IFabric* pIFabric = NULL;
	TelegramFabricLib::IMTelegram* pIMTelegram ;
	HRESULT hr;

	// get fabric
	//hr =  CFabric::GetFabric(&pIFabric) ;
	
	if (GetFabric())
	{
		
		hr = m_pIFabric->Reset((IUnknown**)&pIMTelegram);
		{
			if (S_OK ==	m_pISerPort->SendDeTelTelegram(pIMTelegram))
			{
				//MsgSlave();	
			}
			else 
			{
				//LOG_OUT_WARNING("can not send Telegram ");
			}
			
			// release telegram
			pIMTelegram->Release();
			
		}	
	
		// kill fabric 
		GetFabric()->Kill();
		m_pIFabric = NULL;
	}
	else 
	{
		LOG_OUT_WARNING("can not create fabric")
	}	
}

void CMd500_dlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// clean up
	DeleteObject(m_hBMDefault);	
	DeleteObject(m_hBMUpdate);	
	DeleteObject(m_hBMRetrive);	
	DeleteObject(m_hBMReset);	
//	DeleteObject(m_hBMHalt);	
//	DeleteObject(m_hBMContinue);	
	
}
