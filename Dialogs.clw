; CLW-Datei enth�lt Informationen f�r den MFC-Klassen-Assistenten

[General Info]
Version=1
ResourceCount=8
ClassCount=8
Class1=CDialogsApp
LastClass=CMd100_dlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "resource.h"
ODLFile=Dialogs.idl
LastPage=0
Class2=CIO28_dlg
Resource1=IDD_DIALOG_MD500_CONFIGURATION
Class3=CMd500_dlg
Resource2=IDD_DIALOG_ME100_CONFIGURATION
Class4=CMd100_dlg
Resource3=IDD_DIALOG_MD1500_CONFIGURATION
Resource4=IDD_DIALOG_LIST_ITEM
Class5=CEmbeddedConfigurator_dlg
Class6=CPageMD100
Resource5=IDD_DIALOG_MD100_CONFIGURATION
Class7=CDialogItemValue
Resource6=IDD_DIALOG_EMBEDDED_32
Class8=CMdxxMonitor_dlg
Resource7=IDD_DIALOG_SLAVE_IO28
Resource8=IDD_DIALOG_MDxx_MONITOR


[CLS:CDialogsApp]
Type=0
HeaderFile=Dialogs.h
ImplementationFile=Dialogs.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC
LastObject=CDialogsApp

[DLG:IDD_DIALOG_SLAVE_IO28]
Type=1
Class=CIO28_dlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308354
Control4=IDC_EDIT_ADDRES,edit,1350631552

[CLS:CIO28_dlg]
Type=0
HeaderFile=IO28_dlg.h
ImplementationFile=IO28_dlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CIO28_dlg

[DLG:IDD_DIALOG_MD500_CONFIGURATION]
Type=1
Class=CMd500_dlg
ControlCount=47
Control1=IDC_COMBO_SLAVE_TYPE,combobox,1344339971
Control2=IDC_EDIT_SLAVE_ADDRESS,edit,1350631552
Control3=IDC_RADIO_VCC,button,1342177289
Control4=IDC_RADIO_RV256,button,1342177289
Control5=IDC_STATIC_COMPRO,static,1342308354
Control6=IDC_RADIO_SPI500,button,1342177289
Control7=IDC_RADIO_SPI500_R,button,1476395017
Control8=IDC_RADIO_TWI,button,1476395017
Control9=IDC_RADIO_TWI_R,button,1476395017
Control10=IDC_STATIC_SLAVEOFFSET,static,1342308354
Control11=IDC_COMBO_SLAVE_OFFSET,combobox,1344339971
Control12=IDC_COMBO_BAUD,combobox,1344339971
Control13=IDC_COMBO_PARITY,combobox,1478557954
Control14=IDC_COMBO_TAKT,combobox,1344339971
Control15=IDC_COMBO_SPI_TAKT,combobox,1478557699
Control16=IDC_COMBO_TWI_TAKT,combobox,1478557699
Control17=IDC_BUTTON_DEFAULT,button,1342242944
Control18=IDC_BUTTON_UPDATE,button,1342242944
Control19=IDC_BUTTON_RETRIEVE,button,1342242944
Control20=IDOK,button,1342242817
Control21=IDCANCEL,button,1342242816
Control22=IDC_TREE_MD500,SysTreeView32,1350631431
Control23=IDC_STATIC_SLAVETYPE,static,1342308354
Control24=IDC_STATIC_SLAVEADDRESS,static,1342308354
Control25=IDC_STATIC,static,1342177801
Control26=IDC_STATIC_LINE1,static,1342177296
Control27=IDC_STATIC_REFVOL,static,1342308354
Control28=IDC_STATIC_LINE2,static,1342177296
Control29=IDC_STATIC_LINE3,static,1342177296
Control30=IDC_STATIC_BAUD,static,1342308354
Control31=IDC_STATIC_PARITY,static,1342308354
Control32=IDC_STATIC_TAKT,static,1342308354
Control33=IDC_STATIC_TABLEOFFSET,static,1342308354
Control34=IDC_EDIT_TABLE_OFFSET,edit,1484849280
Control35=IDC_STATIC_SPI_TAKT,static,1342308354
Control36=IDC_STATIC_TWI_TAKT,static,1342308354
Control37=IDC_STATIC_SPI_COMMENT,static,1342308352
Control38=IDC_STATIC_TWI_COMMENT,static,1342308352
Control39=IDC_STATIC_PROCESSOR,static,1073872898
Control40=IDC_STATIC_MODULE,static,1073872898
Control41=IDC_EDIT_PROCESSOR,edit,1216413824
Control42=IDC_EDIT_MODULE,edit,1216413824
Control43=IDC_STATIC_TAKT_CPU,static,1073872898
Control44=IDC_EDIT_TAKT_CPU,edit,1216413824
Control45=IDC_STATIC,static,1342177287
Control46=IDC_STATIC_LINE4,static,1342177296
Control47=IDC_BUTTON_RESET,button,1342242944

