// MdxxMonitor_dlg.cpp: Implementierungsdatei
//
#include "stdafx.h"

#include <afxcmn.h>
#include <afxdlgs.h>


#include "resource.h"
#include "MdxxMonitor_dlg.h"
//#include "SerialPortSink.h"

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CMdxxMonitor_dlg 
/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//  The Rs232Thread (Rs232 thread ) Function.                             //
//                                                                         //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////


UINT CMdxxMonitor_dlg::Rs232Thread( LPVOID pParam )
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// Cast the void pointer passed to the thread back to
	// a pointer of CSerialPort class
	//CMdxxMonitor_dlg *dlg = (CMdxxMonitor_dlg*)pParam;
	//HWND * pHwnd = (HWND*) (pParam) ;
	
	//CMdxxMonitor_dlg dlg(CWnd::FromHandle(*pHwnd));

	
	CMdxxMonitor_dlg *dlg = (CMdxxMonitor_dlg*)pParam;

	
	
	// Set the status variable in the dialog class to
	// TRUE to indicate the thread is running.
	dlg->RunMe();	
	return 0;
}

void  CMdxxMonitor_dlg::RunMe()
{	
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CString csSelected;
	HRESULT hr;
	TelegramFabricLib::IMTelegram* pReadRAM     = NULL;


	CFileUtility::existFile("...........");
/*
	CoInitialize(NULL);
	if (m_pSink)
	m_pSink->Release();
	
	// connection to serial port
	m_pSink = new CSerialPortSink;
	hr = m_pISerPort->QueryInterface(IID_IConnectionPointContainer, (void**) &m_pContainer);

	// find connection point
	hr = m_pContainer->FindConnectionPoint(DPORTLib::IID__ISerPortEvents, &m_pConnectionPoint);
	
	// cokie
	hr = m_pConnectionPoint->Advise(m_pSink, &m_dwCokie);	
*/

	// signal thread is startet 
	SetEvent(m_hThreadStartet);
	ResetEvent(m_hShutdownEvent);

	// begin forever loop.  This loop will run as long as the thread is alive.


	for (;;) 
	//while(1)
	{ 

		// read device over RS232
		if (m_bStart == true)
		{
			CString csMessage;

			CString csError;
			CString csInfo;
			CString csDumy;
			
			CListCtrl* pLisRamBild =  (CListCtrl*) GetDlgItem(IDC_LIST_RAM_BILD);

			
			unsigned char length;
			unsigned short usAddress;

			for (int i = 0; i < pLisRamBild->GetItemCount(); i++)
			{
				//i = 3;
				CString csRegName = pLisRamBild->GetItemText(i,2);
				csSelected = pLisRamBild->GetItemText(i,6);
				if (csSelected.CompareNoCase(L"-") ==0)
					continue;

				length = CAlcUtilities::IsValid2Register(csRegName,  m_nVm) ;
				CString csAddress = pLisRamBild->GetItemText(i,3);
				CNumberUtility::HexToWord(csAddress, (WORD) usAddress);

				//IFabric* pIFabric = NULL;
				
				// cursor wait
				BeginWaitCursor();
				
				//HRESULT hr =  CFabric::GetFabric(&pIFabric) ;
				if (GetFabric())
				{
					hr = m_pIFabric->ReadRAM(usAddress, length,(IUnknown**)&pReadRAM);
					if (hr != S_OK)
					{
						LOG_OUT_ERROR("<ERROR> CMdxxMonitor_dlg::RunMe - cannot create telegram object ") 
				
					}

				}
				else
				{
					LOG_OUT_ERROR("CMdxxMonitor_dlg::RunMe - cannot create fabric ") 
					//if (pReadRAM) 
					//	pReadRAM->Release();
					break;
				}
				
				if (m_pISerPort == NULL)
				{
					//csError.LoadString(IDS_ERR_NOPORTOBJECT);
					LOG_OUT_ERROR("CMdxxMonitor_dlg::RunMe - serial port object is not available") 
					break ; //return ;
				}
				
				
				if (hr == S_OK) 
				{
					// clear sink;
					m_pSink->ClearError();
					hr = m_pISerPort->SendDeTelTelegram(pReadRAM);
					if (hr != S_OK)
					{
						//csError.LoadString(IDS_ERR_CANNOTWRITE_MODULTYPE_TELEGRAM);
						LOG_OUT_ERROR("CMdxxMonitor_dlg::RunMe - can not write (read-ram) telegram") 
						break ;
						//pReadRAM->Release();
						//return ;
					}
					
					int nRamValue;

					unsigned char  *buffer;
					m_pSink->get_ReceiveBuffer(&buffer);
					BYTE n0  = buffer[0];
					BYTE n1  = buffer[1]; 
					BYTE n2  = buffer[2]; 
					BYTE n3  = buffer[3];
				
					// Ram as byte
					if ( n0 == XON && n2 == XOF && length== 1)
					{
						nRamValue = n1  ;
					}
					
					// ram as word
					else if (n0 == XON && n3 == XOF && length== 2)
					{
						nRamValue = n2  ;
						nRamValue = nRamValue << 8  ;
						//nRamValue = (( )) ;
						nRamValue = (nRamValue | n1);
					
					}
					else 
						nRamValue = -1;

					CString csValue;
					csValue.Format(L"0x%02x",nRamValue);
					pLisRamBild->SetItemText(i,4,csValue.GetBuffer(0));

						

				}
				if (pReadRAM)
					pReadRAM->Release();
			}
			
		
		}
		else 
		{
		
			//m_bStart
			int nhalt = 1;
		}
		
		// wait until respons to telegram is obtained
		if (WaitForSingleObject(m_hShutdownEvent, m_nWaitDurationForShutDown) == WAIT_OBJECT_0)
		{
			// unadvise !! it destroys sink object ;
			//m_pConnectionPoint->Unadvise(m_dwCokie);	

			//m_pConnectionPoint->Release();
			//m_pContainer->Release();
			
			SetEvent (m_hThreadEndedEvent);
			LOG_OUT_INFO(L"CMdxxMonitor_dlg::RunMe - Rs232 thread is ended  ")
			break ;
		}	
	
	}
/**/
}

