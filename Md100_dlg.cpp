// Md100_dlg.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "resource.h"
#include "Md100_dlg.h"
#include "DialogItemValue.h"
//#include "SerialPortSink.h"

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CMd100_dlg 


CMd100_dlg::CMd100_dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMd100_dlg::IDD, pParent)

{
	//{{AFX_DATA_INIT(CMd100_dlg)
	m_csBrs = _T("");
	m_csEEPROMHexFile = _T("");
	//}}AFX_DATA_INIT

	m_nEBYTEcount   = VM16_EPROM_BYTE_COUNT;
	m_nEWORDcount   = VM16_EPROM_WORD_COUNT;
	m_nItemSelected = -1;
	m_pIFabric      = NULL ;

	m_hBMDefault	= 0;
	m_hBMUpdate		= 0;
	m_hBMRetrive	= 0;
	m_hBMReset		= 0;
	m_hBMHalt		= 0;
	m_hBMContinue	= 0;

}


void CMd100_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMd100_dlg)
	DDX_Control(pDX, IDC_BUTTON_DEFAULT, m_listEBYTE);
	DDX_Text(pDX, IDC_EDIT_BRS, m_csBrs);
	DDX_Text(pDX, IDC_EDIT_BRS_EEPROM_HEX, m_csEEPROMHexFile);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMd100_dlg, CDialog)
	//{{AFX_MSG_MAP(CMd100_dlg)
	ON_BN_CLICKED(IDC_BUTTON_RETRIEVE, OnButtonRetrieve)
	ON_BN_CLICKED(IDC_BUTTON_RESET, OnButtonReset)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_EBYTE, OnDblclkListEbyte)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_EWORD, OnDblclkListEword)
	ON_BN_CLICKED(IDC_BUTTON_EBYTE_UPDATE, OnButtonEbyteUpdate)
	ON_BN_CLICKED(IDC_BUTTON_EWORD_UPDATE, OnButtonEwordUpdate)
	ON_BN_CLICKED(IDC_BUTTON_EBYTE_READ, OnButtonEbyteRead)
	ON_BN_CLICKED(IDC_BUTTON_EBYTE_READ_BUTCH, OnButtonEbyteReadButch)
	ON_BN_CLICKED(IDC_BUTTON_EWORD_READ, OnButtonEwordRead)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_HALT, OnButtonHalt)
	ON_BN_CLICKED(IDC_BUTTON_CONTINUE, OnButtonContinue)
	ON_BN_CLICKED(IDC_BUTTON_BRS, OnButtonBrs)
	ON_BN_CLICKED(IDC_RADIO_BYTES, OnRadioBytes)
	ON_BN_CLICKED(IDC_RADIO_WORDS, OnRadioWords)
	ON_BN_CLICKED(IDC_BUTTON_BRS_EEPROM_HEX, OnButtonBrsEepromHex)
	//}}AFX_MSG_MAP
	ON_CBN_SELCHANGE(IDC_COMBO_TAKT, &CMd100_dlg::OnCbnSelchangeComboTakt)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen für Nachrichten CMd100_dlg 
BOOL CMd100_dlg::OnInitDialog() 
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	CDialog::OnInitDialog();
	
	m_csBrs = AfxGetApp()->GetProfileString(L"dvr", L"SymbolFile", L"" );
	Invalidate();
	InitMe();
	_ReadFromSymbolFile(m_csBrs);

	CButton* prbByte =  (CButton*) GetDlgItem(IDC_RADIO_BYTES);
	prbByte->SetCheck(1);

	// Eeprom hex file
	m_csEEPROMHexFile = AfxGetApp()->GetProfileString(L"DIALOGS", L"EpromHexFile", L"C:\\sw\\bin\\examples\\EEPROM_M.hex");;
	// _UPDATE()
	_UPDATE();
	
	// takt frequency
	CComboBox* pFrq = (CComboBox*)GetDlgItem(IDC_COMBO_TAKT);
	for (int i = 0; i< TAKT_FREQENCY_COUNT ; i++) 	pFrq->AddString(gsFrequency[i]);

	// clock selection  prescaler
	CComboBox* pPRSC = (CComboBox*)GetDlgItem(IDC_COMBO_PRSC);
	for (int i = 0; i< PRSC_COUNT; i++) 	pPRSC->AddString(gsPreScalerforTimer[i]);

	CDialog::OnInitDialog();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX-Eigenschaftenseiten sollten FALSE zurückgeben
}

TelegramFabricLib::IFabric* CMd100_dlg::GetFabric()
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

