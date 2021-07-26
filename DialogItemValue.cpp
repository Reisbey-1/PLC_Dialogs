// DialogItemValue.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "resource.h"
#include "DialogItemValue.h"
/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CDialogItemValue 
CDialogItemValue::CDialogItemValue(int nItemValueByte, CWnd* pParent /*=NULL*/)
	: CDialog(CDialogItemValue::IDD, pParent), m_nItemValueByte(nItemValueByte)
{
	//{{AFX_DATA_INIT(CDialogItemValue)
	//}}AFX_DATA_INIT
}

void CDialogItemValue::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogItemValue)
	DDX_Text(pDX, IDC_EDIT_ITEM_VALUE_BYTE, m_nItemValueByte);
	DDV_MinMaxInt(pDX, m_nItemValueByte, 0, 255);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDialogItemValue, CDialog)
//{{AFX_MSG_MAP(CDialogItemValue)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen für Nachrichten CDialogItemValue 
void CDialogItemValue::OnOK() 
{
	UpdateData();
	CDialog::OnOK();
}

BOOL CDialogItemValue::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CEdit * pItem = (CEdit *)GetDlgItem(IDC_EDIT_ITEM_VALUE_BYTE) ;
	pItem->SetFocus();
	pItem->SetSel(0,-1);
	return FALSE;
					// return TRUE unless you set the focus to a control
					// EXCEPTION: OCX-Eigenschaftenseiten sollten FALSE zurückgeben
}
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CDialogItemValueWord 
CDialogItemValueWord::CDialogItemValueWord(int nItemValueByte, CWnd* pParent /*=NULL*/)
	: CDialog(CDialogItemValueWord::IDD, pParent) , m_nItemValueByte(nItemValueByte)
{
	//{{AFX_DATA_INIT(CDialogItemValueWord)
	//}}AFX_DATA_INIT
}

void CDialogItemValueWord::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogItemValueWord)
	DDX_Text(pDX, IDC_EDIT_ITEM_VALUE_BYTE, m_nItemValueByte);
	DDV_MinMaxInt(pDX, m_nItemValueByte, 0, 0xFFFF);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDialogItemValueWord, CDialog)
//{{AFX_MSG_MAP(CDialogItemValueWord)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen für Nachrichten CDialogItemValue 
void CDialogItemValueWord::OnOK() 
{	UpdateData();
	CDialog::OnOK();
}
BOOL CDialogItemValueWord::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CEdit * pItem = (CEdit *)GetDlgItem(IDC_EDIT_ITEM_VALUE_BYTE) ;
	pItem->SetFocus();
	pItem->SetSel(0,-1);
	return FALSE;
	//return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX-Eigenschaftenseiten sollten FALSE zurückgeben
}