[CLS:CMd500_dlg]
Type=0
HeaderFile=Md500_dlg.h
ImplementationFile=Md500_dlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CMd500_dlg
VirtualFilter=dWC

[DLG:IDD_DIALOG_MD1500_CONFIGURATION]
Type=1
Class=CMd100_dlg
ControlCount=33
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_RADIO_VCC,button,1342177289
Control4=IDC_RADIO_RV256,button,1342177289
Control5=IDC_COMBO_BAUD,combobox,1344339971
Control6=IDC_COMBO_PARITY,combobox,1478557954
Control7=IDC_COMBO_TAKT,combobox,1344339971
Control8=IDC_COMBO_SPI_TAKT,combobox,1478557699
Control9=IDC_COMBO_TWI_TAKT,combobox,1478557699
Control10=IDC_BUTTON_DEFAULT,button,1342242944
Control11=IDC_BUTTON_UPDATE,button,1342242944
Control12=IDC_BUTTON_RETRIEVE,button,1342242944
Control13=IDC_STATIC,static,1342177801
Control14=IDC_STATIC_LINE1,static,1342177296
Control15=IDC_STATIC_REFVOL,static,1342308354
Control16=IDC_STATIC_LINE2,static,1342177296
Control17=IDC_STATIC_LINE3,static,1342177296
Control18=IDC_STATIC_BAUD,static,1342308354
Control19=IDC_STATIC_PARITY,static,1342308354
Control20=IDC_STATIC_TAKT,static,1342308354
Control21=IDC_STATIC_TABLEOFFSET,static,1342308354
Control22=IDC_EDIT_TABLE_OFFSET,edit,1484849280
Control23=IDC_STATIC_SPI_TAKT,static,1342308354
Control24=IDC_STATIC_TWI_TAKT,static,1342308354
Control25=IDC_STATIC_PROCESSOR,static,1342308354
Control26=IDC_STATIC_MODULE,static,1342308354
Control27=IDC_EDIT_PROCESSOR,edit,1484849280
Control28=IDC_EDIT_MODULE,edit,1484849280
Control29=IDC_STATIC_TAKT_CPU,static,1342308354
Control30=IDC_EDIT_TAKT_CPU,edit,1484849280
Control31=IDC_STATIC,static,1342177287
Control32=IDC_STATIC_LINE4,static,1342177296
Control33=IDC_BUTTON_RESET,button,1342242944

[CLS:CMd100_dlg]
Type=0
HeaderFile=Md100_dlg.h
ImplementationFile=Md100_dlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CMd100_dlg
VirtualFilter=dWC