void CMd100_dlg::InitMe()
{
	//AFX_MANAGE_STATE(AfxGetStaticModuleState());
	int i = 0;
	CButton* pButtonDefault = (CButton*) GetDlgItem(IDC_BUTTON_DEFAULT); 
	CButton* pButtonUpdate = (CButton*) GetDlgItem(IDC_BUTTON_UPDATE); 
	CButton* pButtonRetrieve = (CButton*) GetDlgItem(IDC_BUTTON_RETRIEVE); 
	CButton* pButtonReSet = (CButton*) GetDlgItem(IDC_BUTTON_RESET); 
	CButton* pButtonHalt = (CButton*) GetDlgItem(IDC_BUTTON_HALT); 
	CButton* pButtonContinue = (CButton*) GetDlgItem(IDC_BUTTON_CONTINUE); 
	
	// get dvr resource 
	GET_DVR_RESOURCE(hDVRmdl)

	// Store the current resource handle
	HINSTANCE hClientResources = AfxGetResourceHandle();

	if (hDVRmdl)
	{
		AfxSetResourceHandle(hDVRmdl);
		m_hBMDefault	= LoadBitmap(hDVRmdl, MAKEINTRESOURCE(IDB_DEFAULT));
		m_hBMUpdate		= LoadBitmap(hDVRmdl, MAKEINTRESOURCE(IDB_EEPROM_UPDATE));
		m_hBMRetrive	= LoadBitmap(hDVRmdl, MAKEINTRESOURCE(IDB_EEPROM_RETRIEVE));
		m_hBMReset		= LoadBitmap(hDVRmdl, MAKEINTRESOURCE(IDB_RESET));
		m_hBMHalt		= LoadBitmap(hDVRmdl, MAKEINTRESOURCE(IDB_HALT));
		m_hBMContinue	= LoadBitmap(hDVRmdl, MAKEINTRESOURCE(IDB_CONTINUE));

		pButtonDefault->SetBitmap(m_hBMDefault);
		pButtonUpdate->SetBitmap(m_hBMUpdate);
		pButtonRetrieve->SetBitmap(m_hBMRetrive);
		pButtonReSet->SetBitmap(m_hBMReset);
		pButtonHalt->SetBitmap(m_hBMHalt);
		pButtonContinue->SetBitmap(m_hBMContinue);
	
		// Restore the client application resource handle
		AfxSetResourceHandle(hClientResources);

	}


	// eprom byte list
	CListCtrl* pListEBYTE =  (CListCtrl*) GetDlgItem(IDC_LIST_EBYTE);
	pListEBYTE->InsertColumn(0, L"Adress",LVCFMT_LEFT, 50);
	pListEBYTE->InsertColumn(1, L"Name",LVCFMT_LEFT, 50);
	pListEBYTE->InsertColumn(2, L"Register",LVCFMT_LEFT, 60);
	pListEBYTE->InsertColumn(3, L"Value",LVCFMT_LEFT, 50);
	pListEBYTE->InsertColumn(4, L"Explanation",LVCFMT_LEFT, 350);
	pListEBYTE->InsertColumn(5, L"Selection",LVCFMT_LEFT, 60);

	
	pListEBYTE->SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_ONECLICKACTIVATE  );
	
	
	CString csItemAdress;
	CString csItemName;
	CString csItemValue;
	CString csCaption;
	if (m_nProcessor == VM_08)
	{
		m_nEBYTEcount = VM08_EPROM_BYTE_COUNT;
		m_nEWORDcount = VM08_EPROM_WORD_COUNT;
		csCaption.LoadString(IDS_ME50_VM08);
		SetWindowText(csCaption);
		LOG_OUT_INTERNAL(csCaption)
	}
	if (m_nProcessor == VM_16)
	{
		m_nEBYTEcount = VM16_EPROM_BYTE_COUNT;
		m_nEWORDcount = VM16_EPROM_WORD_COUNT;
		csCaption.LoadString(IDS_ME100_VM16);
		SetWindowText(csCaption);
		LOG_OUT_INTERNAL(csCaption)
	}
	
	if (m_nProcessor == VM_32)
	{
		m_nEBYTEcount = VM32_EPROM_BYTE_COUNT;
		m_nEWORDcount = VM32_EPROM_WORD_COUNT;
		csCaption.LoadString(IDS_ME100_VM32);
		SetWindowText(csCaption);
		LOG_OUT_INTERNAL(csCaption)
	}
	
	for (i= 0; i< m_nEBYTEcount; i++) 
	{
		csItemAdress.Format(L"0x%02x",i + VM_EPROM_BYTE_BASE );
		csItemName.Format(L"EB%02x",i);
		csItemValue.Format(L"0xFF",i);
		pListEBYTE->InsertItem(i,csItemAdress.GetBuffer(0));
		pListEBYTE->SetItemText(i,1,csItemName.GetBuffer(0));
		pListEBYTE->SetItemText(i,2,csItemName.GetBuffer(0));
		pListEBYTE->SetItemText(i,3,csItemValue.GetBuffer(0));

	}

	// eprom word list
	CListCtrl* pListEWORD =  (CListCtrl*) GetDlgItem(IDC_LIST_EWORD);
	pListEWORD->InsertColumn(0, L"Adress",LVCFMT_LEFT, 50);
	pListEWORD->InsertColumn(1, L"Name",LVCFMT_LEFT, 50);
	pListEWORD->InsertColumn(2, L"Register",LVCFMT_LEFT, 60);
	pListEWORD->InsertColumn(3, L"Value",LVCFMT_LEFT, 50);
	pListEWORD->InsertColumn(4, L"Explanation",LVCFMT_LEFT, 350);
	pListEWORD->InsertColumn(5, L"Selection",LVCFMT_LEFT, 60);
	pListEWORD->SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_ONECLICKACTIVATE  );

	int k = 0;
	for (i= 0; i<m_nEWORDcount; i++) 
	{
		csItemAdress.Format(L"0x%02x",k + VM_EPROM_BYTE_BASE + m_nEBYTEcount);
		csItemName.Format(L"EW%02x",i);
		csItemValue.Format(L"0xFFFF",i);
		pListEWORD->InsertItem(i,csItemAdress.GetBuffer(0));
		pListEWORD->SetItemText(i,1,csItemName.GetBuffer(0));
		pListEWORD->SetItemText(i,2,csItemName.GetBuffer(0));
		pListEWORD->SetItemText(i,3,csItemValue.GetBuffer(0));

		k = k+2;
	}	
}

