; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDlg_Estadisticas
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Lander.h"
LastPage=0

ClassCount=9
Class1=CLanderApp
Class2=CLanderDoc
Class3=CLanderView
Class4=CMainFrame

ResourceCount=7
Resource1=IDD_ABOUTBOX (Spanish (Modern))
Class5=CAboutDlg
Resource2=IDD_IR_A
Resource3=IDR_MAINFRAME
Class6=CDlg_IrA
Resource4=IDD_BUSCAR_PATRON
Class7=CDlg_BuscarPatron
Resource5=IDD_DATOS
Class8=CDlg_Datos
Resource6=IDD_ABOUTBOX
Class9=CDlg_Estadisticas
Resource7=IDD_RESULTADOS

[CLS:CLanderApp]
Type=0
HeaderFile=Lander.h
ImplementationFile=Lander.cpp
Filter=W
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CLanderDoc]
Type=0
HeaderFile=LanderDoc.h
ImplementationFile=LanderDoc.cpp
Filter=T
BaseClass=CDocument
VirtualFilter=DC
LastObject=CLanderDoc

[CLS:CLanderView]
Type=0
HeaderFile=LanderView.h
ImplementationFile=LanderView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CLanderView

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame



[CLS:CAboutDlg]
Type=0
HeaderFile=Lander.cpp
ImplementationFile=Lander.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=6
Control1=IDC_STATIC,static,1342308480
Control2=IDC_STATIC,static,1342308352
Control3=IDOK,button,1342373889
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDR_MAINFRAME,static,1342177283

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_VIEW_TOOLBAR
Command2=ID_VIEW_STATUS_BAR
Command3=ID_APP_ABOUT
CommandCount=3

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_OPEN
Command2=ID_BUTINTEN_ATRAS
Command3=ID_BUTCICLO_ATRAS
Command4=ID_BUTCICLO_ADEL
Command5=ID_BUTINTEN_ADEL
CommandCount=5

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_OPEN
Command2=ID_BUTCICLO_ADEL
Command3=ID_BUTCICLO_ATRAS
Command4=ID_BUTINTEN_ADEL
Command5=ID_BUTINTEN_ATRAS
Command6=ID_BUT_BUSCAR
Command7=ID_BUT_PATRON_ADEL
Command8=ID_BUT_PATRON_ATRAS
Command9=ID_BUT_IR_A
Command10=ID_BUT_DATOS
Command11=ID_BUT_GRAFICAS
Command12=ID_BUT_GRAFICAS2
Command13=ID_BUTTON_ESTADISTICAS
CommandCount=13

[DLG:IDD_ABOUTBOX (Spanish (Modern))]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg

[DLG:IDD_IR_A]
Type=1
Class=CDlg_IrA
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT1,edit,1350631552
Control6=IDC_EDIT2,edit,1350631552

[CLS:CDlg_IrA]
Type=0
HeaderFile=Dlg_IrA.h
ImplementationFile=Dlg_IrA.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT1

[DLG:IDD_BUSCAR_PATRON]
Type=1
Class=CDlg_BuscarPatron
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_CHECK1,button,1342242819

[CLS:CDlg_BuscarPatron]
Type=0
HeaderFile=Dlg_BuscarPatron.h
ImplementationFile=Dlg_BuscarPatron.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlg_BuscarPatron
VirtualFilter=dWC

[DLG:IDD_DATOS]
Type=1
Class=CDlg_Datos
ControlCount=48
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC_PATRON,static,1342312448
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC_VAL_PROP,static,1342312448
Control9=IDC_STATIC_VAL_PATR,static,1342312448
Control10=IDC_STATIC_VAL_P,static,1342312448
Control11=IDC_STATIC_VAL_N,static,1342312448
Control12=IDC_STATIC,button,1342177287
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC_S1,static,1342312448
Control20=IDC_STATIC_S2,static,1342312448
Control21=IDC_STATIC_S3,static,1342312448
Control22=IDC_STATIC_S4,static,1342312448
Control23=IDC_STATIC_S5,static,1342312448
Control24=IDC_STATIC_S6,static,1342312448
Control25=IDC_STATIC_G1,static,1342312448
Control26=IDC_STATIC_G2,static,1342312448
Control27=IDC_STATIC_G3,static,1342312448
Control28=IDC_STATIC_G4,static,1342312448
Control29=IDC_STATIC_G5,static,1342312448
Control30=IDC_STATIC_G6,static,1342312448
Control31=IDC_STATIC_B1,static,1073741838
Control32=IDC_STATIC_B2,static,1073741838
Control33=IDC_STATIC_B3,static,1073741838
Control34=IDC_STATIC_B4,static,1073741838
Control35=IDC_STATIC_B5,static,1073741838
Control36=IDC_STATIC_B6,static,1073741838
Control37=IDC_STATIC,button,1342177287
Control38=IDC_STATIC,static,1342308352
Control39=IDC_STATIC,static,1342308352
Control40=IDC_STATIC_ZONAXY,static,1342312448
Control41=IDC_STATIC_ZONAYZ,static,1342312448
Control42=IDC_STATIC,button,1342177287
Control43=IDC_STATIC,static,1342308352
Control44=IDC_STATIC,static,1342308352
Control45=IDC_STATIC,static,1342308352
Control46=IDC_STATIC_ZONAXY2,static,1342312448
Control47=IDC_STATIC_ZONAXY3,static,1342312448
Control48=IDC_STATIC_ZONAXY4,static,1342312448

[CLS:CDlg_Datos]
Type=0
HeaderFile=Dlg_Datos.h
ImplementationFile=Dlg_Datos.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlg_Datos
VirtualFilter=dWC

[DLG:IDD_RESULTADOS]
Type=1
Class=CDlg_Estadisticas
ControlCount=35
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC_MEDIA,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC_DESVTIP,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC_PORCENTAGE,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC_PATRONES,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC_HORAS,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC_MINUTOS,static,1342308352
Control17=IDC_STATIC_SEGUNDOS,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC_PORCENTAGE2,static,1342308352
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC_INT1,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_STATIC,static,1342308352
Control24=IDC_STATIC,static,1342308352
Control25=IDC_STATIC_INT2,static,1342308352
Control26=IDC_STATIC_INT3,static,1342308352
Control27=IDC_STATIC,static,1342308352
Control28=IDC_STATIC,static,1342308352
Control29=IDC_STATIC_INT4,static,1342308352
Control30=IDC_STATIC_INT5,static,1342308352
Control31=IDC_STATIC,static,1342308352
Control32=IDC_STATIC,static,1342308352
Control33=IDC_STATIC,static,1342308352
Control34=IDC_STATIC,static,1342308352
Control35=IDC_STATIC,static,1342308352

[CLS:CDlg_Estadisticas]
Type=0
HeaderFile=Dlg_Estadisticas.h
ImplementationFile=Dlg_Estadisticas.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDlg_Estadisticas