[DLG:IDD_DIALOG_MD100_CONFIGURATION]
Type=1
Class=CPageMD100
ControlCount=46
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_RADIO_VCC,button,1342177289
Control4=IDC_RADIO_RV256,button,1342177289
Control5=IDC_COMBO_PARITY,combobox,1478557954
Control6=IDC_COMBO_TAKT,combobox,1478557699
Control7=IDC_COMBO_SPI_TAKT,combobox,1478557699
Control8=IDC_COMBO_TWI_TAKT,combobox,1478557699
Control9=IDC_BUTTON_DEFAULT,button,1342242944
Control10=IDC_BUTTON_UPDATE,button,1342242944
Control11=IDC_BUTTON_RETRIEVE,button,1342242944
Control12=IDC_STATIC,static,1342177801
Control13=IDC_STATIC_LINE1,static,1342177296
Control14=IDC_STATIC_REFVOL,static,1342308354
Control15=IDC_STATIC_LINE2,static,1342177296
Control16=IDC_STATIC_BAUD,static,1342308354
Control17=IDC_STATIC_PARITY,static,1342308354
Control18=IDC_STATIC_TAKT,static,1342308354
Control19=IDC_STATIC_TABLEOFFSET,static,1342308354
Control20=IDC_EDIT_TABLE_OFFSET,edit,1484849280
Control21=IDC_STATIC_SPI_TAKT,static,1342308354
Control22=IDC_STATIC_TWI_TAKT,static,1342308354
Control23=IDC_STATIC_PROCESSOR,static,1342308354
Control24=IDC_STATIC_MODULE,static,1342308354
Control25=IDC_EDIT_PROCESSOR,edit,1484849280
Control26=IDC_EDIT_MODULE,edit,1484849280
Control27=IDC_STATIC_TAKT_CPU,static,1342308354
Control28=IDC_EDIT_TAKT_CPU,edit,1484849280
Control29=IDC_BUTTON_RESET,button,1342242944
Control30=IDC_EDIT_BAUD,edit,1484849280
Control31=IDC_LIST_EWORD,SysListView32,1350631433
Control32=IDC_LIST_EBYTE,SysListView32,1350631433
Control33=IDC_EDIT_EBYTE,edit,1082196096
Control34=IDC_BUTTON_EBYTE_UPDATE,button,1342242816
Control35=IDC_EDIT_EWORD,edit,1082196096
Control36=IDC_BUTTON_EWORD_UPDATE,button,1342242816
Control37=IDC_BUTTON_EBYTE_READ,button,1342242816
Control38=IDC_BUTTON_EBYTE_READ_BUTCH,button,1342242816
Control39=IDC_BUTTON_EWORD_READ,button,1342242816
Control40=IDC_BUTTON_EWORD_READ_BUTCH,button,1342242816
Control41=IDC_STATIC_LINE3,static,1342177296
Control42=IDC_STATIC,static,1342308352
Control43=IDC_STATIC,static,1342308352
Control44=IDC_BUTTON_HALT,button,1342242944
Control45=IDC_BUTTON_CONTINUE,button,1342242944
Control46=IDC_STATIC,static,1342177801

[DLG:IDD_DIALOG_EMBEDDED_32]
Type=1
Class=CEmbeddedConfigurator_dlg
ControlCount=17
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342177294
Control4=IDC_COMBO_PINS,combobox,1344340227
Control5=IDC_COMBO_MODES,combobox,1344340227
Control6=IDC_RADIO_DIGITAL_IN,button,1476395017
Control7=IDC_RADIO_DIGITAL_OUT,button,1476395017
Control8=IDC_RADIO_ANALOG_IN,button,1476395017
Control9=IDC_RADIO_ANALOG_OUT,button,1476395017
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDIT_REGISTER,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342177287
Control15=IDC_BUTTON_OPEN,button,1342242816
Control16=IDC_BUTTON_SAVE,button,1342242816
Control17=IDC_STATIC,static,1342177287

[CLS:CEmbeddedConfigurator_dlg]
Type=0
HeaderFile=EmbeddedConfigurator_dlg.h
ImplementationFile=EmbeddedConfigurator_dlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CEmbeddedConfigurator_dlg

[CLS:CPageMD100]
Type=0
HeaderFile=PageMD100.h
ImplementationFile=PageMD100.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CPageMD100
VirtualFilter=idWC

[DLG:IDD_DIALOG_LIST_ITEM]
Type=1
Class=CDialogItemValue
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT_ITEM_VALUE_BYTE,edit,1350631552
Control4=IDC_STATIC,static,1342308352

[CLS:CDialogItemValue]
Type=0
HeaderFile=DialogItemValue.h
ImplementationFile=DialogItemValue.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT_ITEM_VALUE_BYTE
VirtualFilter=dWC