void CMd100_dlg::OnButtonRetrieve() 
{
	TelegramFabricLib::IMTelegram * pIMTelegram ;

	HRESULT hr;

	if (GetFabric())
	{
		
		hr = m_pIFabric->ReadMasterTable((IUnknown**)&pIMTelegram);
		{
			if (S_OK ==	m_pISerPort->SendDeTelTelegram(pIMTelegram))
			{
				Beep(1000, 100);
				MsgCPU();	
			}
			else 
			{
				LOG_OUT_DEBUG(L"CMd100_dlg::OnButtonRetrieve - can not send Telegram ");
			}
			
			// release telegram
			pIMTelegram->Release();
		}	
	}
	else 
	{
		LOG_OUT_DEBUG(L"CMd100_dlg::OnButtonRetrieve - can not create fabric")
	}
}

void CMd100_dlg::MsgReceived() 
{
	CString cs ;
	// format coming values
	//


	DPortLib::ISerialSink *pSink;
	m_pSink->QueryInterface(DPortLib::IID_ISerialSink,(void**)&pSink);
	m_csMessage.Empty();

	HRESULT hr = pSink->get_ReceiveBuffer((unsigned char**)&m_szReceiveBuffer);
	 
	CString csMessage;
	CString csDumy;

	BSTR bstr;
	hr = pSink->get_Message(&bstr);

	// m_csMessage = L"CMd100_dlg::MsgReceived : \n";
	if (hr == S_OK)
	{
		m_csMessage = CStringUtility::bstrToCString(bstr);
	
		pSink->Release();
/*
		for (int i = 0; i < 1028; i++)
		{
			cs.Format(L"%02x ", szReceiveBuffer[i]);
			if (i > 2 && i < 11)
				cs = L"** ";
			if (szReceiveBuffer[i] == XOF)
			{
				m_csMessage += cs;
				pSink->Release();
				//	LOG_OUT_INTERNAL( m_csMessage)
				break;
			}
			m_csMessage += cs;
		}*/

	}	
}