CMdxxMonitor_dlg::CMdxxMonitor_dlg(CWnd* pParent /*=NULL*/ , int nVm)
	: CDialog(CMdxxMonitor_dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMdxxMonitor_dlg)
	m_csSymbolFile = _T("");
	//}}AFX_DATA_INIT

	m_pSink = 0;
	m_hThreadStartet	= CreateEvent(NULL, TRUE, FALSE, NULL);
	m_hShutdownEvent	= CreateEvent(NULL, TRUE, FALSE, NULL);
	m_hThreadEndedEvent	= CreateEvent(NULL, TRUE, FALSE, NULL);
	m_pThread			= NULL;
	m_bStart			= false;
	m_nVm				= nVm;
	m_nWaitDurationForShutDown = 100;

	m_pIFabric          = NULL;
}


void CMdxxMonitor_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMdxxMonitor_dlg)
	DDX_Text(pDX, IDC_EDIT_SYMBOL_FILE, m_csSymbolFile);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMdxxMonitor_dlg, CDialog)
	//{{AFX_MSG_MAP(CMdxxMonitor_dlg)
	ON_BN_CLICKED(IDC_BUTTON_BROWSE, OnButtonBrowse)
	ON_BN_CLICKED(IDC_BUTTON_START, OnButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_STOP, OnButtonStop)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_RAM_BILD, OnDblclkListRamBild)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen für Nachrichten CMdxxMonitor_dlg 

BOOL CMdxxMonitor_dlg::OnInitDialog() 
{
	CDialog::OnInitDialog();


	InitMe();
	CDialog::OnInitDialog();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX-Eigenschaftenseiten sollten FALSE zurückgeben
}

