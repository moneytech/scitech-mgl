@echo off
REM Setup environment variables for Visual C++ 5.0 32 bit edition

if .%CHECKED%==.1 goto checked_build
set LIB=%SCITECH_LIB%\LIB\RELEASE\DOS32\VC5;%VC5_PATH%\VC\LIB;%TNT_PATH%\COFFLIB;.
echo Release build enabled.
goto setvars

:checked_build
set LIB=%SCITECH_LIB%\LIB\RELEASE\DOS32\VC5;%VC5_PATH%\VC\LIB;%TNT_PATH%\COFFLIB;.
echo Checked debug build enabled.
goto setvars

:setvars
set TOOLROOTDIR=%VC5_PATH%\VC
set INCLUDE=.;INCLUDE;%SCITECH%\INCLUDE;%PRIVATE%\INCLUDE;%VC5_PATH%\VC\INCLUDE;%TNT_PATH%\INCLUDE;
set INIT=%VC5_PATH%\VC
SET MAKESTARTUP=%SCITECH%\MAKEDEFS\VC32.MK
call clrvars.bat
SET VC_LIBBASE=vc5
PATH %SCITECH_BIN%;%VC5_PATH%\VC\BIN;%VC5_PATH%\SHAREDIDE\BIN;%TNT_PATH%\BIN;%DEFPATH%%VC32_CD_PATH%

REM If you set the following to a 1, a TNT DosStyle app will be created.
REM Otherwise a TNT NtStyle app will be created. NtStyle apps will *only*
REM run under real DOS when using our libraries, since we require access
REM to functions that the Win32 API does not support (such as direct access
REM to video memory, calling Int 10h BIOS functions etc). DosStyle apps
REM will however run fine in both DOS and a Win95 DOS box (NT DOS boxes don't
REM work too well).
REM
REM If you are using the RealTime DOS extender, your apps *must* be NtStyle,
REM and hence will never be able to run under Win95 or WinNT, only DOS.

SET DOSSTYLE=

echo Visual C++ 5.0 32-bit compilation environment set up (with TNT).