void CMd100_dlg::MsgCPU() 
{
	CEdit* pProcessor = (CEdit*) GetDlgItem(IDC_EDIT_PROCESSOR);
	CEdit* pModule    = (CEdit*) GetDlgItem(IDC_EDIT_MODULE);
//	CEdit* pTakt      = (CEdit*) GetDlgItem(IDC_EDIT_TAKT_CPU);
	CEdit* pBaud      = (CEdit*) GetDlgItem(IDC_EDIT_BAUD);

	CComboBox* pFrq = (CComboBox*)GetDlgItem(IDC_COMBO_TAKT);
	CComboBox* pSpiFrq = (CComboBox*)GetDlgItem(IDC_COMBO_SPI_TAKT);
	CComboBox* pPRSC = (CComboBox*)GetDlgItem(IDC_COMBO_PRSC);
	
	CButton* pButton256 = (CButton*) GetDlgItem(IDC_RADIO_RV256); 
	CButton* pButtonVcc = (CButton*) GetDlgItem(IDC_RADIO_VCC); 
	
	//AfxMessageBox(L"1");
	MsgReceived();
//	AfxMessageBox(L"2");


	// Processor tMSRV
	try
	{
		if (m_szReceiveBuffer[tDEVL+1] < 3)
		{
			pProcessor->SetWindowText(gsProcessor[m_szReceiveBuffer[tDEVL+1]]);
			pModule->SetWindowText(gsModule[m_szReceiveBuffer[tDEVH+1]]);
		}
		
		// anolog voltage
		if (m_szReceiveBuffer[tMSRV+1] == 0 )
		{
			pButtonVcc->SetCheck(1);
			pButton256->SetCheck(0);
		}
		else 
		{
			pButtonVcc->SetCheck(0);
			pButton256->SetCheck(1);
		}

		// baud
		if (m_szReceiveBuffer[tMAUD + 1] < 7 )
		{
			pBaud->SetWindowText(gsBaud[m_szReceiveBuffer[tMAUD + 1]]);
		}

		// tick
		if (m_szReceiveBuffer[tTICK + 1] < 7)
		{
			pBaud->SetWindowText(gsBaud[m_szReceiveBuffer[tMAUD + 1]]);
		}

		// frequency
		if (m_szReceiveBuffer[tFRQN + 1] < TAKT_FREQENCY_COUNT)
		{
			pFrq->SetCurSel(m_szReceiveBuffer[tFRQN + 1]);
		}

		// spi frequency  gsSpiFrequency[TAKT_SPI_FREQENCY_COUNT]
		if (m_szReceiveBuffer[tFRQN + 1] < TAKT_SPI_FREQENCY_COUNT)
		{
			pFrq->SetCurSel(m_szReceiveBuffer[tFRQN + 1]);
		}

		// pre scaler
		if (m_szReceiveBuffer[tPRSC + 1] < PRSC_COUNT) // gsPreScalerforTimer
		{
			pPRSC->SetCurSel(m_szReceiveBuffer[tPRSC + 1]);
		}



	}
	catch(...)
	{
	
	}

	LOG_OUT_CRITICAL(m_csMessage) 

}

void CMd100_dlg::OnButtonReset() 
{
	TelegramFabricLib::IMTelegram* pIMTelegram ;
	HRESULT hr;

	// get fabric
	if (GetFabric())
	{
		hr = m_pIFabric->Reset((IUnknown**)&pIMTelegram);
		{
			if (S_OK ==	m_pISerPort->SendDeTelTelegram(pIMTelegram))
			{
			}
			else 
			{
				LOG_OUT_DEBUG(L"CMd100_dlg::OnButtonReset - can not send Telegram ");
			}
			
			// release telegram
			pIMTelegram->Release();
			
		}	

	}
	else 
	{
		LOG_OUT_WARNING(L"CMd100_dlg::OnButtonReset - can not create fabric")
	}		
}

void CMd100_dlg::OnDblclkListEbyte(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CListCtrl* pListEBYTE = (CListCtrl*)GetDlgItem(IDC_LIST_EBYTE); 
	m_nItemSelected =  pListEBYTE->GetNextItem(-1,LVNI_SELECTED);
	CString csValue, csComment, csCaption;
	
	if (m_nItemSelected == -1)
	{
		LOG_OUT_ERROR(L"CMd100_dlg::OnDblclkListEbyte - Select an element !")
		return;
	}
	
	csValue = pListEBYTE->GetItemText(m_nItemSelected,3);
	BYTE b;
//	if(FALSE== CNumberUtility::HexToByte(csValue,b))
//		return;
	b = _wtoi(csValue);	

	csValue = pListEBYTE->GetItemText(m_nItemSelected,3);
	csComment = pListEBYTE->GetItemText(m_nItemSelected, 4);
	csCaption = pListEBYTE->GetItemText(m_nItemSelected, 1);
	
	int nByte =  dvr::GetInputNumeric(this,csComment, csCaption,b );

	if (nByte == -1)
		return;
	if (nByte > 255)
		return;
	csValue.Format(L"%03i",nByte);
	pListEBYTE->SetItemText(m_nItemSelected,3,csValue);
		
	*pResult = 0;
}

void CMd100_dlg::OnDblclkListEword(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CListCtrl* pListEWORD = (CListCtrl*)GetDlgItem(IDC_LIST_EWORD); 
	m_nItemSelected =  pListEWORD->GetNextItem(-1,LVNI_SELECTED);
	CString csValue, csComment, csCaption;
	WORD w;
	
	if (m_nItemSelected == -1)
	{
		LOG_OUT_ERROR(L"CMd100_dlg::OnDblclkListEword - Select an element !")
		return;
	}
	
	csValue = pListEWORD->GetItemText(m_nItemSelected,3);
	csComment = pListEWORD->GetItemText(m_nItemSelected, 4);
	csCaption = pListEWORD->GetItemText(m_nItemSelected, 1);
	w = _wtoi(csValue);

	int nByte =  dvr::GetInputNumeric(this,csComment, csCaption,w );
	csValue.Format(L"%06i",nByte);
	pListEWORD->SetItemText(m_nItemSelected,3,csValue);

	*pResult = 0;
}

