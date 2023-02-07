# Microsoft Developer Studio Project File - Name="Lander" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Lander - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Lander.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Lander.mak" CFG="Lander - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Lander - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Lander - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Lander - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0xc0a /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0xc0a /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 opengl32.lib glu32.lib glaux.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Lander - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0xc0a /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0xc0a /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 opengl32.lib glu32.lib glaux.lib glut32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Lander - Win32 Release"
# Name "Lander - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\CoordenadaCartesiana.cpp
# End Source File
# Begin Source File

SOURCE=.\CoordenadaEsferica.cpp
# End Source File
# Begin Source File

SOURCE=.\DatosCiclo.cpp
# End Source File
# Begin Source File

SOURCE=.\DatosIniciales.cpp
# End Source File
# Begin Source File

SOURCE=.\DibAgente.cpp
# End Source File
# Begin Source File

SOURCE=.\DibGL.cpp
# End Source File
# Begin Source File

SOURCE=.\Dlg_BuscarPatron.cpp
# End Source File
# Begin Source File

SOURCE=.\Dlg_Datos.cpp
# End Source File
# Begin Source File

SOURCE=.\Dlg_Estadisticas.cpp
# End Source File
# Begin Source File

SOURCE=.\Dlg_IrA.cpp
# End Source File
# Begin Source File

SOURCE=.\Lander.cpp
# End Source File
# Begin Source File

SOURCE=.\Lander.rc
# End Source File
# Begin Source File

SOURCE=.\LanderDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\LanderView.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\ManejadorBitmap.cpp
# End Source File
# Begin Source File

SOURCE=.\ManejadorFichero.cpp
# End Source File
# Begin Source File

SOURCE=.\Orientacion.cpp
# End Source File
# Begin Source File

SOURCE=.\Punto.cpp
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\CoordenadaCartesiana.h
# End Source File
# Begin Source File

SOURCE=.\CoordenadaEsferica.h
# End Source File
# Begin Source File

SOURCE=.\DatosCiclo.h
# End Source File
# Begin Source File

SOURCE=.\DatosIniciales.h
# End Source File
# Begin Source File

SOURCE=.\DibAgente.h
# End Source File
# Begin Source File

SOURCE=.\DibGL.h
# End Source File
# Begin Source File

SOURCE=.\Dlg_BuscarPatron.h
# End Source File
# Begin Source File

SOURCE=.\Dlg_Datos.h
# End Source File
# Begin Source File

SOURCE=.\Dlg_Estadisticas.h
# End Source File
# Begin Source File

SOURCE=.\Dlg_IrA.h
# End Source File
# Begin Source File

SOURCE=.\header1.h
# End Source File
# Begin Source File

SOURCE=.\Lander.h
# End Source File
# Begin Source File

SOURCE=.\LanderDoc.h
# End Source File
# Begin Source File

SOURCE=.\LanderView.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\ManejadorBitmap.h
# End Source File
# Begin Source File

SOURCE=.\ManejadorFichero.h
# End Source File
# Begin Source File

SOURCE=.\Orientacion.h
# End Source File
# Begin Source File

SOURCE=.\Punto.h
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Land.bmp
# End Source File
# Begin Source File

SOURCE=.\res\lander.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Lander.ico
# End Source File
# Begin Source File

SOURCE=.\res\Lander.rc2
# End Source File
# Begin Source File

SOURCE=.\res\LanderDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
