# Microsoft Developer Studio Project File - Name="RCards" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=RCards - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "RCards.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "RCards.mak" CFG="RCards - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "RCards - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "RCards - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/RCards", DHAAAAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "RCards - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "RCARDS_EXPORTS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O1 /D "NDEBUG" /D "RCARDS_EXPORTS" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_RCARDSDLL" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x415 /d "NDEBUG"
# ADD RSC /l 0x415 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib /nologo /dll /machine:I386

!ELSEIF  "$(CFG)" == "RCards - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "RCARDS_EXPORTS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "_RCARDSDLL" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x415 /d "_DEBUG"
# ADD RSC /l 0x415 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib /nologo /dll /debug /machine:I386 /out:"Debug/RCardsd.dll" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "RCards - Win32 Release"
# Name "RCards - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\RCards.c
# End Source File
# Begin Source File

SOURCE=.\RCards.rc
# End Source File
# Begin Source File

SOURCE=.\StdAfx.c
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\RCards.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\Res\bmp1.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp10.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp11.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp12.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp13.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp14.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp15.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp16.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp17.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp18.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp19.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp2.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp20.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp21.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp22.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp23.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp24.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp25.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp26.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp27.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp28.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp29.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp3.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp30.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp31.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp32.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp33.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp34.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp35.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp36.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp37.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp38.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp39.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp4.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp40.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp41.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp42.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp43.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp44.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp45.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp46.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp47.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp48.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp49.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp5.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp50.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp51.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp52.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp53.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp54.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp55.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp56.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp57.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp58.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp59.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp6.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp60.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp61.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp62.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp63.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp64.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp65.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp67.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp678.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp679.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp68.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp680.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp681.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp682.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp683.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp684.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp7.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp8.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\bmp9.bmp
# End Source File
# Begin Source File

SOURCE=.\Res\mask.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