void CMd100_dlg::OnButtonEbyteUpdate() 
{
	CListCtrl* pListEBYTE = (CListCtrl*)GetDlgItem(IDC_LIST_EBYTE); 
	m_nItemSelected =  pListEBYTE->GetNextItem(-1,LVNI_SELECTED);
	CString csValue;
	CString csAdress;
	CString csMessage;
	
	if (m_nItemSelected == -1)	{
		LOG_OUT_ERROR(L"CMd100_dlg::OnButtonEbyteUpdate - Select an element !")
		return;
	}

	TelegramFabricLib::IMTelegram* pIMTelegram ;
	HRESULT hr;
	if (GetFabric())
	{
		while (m_nItemSelected != -1)
		{	
			csAdress = pListEBYTE->GetItemText(m_nItemSelected,0);
			WORD a;
			if(FALSE== CNumberUtility::HexToWord(csAdress,a))
				break;

			csValue = pListEBYTE->GetItemText(m_nItemSelected,3);
			BYTE b = _wtoi(csValue);
				
			hr = m_pIFabric->WriteEpprom(a, b,  (IUnknown**)&pIMTelegram );
			if(hr == S_OK )	{
				if (S_OK ==	m_pISerPort->SendDeTelTelegram(pIMTelegram))	{
					MsgReceived();
					csMessage.Format(L"eprom value %s at adress %s is written",csValue ,csAdress );
					LOG_OUT_NOTIFY(csMessage);
				}
				else {
					LOG_OUT_DEBUG(L"CMd100_dlg::OnButtonEbyteUpdate - can not send Telegram ");
					// release telegram
					pIMTelegram->Release();
					break;
				}
				// release telegram
				pIMTelegram->Release();
				m_nItemSelected =  pListEBYTE->GetNextItem(m_nItemSelected,LVNI_SELECTED);
			}	
		}
	}
	else {
		LOG_OUT_DEBUG(L"CMd100_dlg::OnButtonEbyteUpdate - can not create fabric")
	}	

	return;

}

void CMd100_dlg::OnButtonEbyteRead() 
{
	CListCtrl* pListEBYTE = (CListCtrl*)GetDlgItem(IDC_LIST_EBYTE); 
	m_nItemSelected =  pListEBYTE->GetNextItem(-1,LVNI_SELECTED);
	CString csValue;
	CString csAdress;
	CString csMessage;
	
	if (m_nItemSelected == -1)	{
		LOG_OUT_ERROR(L"CMd100_dlg::OnButtonEbyteRead - Select an element !")
		return;
	}
	csAdress = pListEBYTE->GetItemText(m_nItemSelected,0);
	WORD a;
	if(FALSE== CNumberUtility::HexToWord(csAdress,a))
		return;

	TelegramFabricLib::IMTelegram* pIMTelegram ;
	HRESULT hr;
	
	if (GetFabric()) 
	{
		hr = m_pIFabric->ReadEpprom(a, (IUnknown**)&pIMTelegram );
		if(hr == S_OK )
		{	if (S_OK ==	m_pISerPort->SendDeTelTelegram(pIMTelegram))
			{
				BOOL bErr = FALSE; 
				DPortLib::ISerialSink *pSS = NULL;
				m_pSink->QueryInterface(DPortLib::IID_ISerialSink, (void **) &pSS) ;
				if (pSS)	
				{
					pSS->get_error((long*)&bErr);
					pSS->Release();
				}
			if (bErr == FALSE)	
			{
				MsgReceived();
				csMessage.Format(L"eprom value %s at adress %s is read", m_csMessage,csAdress );
				LOG_OUT_NOTIFY(csMessage);

				// set read value into list place
				csValue.Format(L"0x%s",m_csMessage.Mid(5,2));
				pListEBYTE->SetItemText(m_nItemSelected,3,csValue);
			}
			else 	
			{
				csMessage.Format(L"error !");
				LOG_OUT_ERROR(csMessage);
			}
			}
			else 	
			{
				LOG_OUT_DEBUG(L"CMd100_dlg::OnButtonEbyteRead - can not send Telegram ");
			}
			// release telegram
			pIMTelegram->Release();
			}	
	}
}