TelegramFabricLib::IFabric* CMdxxMonitor_dlg::GetFabric()
{
	HRESULT hr = S_OK;  // 0x800401f0
	try
	{
		if (m_pIFabric == NULL)
		{
		CoInitialize(NULL);
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

void CMdxxMonitor_dlg::InitMe() 
{
	CWinApp* pApp = AfxGetApp();
	// eprom word list
	CListCtrl* pLisRamBild =  (CListCtrl*) GetDlgItem(IDC_LIST_RAM_BILD);
	pLisRamBild->InsertColumn(0, L"Name",LVCFMT_LEFT, 50);
	pLisRamBild->InsertColumn(1, L"Type",LVCFMT_LEFT, 60);
	pLisRamBild->InsertColumn(2, L"Register",LVCFMT_LEFT, 60);
	pLisRamBild->InsertColumn(3, L"Adress",LVCFMT_LEFT, 50);

	pLisRamBild->InsertColumn(4, L"Value",LVCFMT_LEFT, 50);
	
	pLisRamBild->InsertColumn(5, L"Comment",LVCFMT_LEFT, 130);
	pLisRamBild->InsertColumn(6, L"Selection",LVCFMT_LEFT, 75);

	pLisRamBild->SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_ONECLICKACTIVATE  );

	m_csSymbolFile =  pApp->GetProfileString(L"Monitor", L"SymbolFile", L"");
	FillList();

	
	/// 
	ResetEvent(m_hThreadStartet);

	if (!(m_pThread = AfxBeginThread(Rs232Thread, this)))
	// if (!(m_pThread = AfxBeginThread(Rs232Thread, &m_hWnd)))
	{
		LOG_OUT_WARNING(L"CMdxxMonitor_dlg::InitMe - can not start communicatin thread")
		return;
	}
	
	// wait until respons to telegram is obtained
	if (WaitForSingleObject(m_hThreadStartet, 5000) == WAIT_TIMEOUT)
	{
		LOG_OUT_ERROR(L"CMdxxMonitor_dlg::InitMe - can not start communicatin thread, time is out !  ")
		return ;
	}	
	
		LOG_OUT_INFO(L"CMdxxMonitor_dlg::InitMe - communicatin thread is started ")
	
	m_pThread->SetThreadPriority(THREAD_PRIORITY_HIGHEST);
	

}

void CMdxxMonitor_dlg::OnDestroy() 
{

	OnButtonStop() ;

	CWinApp* pApp = AfxGetApp();
	CDialog::OnDestroy();
	pApp->WriteProfileString(L"Monitor", L"SymbolFile", m_csSymbolFile.GetBuffer(0) );

/*	
	// unadvise !! it destroys sink object ;
	m_pConnectionPoint->Unadvise(m_dwCokie);	

	m_pConnectionPoint->Release();
	m_pContainer->Release();
*/

	SetEvent(m_hShutdownEvent);

	// wait until respons to telegram is obtained
	if (WaitForSingleObject(m_hThreadEndedEvent, 15000) == WAIT_TIMEOUT)
	{
		LOG_OUT_ERROR(L"CMdxxMonitor_dlg::InitMe - can not end  Rs232 thread. time is out !  ")
		return ;
	}	
}



void CMdxxMonitor_dlg::OnButtonBrowse() 
{
	//AFX_MANAGE_STATE(AfxGetStaticModuleState())

	CString csEditor;
	CString csApplications;
	CString csAllFiles;
	CString csBrowse;
/*	

	OPENFILENAME lpofn ;
	GetOpenFileName(&lpofn);
	   // address of structure with initialization 
                         // data
	
*/	
	csAllFiles.LoadString(IDS_STRING_TAG_ALLFILES);
	
	CString strFilter = csApplications + "(syb)|*.syb|sembol (*.syb)|*.syb|"+ csAllFiles + " (*.*)|*.*||";
	CFileDialog OpenFileDialog(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, strFilter);
	
	if(OpenFileDialog.DoModal() == IDOK)
	{
		m_csSymbolFile = OpenFileDialog.m_ofn.lpstrFile;
		
		FillList();

		CDialog::OnInitDialog();	
	}
	

}

void CMdxxMonitor_dlg::FillList() 
{
	CListCtrl* pLisRamBild =  (CListCtrl*) GetDlgItem(IDC_LIST_RAM_BILD);
	TRoot  root;
	root.ReadFromSymbolFile(m_csSymbolFile);
	
	pLisRamBild->DeleteAllItems();
	// analog inputs
	TAnalogInputs analogInputs = root.GetAnalogInputs();
	POSITION pos = analogInputs.GetHeadPosition();
	int i = 0;
	while (pos)
	{
		TSymbol syb = analogInputs.GetNext(pos);
		pLisRamBild->InsertItem(i,syb.GetName().GetBuffer(0));
		pLisRamBild->SetItemText(i,1,syb.GetType().GetBuffer(0));
		pLisRamBild->SetItemText(i,2,syb.GetRegName().GetBuffer(0));
		pLisRamBild->SetItemText(i,3,syb.GetAddress().GetBuffer(0));
		pLisRamBild->SetItemText(i,5,syb.GetComment().GetBuffer(0));
		pLisRamBild->SetItemText(i,6, L"-");
	
	}
	// analog outputs
	TAnalogOutputs analogOutputs = root.GetAnalogOutputs();
	pos = analogOutputs.GetHeadPosition();
	i = 0;
	while (pos)
	{
		TSymbol syb = analogOutputs.GetNext(pos);
		pLisRamBild->InsertItem(i,syb.GetName().GetBuffer(0));
		pLisRamBild->SetItemText(i,1,syb.GetType().GetBuffer(0));
		pLisRamBild->SetItemText(i,2,syb.GetRegName().GetBuffer(0));
		pLisRamBild->SetItemText(i,3,syb.GetAddress().GetBuffer(0));
		pLisRamBild->SetItemText(i,5,syb.GetComment().GetBuffer(0));
		pLisRamBild->SetItemText(i,6, L"-");
	}
	
	// Words
	TWords words = root.GetWords();
	pos = words.GetHeadPosition();
	i = 0;
	while (pos)
	{
		TSymbol syb = words.GetNext(pos);
		pLisRamBild->InsertItem(i,syb.GetName().GetBuffer(0));
		pLisRamBild->SetItemText(i,1,syb.GetType().GetBuffer(0));
		pLisRamBild->SetItemText(i,2,syb.GetRegName().GetBuffer(0));
		pLisRamBild->SetItemText(i,3,syb.GetAddress().GetBuffer(0));
		pLisRamBild->SetItemText(i,5,syb.GetComment().GetBuffer(0));
		pLisRamBild->SetItemText(i,6, L"-");
	}

	// Bytes
	TBytes bytes = root.GetBytes();
	pos = bytes.GetHeadPosition();
	i = 0;
	while (pos)
	{
		TSymbol syb = bytes.GetNext(pos);
		pLisRamBild->InsertItem(i,syb.GetName().GetBuffer(0));
		pLisRamBild->SetItemText(i,1,syb.GetType().GetBuffer(0));
		pLisRamBild->SetItemText(i,2,syb.GetRegName().GetBuffer(0));
		pLisRamBild->SetItemText(i,3,syb.GetAddress().GetBuffer(0));
		pLisRamBild->SetItemText(i,5,syb.GetComment().GetBuffer(0));
		pLisRamBild->SetItemText(i,6, L"-");
	}

	// DigitalOutputs
	TDigitalOutputs digitaloutputs = root.GetOutputs();
	pos = digitaloutputs.GetHeadPosition();
	i = 0;
	while (pos)
	{
		TSymbol syb = digitaloutputs.GetNext(pos);
		pLisRamBild->InsertItem(i,syb.GetName().GetBuffer(0));
		pLisRamBild->SetItemText(i,1,syb.GetType().GetBuffer(0));
		pLisRamBild->SetItemText(i,2,syb.GetRegName().GetBuffer(0));
		pLisRamBild->SetItemText(i,3,syb.GetAddress().GetBuffer(0));
		pLisRamBild->SetItemText(i,5,syb.GetComment().GetBuffer(0));
		pLisRamBild->SetItemText(i,6, L"-");
	}

	// DigitalInputs
	TDigitalInputs digitalinputs = root.GetInputs();
	pos = digitalinputs.GetHeadPosition();
	i = 0;
	while (pos)
	{
		TSymbol syb = digitalinputs.GetNext(pos);
		pLisRamBild->InsertItem(i,syb.GetName().GetBuffer(0));
		pLisRamBild->SetItemText(i,1,syb.GetType().GetBuffer(0));
		pLisRamBild->SetItemText(i,2,syb.GetRegName().GetBuffer(0));
		pLisRamBild->SetItemText(i,3,syb.GetAddress().GetBuffer(0));
		pLisRamBild->SetItemText(i,5,syb.GetComment().GetBuffer(0));
		pLisRamBild->SetItemText(i,6, L"-");
	}

	// EpromBytes
	TEpromBytes eprombytes = root.GetEpromBytes();
	pos = eprombytes.GetHeadPosition();
	i = 0;
	while (pos)
	{
		TSymbol syb = eprombytes.GetNext(pos);
		pLisRamBild->InsertItem(i,syb.GetName().GetBuffer(0));
		pLisRamBild->SetItemText(i,1,syb.GetType().GetBuffer(0));
		pLisRamBild->SetItemText(i,2,syb.GetRegName().GetBuffer(0));
		pLisRamBild->SetItemText(i,3,syb.GetAddress().GetBuffer(0));
		pLisRamBild->SetItemText(i,5,syb.GetComment().GetBuffer(0));
		pLisRamBild->SetItemText(i,6, L"-");
	}

	// EpromWords
	TEpromWords epromwords = root.GetEpromWords();
	pos = epromwords.GetHeadPosition();
	i = 0;
	while (pos)
	{
		TSymbol syb = epromwords.GetNext(pos);
		pLisRamBild->InsertItem(i,syb.GetName().GetBuffer(0));
		pLisRamBild->SetItemText(i,1,syb.GetType().GetBuffer(0));
		pLisRamBild->SetItemText(i,2,syb.GetRegName().GetBuffer(0));
		pLisRamBild->SetItemText(i,3,syb.GetAddress().GetBuffer(0));
		pLisRamBild->SetItemText(i,5,syb.GetComment().GetBuffer(0));
		pLisRamBild->SetItemText(i,6, L"-");
	}

}


void CMdxxMonitor_dlg::OnButtonStart() 
{
	// Gain ownership of the critical section
	//EnterCriticalSection(&m_csCommunicationSync);
	m_bStart = true;
	//LeaveCriticalSection(&m_csCommunicationSync); 
	LOG_OUT_DEBUG(L"CMdxxMonitor_dlg::OnButtonStart - start ")
}

void CMdxxMonitor_dlg::OnButtonStop() 
{
	// Gain ownership of the critical section
	//EnterCriticalSection(&m_csCommunicationSync);
	m_bStart = false;
	//LeaveCriticalSection(&m_csCommunicationSync); 
	LOG_OUT_DEBUG(L"CMdxxMonitor_dlg::OnButtonStop - stop ")
	
}

void CMdxxMonitor_dlg::OnDblclkListRamBild(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CListCtrl* pLisRamBild =  (CListCtrl*) GetDlgItem(IDC_LIST_RAM_BILD);
	int nItemSelected =  pLisRamBild->GetNextItem(-1,LVNI_SELECTED);
	CString csValue;
	
	if (nItemSelected == -1)
	{
		LOG_OUT_NOTIFY(L"CMdxxMonitor_dlg::OnDblclkListRamBild Select an element !")
		return;
	}
	
	csValue = pLisRamBild->GetItemText(nItemSelected,6);
	if (csValue.CompareNoCase(L"-") == 0)
	{
		pLisRamBild->SetItemText(nItemSelected,6, L"x");
	}
	else
	{
		pLisRamBild->SetItemText(nItemSelected,6, L"-");
	}

	*pResult = 0;
}

void CMdxxMonitor_dlg::OnCancel() 
{
	// TODO: Zusätzlichen Bereinigungscode hier einfügen
	OnDestroy();
	CDialog::OnCancel();
}

void CMdxxMonitor_dlg::OnOK() 
{
	// TODO: Zusätzliche Prüfung hier einfügen
	OnDestroy();
	CDialog::OnOK();
}