[DLG:IDD_DIALOG_MDxx_MONITOR]
Type=1
Class=CMdxxMonitor_dlg
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LIST_RAM_BILD,SysListView32,1350631425
Control4=IDC_EDIT_SYMBOL_FILE,edit,1484849280
Control5=IDC_BUTTON_BROWSE,button,1342242816
Control6=IDC_BUTTON_START,button,1342242816
Control7=IDC_BUTTON_STOP,button,1342242816

[CLS:CMdxxMonitor_dlg]
Type=0
HeaderFile=MdxxMonitor_dlg.h
ImplementationFile=MdxxMonitor_dlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CMdxxMonitor_dlg
VirtualFilter=dWC

[DLG:IDD_DIALOG_ME100_CONFIGURATION]
Type=1
Class=CMd100_dlg
ControlCount=48
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_RADIO_VCC,button,1342177289
Control4=IDC_RADIO_RV256,button,1342177289
Control5=IDC_COMBO_PARITY,combobox,1478557954
Control6=IDC_COMBO_TAKT,combobox,1478557699
Control7=IDC_COMBO_SPI_TAKT,combobox,1478557699
Control8=IDC_COMBO_TWI_TAKT,combobox,1478557699
Control9=IDC_BUTTON_DEFAULT,button,1342242944
Control10=IDC_BUTTON_UPDATE,button,1342242944
Control11=IDC_BUTTON_RETRIEVE,button,1342242944
Control12=IDC_STATIC,static,1342177801
Control13=IDC_STATIC_LINE1,static,1342177296
Control14=IDC_STATIC_REFVOL,static,1342308354
Control15=IDC_STATIC_LINE2,static,1342177296
Control16=IDC_STATIC_BAUD,static,1342308354
Control17=IDC_STATIC_PARITY,static,1342308354
Control18=IDC_STATIC_TAKT,static,1342308354
Control19=IDC_STATIC_TABLEOFFSET,static,1342308354
Control20=IDC_EDIT_TABLE_OFFSET,edit,1484849280
Control21=IDC_STATIC_SPI_TAKT,static,1342308354
Control22=IDC_STATIC_TWI_TAKT,static,1342308354
Control23=IDC_STATIC_PROCESSOR,static,1342308354
Control24=IDC_STATIC_MODULE,static,1342308354
Control25=IDC_EDIT_PROCESSOR,edit,1484849280
Control26=IDC_EDIT_MODULE,edit,1484849280
Control27=IDC_STATIC_TAKT_CPU,static,1342308354
Control28=IDC_EDIT_TAKT_CPU,edit,1484849280
Control29=IDC_BUTTON_RESET,button,1342242944
Control30=IDC_EDIT_BAUD,edit,1484849280
Control31=IDC_LIST_EWORD,SysListView32,1082195977
Control32=IDC_LIST_EBYTE,SysListView32,1350631433
Control33=IDC_BUTTON_EBYTE_UPDATE,button,1342242816
Control34=IDC_BUTTON_EWORD_UPDATE,button,1342242816
Control35=IDC_BUTTON_EBYTE_READ,button,1476460544
Control36=IDC_BUTTON_EBYTE_READ_BUTCH,button,1342242816
Control37=IDC_BUTTON_EWORD_READ,button,1342242816
Control38=IDC_BUTTON_EWORD_READ_BUTCH,button,1342242816
Control39=IDC_STATIC_LINE3,static,1342177296
Control40=IDC_BUTTON_HALT,button,1342242944
Control41=IDC_BUTTON_CONTINUE,button,1342242944
Control42=IDC_STATIC,static,1342177801
Control43=IDC_BUTTON_BRS,button,1342242816
Control44=IDC_EDIT_BRS,edit,1484849280
Control45=IDC_RADIO_WORDS,button,1342177289
Control46=IDC_RADIO_BYTES,button,1342177289
Control47=IDC_BUTTON_BRS_EEPROM_HEX,button,1342242816
Control48=IDC_EDIT_BRS_EEPROM_HEX,edit,1484849280