void CMd100_dlg::OnButtonEbyteReadButch() 
{
	CListCtrl* pListEBYTE = (CListCtrl*)GetDlgItem(IDC_LIST_EBYTE); 
	//m_nItemSelected =  pListEBYTE->GetNextItem(-1,LVNI_SELECTED);
	CString csValue;
	CString csAdress;
	CString csMessage;
	WORD a;
	BOOL bVersucht = TRUE;
	TelegramFabricLib::IMTelegram* pIMTelegram ;
	HRESULT hr;

	BeginWaitCursor();
	
	if (GetFabric())
	{
		int nItemSelected =  pListEBYTE->GetNextItem(-1,LVNI_SELECTED);
		while (nItemSelected != -1)
		{
			csMessage.Format(L"%i", nItemSelected);
			LOG_OUT_NOTIFY(csMessage);
			csAdress = pListEBYTE->GetItemText(nItemSelected,0);
			if(FALSE== CNumberUtility::HexToWord(csAdress,a))
				break;
		
			hr = m_pIFabric->ReadEpprom(a, (IUnknown**)&pIMTelegram );
			if(hr == S_OK )
			{
				if (S_OK ==	m_pISerPort->SendDeTelTelegram(pIMTelegram))
				{
					MsgReceived();
					csMessage.Format(L"eprom value %s at adress %s is read",csValue ,csAdress );
					LOG_OUT_NOTIFY(csMessage);

					// set read value into list place
					csValue.Format(L"0x%s",m_csMessage.Mid(3,2));
					BYTE b;
					CNumberUtility::HexToByte(csValue, b);
					csValue.Format(L"%03i", b);
					pListEBYTE->SetItemText(nItemSelected,3,csValue);
					LOG_OUT_NOTIFY(csMessage);

				}
				else 
				{
					LOG_OUT_DEBUG(L"CMd100_dlg::OnButtonEbyteReadButch - can not send Telegram ");
					bVersucht = FALSE;
				}
				// release telegram
				pIMTelegram->Release();
			}	

			if (bVersucht==FALSE)
				break;
	
			Beep(100,100);
			nItemSelected =  pListEBYTE->GetNextItem(nItemSelected,LVNI_SELECTED);
		}
	
	}
	EndWaitCursor();
}

void CMd100_dlg::OnButtonEwordUpdate() 
{
	CListCtrl* pListEWORD = (CListCtrl*)GetDlgItem(IDC_LIST_EWORD); 
	m_nItemSelected =  pListEWORD->GetNextItem(-1,LVNI_SELECTED);
	CString csValue;
	CString csAdress;
	CString csMessage;

	
	if (m_nItemSelected == -1)
	{
		LOG_OUT_ERROR(L"Select an element !")
		return;
	}

	csAdress = pListEWORD->GetItemText(m_nItemSelected,0);
	WORD a;
	if(FALSE== CNumberUtility::HexToWord(csAdress,a))
		return;

	csValue = pListEWORD->GetItemText(m_nItemSelected,3);
	WORD w;
	if(FALSE== CNumberUtility::HexToWord(csValue,w))
		return;

	TelegramFabricLib::IMTelegram* pIMTelegram ;
	HRESULT hr;

	// get fabric
	if (GetFabric())
	{
		hr = m_pIFabric->WriteEppromWord(a, w,  (IUnknown**)&pIMTelegram );
		if(hr == S_OK )
		{
			if (S_OK ==	m_pISerPort->SendDeTelTelegram(pIMTelegram))
			{
				MsgReceived();
				csMessage.Format(L"eprom value(word) %s at adress %s is written",csValue ,csAdress );
				LOG_OUT_NOTIFY(csMessage);

			}
			else 
			{
				LOG_OUT_DEBUG(L"CMd100_dlg::OnButtonEwordUpdate - can not send Telegram ");
			}
			// release telegram
			pIMTelegram->Release();
		}	
	
	}
	else 
	{
		LOG_OUT_DEBUG(L"CMd100_dlg::OnButtonEwordUpdate - can not create fabric")
	}
}

void CMd100_dlg::OnButtonEwordRead() 
{
	CListCtrl* pListEWORD = (CListCtrl*)GetDlgItem(IDC_LIST_EWORD); 
	m_nItemSelected =  pListEWORD->GetNextItem(-1,LVNI_SELECTED);
	CString csValue;
	CString csAdress;
	CString csMessage;
	WORD a,w;
	BYTE Blh[2];

	TelegramFabricLib::IMTelegram* pIMTelegram ;
	HRESULT hr;

	// get fabric
	BeginWaitCursor();

	if (GetFabric())
	{

		csAdress = pListEWORD->GetItemText(m_nItemSelected,0);
		if(FALSE== CNumberUtility::HexToWord(csAdress,a))
			return;
		
		for (int i = 0; i < 2; i++)
		{
			hr = m_pIFabric->ReadEpprom(a+i, (IUnknown**)&pIMTelegram );
			if(hr == S_OK )
			{
				if (S_OK ==	m_pISerPort->SendDeTelTelegram(pIMTelegram))
				{
					MsgReceived();
					csValue.Format(L"0x%s",m_csMessage.Mid(3,2));
					CNumberUtility::HexToByte(csValue,Blh[i]);
					csMessage.Format(L"eprom value %s at adress 0x%x is read",csValue ,a+i );
					LOG_OUT_NOTIFY(csMessage);
					}
				else 
				{
					LOG_OUT_DEBUG(L"CMd100_dlg::OnButtonEwordRead - can not send Telegram ");
				}
				// release telegram
				pIMTelegram->Release();
			}	
		}
		// into list
		w =  CNumberUtility::TwoBytetoWord(Blh[0], Blh[1]) ;
		csValue.Format(L"0x%04x",w);
		pListEWORD->SetItemText(m_nItemSelected,3,csValue);
	}
	EndWaitCursor();	
}

void CMd100_dlg::OnDestroy() 
{
	// clean up
	DeleteObject(m_hBMDefault);	
	DeleteObject(m_hBMUpdate);	
	DeleteObject(m_hBMRetrive);	
	DeleteObject(m_hBMReset);	
	DeleteObject(m_hBMHalt);	
	DeleteObject(m_hBMContinue);	

	CDialog::OnDestroy();
}

void CMd100_dlg::OnButtonHalt() 
{
	TelegramFabricLib::IMTelegram* pIMTelegram ;
	HRESULT hr;

	// get fabric
	if (GetFabric())
	{
		hr = m_pIFabric->Hlt((IUnknown**)&pIMTelegram);
		{
			if (S_OK ==	m_pISerPort->SendDeTelTelegram(pIMTelegram))
			{
				//MsgSlave();	
			}
			else 
			{
				LOG_OUT_DEBUG(L"CMd100_dlg::OnButtonHalt - can not send Telegram ");
			}
			// release telegram
			pIMTelegram->Release();
		}	

	}
	else 
	{
		LOG_OUT_DEBUG(L"CMd100_dlg::OnButtonHalt - can not create fabric")
	}			
}

void CMd100_dlg::OnButtonContinue() 
{
	TelegramFabricLib::IMTelegram* pIMTelegram ;
	HRESULT hr;

	// get fabric
	if (GetFabric())
	{
		hr = m_pIFabric->Continue((IUnknown**)&pIMTelegram);
		{
			if (S_OK ==	m_pISerPort->SendDeTelTelegram(pIMTelegram))
			{
				//MsgSlave();	
			}
			else 
			{
				LOG_OUT_DEBUG(L"CMd100_dlg::OnButtonContinue - can not send Telegram ");
			}
			// release telegram
			pIMTelegram->Release();
		}	
	}
	else 
	{
		LOG_OUT_DEBUG(L"CMd100_dlg::OnButtonContinue - can not create fabric")
	}
}

void CMd100_dlg::OnButtonBrs() 
{
	CString csEditor;
	CString csApplications;
	CString csAllFiles;
	CString csBrowse = L"browse";
	CString csSymbolFile ;
	CString strFilter = csApplications + L"(syb)|*.syb|symbol (*.syb)|*.syb|all files (*.*)|*.*||";
	CFileDialog OpenFileDialog(TRUE, 
		NULL, 
		csSymbolFile.GetBuffer(0), //NULL, 
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, 
		strFilter);
	
	OpenFileDialog.m_ofn.lpstrTitle = csBrowse;
	if(OpenFileDialog.DoModal() == IDOK)
	{
		m_csBrs = OpenFileDialog.m_ofn.lpstrFile ; 
		_ReadFromSymbolFile(m_csBrs);
		AfxGetApp()->WriteProfileString(L"dvr", L"SymbolFile", m_csBrs );
		CDialog::OnInitDialog();
	}					
}

void CMd100_dlg::_ReadFromSymbolFile(CString csFile)
{
	int i = 0;
	POSITION pos = 0;
	CListCtrl* pListEBYTE =  (CListCtrl*) GetDlgItem(IDC_LIST_EBYTE);
	CListCtrl* pListEWORD =  (CListCtrl*) GetDlgItem(IDC_LIST_EWORD);
	TRoot root;
	root.ReadFromSymbolFile(csFile);
	int nSel = 0;
	CString csDumy = L"";

	for ( i = 0; i< pListEBYTE->GetItemCount(); i++)
	{
		pListEBYTE->SetItemText(nSel,4, L"");
	}
	for ( i = 0; i< pListEWORD->GetItemCount(); i++)
	{
		pListEWORD->SetItemText(nSel,4, L"");
	}

	// EpromBytes
	pos = root.GetEpromBytes().GetHeadPosition();
	while (pos)
	{
		try
		{
			TSymbol syb = (root.GetEpromBytes()).GetNext(pos);	
			csDumy = syb.GetRegName();
			csDumy.TrimLeft(L"EB");
			nSel = _wtoi(csDumy.GetBuffer(0));
			
			pListEBYTE->SetItemText(nSel,4,syb.GetComment());
			
		} catch(...) {}
	}
	
	// EpromWords
	pos = root.GetEpromWords().GetHeadPosition();
	while (pos)
	{
		try
		{
			TSymbol syb = (root.GetEpromWords()).GetNext(pos);	
			csDumy = syb.GetRegName();
			csDumy.TrimLeft(L"EW");
			nSel = _wtoi(csDumy.GetBuffer(0));
			pListEWORD->SetItemText(nSel,4,syb.GetComment());
		} catch(...) {}
	}
	
} 

void CMd100_dlg::OnRadioBytes() 
{
	CListCtrl* pListEBYTE =  (CListCtrl*) GetDlgItem(IDC_LIST_EBYTE);
	CListCtrl* pListEWORD =  (CListCtrl*) GetDlgItem(IDC_LIST_EWORD);
	pListEBYTE->ShowWindow(SW_SHOW);
	pListEWORD->ShowWindow(SW_HIDE);
	
}

void CMd100_dlg::OnRadioWords() 
{
	CListCtrl* pListEBYTE =  (CListCtrl*) GetDlgItem(IDC_LIST_EBYTE);
	CListCtrl* pListEWORD =  (CListCtrl*) GetDlgItem(IDC_LIST_EWORD);
	pListEWORD->ShowWindow(SW_SHOW);
	pListEBYTE->ShowWindow(SW_HIDE);
	
}

void CMd100_dlg::OnButtonBrsEepromHex() 
{
	CString csValue;
	CString csAllFiles;
	CString csSymbolFile ;
	CString strFilter = L"(hex)|*.hex|hex files (*.hex)|*.hex| all files (*.*)|*.*||";
	CFileDialog OpenFileDialog(TRUE, 
		NULL, 
		m_csEEPROMHexFile,// NULL, 
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, 
		strFilter);
	if(OpenFileDialog.DoModal() == IDOK)
	{
		m_csEEPROMHexFile = OpenFileDialog.m_ofn.lpstrFile;
		AfxGetApp()->WriteProfileString(L"DIALOGS", L"EpromHexFile", m_csEEPROMHexFile );
		_UPDATE();
		CDialog::OnInitDialog();
	}
}

void CMd100_dlg::_UPDATE() 
{
	int i = 0;
	int	nEBYTEcount ;//VM08_EPROM_BYTE_COUNT;
	int	nEWORDcount ;//VM08_EPROM_WORD_COUNT;
	unsigned char bf[5000];
	MasterTable MTBuffer;
	IHexFrmt frmt;

	if (frmt.Read(bf,5000,m_csEEPROMHexFile) == TRUE  )
	{
		SetWindowText(L"Master Table ["+m_csEEPROMHexFile+"]");

		// copy to buffer to controls 
		memcpy(&MTBuffer, &bf,  tMLEN);
		
		// Processor
		if (MTBuffer.DEVL < 3 )
		{
			if(MTBuffer.DEVL == VM_08)
			{
				m_nProcessor  = VM_08;
				nEBYTEcount = VM08_EPROM_BYTE_COUNT;
				nEWORDcount = VM08_EPROM_WORD_COUNT;
			}
			else if (MTBuffer.DEVL == VM_16)
			{
				m_nProcessor  = VM_16;
				nEBYTEcount = VM16_EPROM_BYTE_COUNT;
				nEWORDcount = VM16_EPROM_WORD_COUNT;
			}

			else if (MTBuffer.DEVL == VM_32)
			{
				m_nProcessor  = VM_32;
				nEBYTEcount = VM32_EPROM_BYTE_COUNT;
				nEWORDcount = VM32_EPROM_WORD_COUNT;
			}
		}

		CListCtrl* pListEBYTE =  (CListCtrl*) GetDlgItem(IDC_LIST_EBYTE);
		CListCtrl* pListEWORD =  (CListCtrl*) GetDlgItem(IDC_LIST_EWORD);
		BYTE  b;
		WORD  w;
		CString csValue;

		for (  i = 	0; i <    nEBYTEcount; i++)
		{
			b = bf[VM_EPROM_BYTE_BASE + i];
			csValue.Format(L"%03i",b);
			pListEBYTE->SetItemText(i,3,csValue.GetBuffer(0));
		}

		for ( i = 	0; i <    nEWORDcount; i++)
		{
			w = bf[VM_EPROM_BYTE_BASE + m_nEBYTEcount + 2*i+1];
			w = w << 8;
			b = bf[VM_EPROM_BYTE_BASE + m_nEBYTEcount + 2*i];
			w = w | b;
			csValue.Format(L"%06i",w);
			pListEWORD->SetItemText(i,3,csValue.GetBuffer(0));
		}

	}
	else return ;
}



void CMd100_dlg::OnCbnSelchangeComboTakt()
{
	// TODO: Add your control notification handler code here
}
