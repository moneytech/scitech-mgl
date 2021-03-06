/****************************************************************************
*
*                         SciTech Display Doctor
*
*  ========================================================================
*
*   Copyright (C) 1991-2004 SciTech Software, Inc. All rights reserved.
*
*   This file may be distributed and/or modified under the terms of the
*   GNU General Public License version 2.0 as published by the Free
*   Software Foundation and appearing in the file LICENSE.GPL included
*   in the packaging of this file.
*
*   Licensees holding a valid Commercial License for this product from
*   SciTech Software, Inc. may use this file in accordance with the
*   Commercial License Agreement provided with the Software.
*
*   This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING
*   THE WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR
*   PURPOSE.
*
*   See http://www.scitechsoft.com/license/ for information about
*   the licensing options available and how to purchase a Commercial
*   License Agreement.
*
*   Contact license@scitechsoft.com if any conditions of this licensing
*   are not clear to you, or you have questions about licensing options.
*
*  ========================================================================
*
* Language:     ANSI C
* Environment:  Any
*
* Description:  Support library for implementing hardware and software
*               stereo support using SNAP Graphics drivers and IHV
*               DirectX 8 drivers under Win32.
*
****************************************************************************/

#ifndef __DDSTEREO_H
#define __DDSTEREO_H

#include "snap/graphics.h"

/*--------------------------- Macros and Typedefs -------------------------*/

/* We use C calling conventions for all our functions */

#define DDSAPI  _ASMAPI

/****************************************************************************
REMARKS:
Error codes returned by DDS_init function to indicate driver load status
if loading the device driver failed. Most of these error codes are just
duplicates of the codes returned by the SNAP Graphics device driver loader
library.

HEADER:
ddstereo.h

MEMBERS:
ddsOK               - No error
ddsNotDetected      - Hardware not detected
ddsNotPOSTed        - Hardware has not been POSTed
ddsDriverNotFound   - Driver file not found
ddsCorruptDriver    - File loaded not a driver file
ddsLoadMem          - Not enough memory to load driver
ddsOldVersion       - Driver file is an older version
ddsIOError          - General I/O error
ddsMemMapError      - Could not map physical memory areas
ddsStereoDisabled   - Stereo support is disabled
ddsStereoStarted    - DDS_start has already been called
ddsUnableToFindCRTC - Unable to compute valid CRTC timings using GTF
ddsLockFailed       - DirectDraw lock of a surface failed
ddsInternalError    - Internal error in the DirectDraw stereo library
ddsUnknownMode      - Unknown stereo mode
ddsVideoMemError    - Not enough video memory to support stereo mode
ddsDDrawCapsError   - DirectDraw capabilities unavailable for stereo mode
ddsNotCertified     - Driver file is not certified for stereo
ddsDDrawVersion     - DirectDraw version is not current
ddsNotConfigured    - Driver file has not yet been configured for stereo
ddsWindowError      - Invalid window handle
ddsMultiMonError    - Multiple display devices not available
ddsDLLError         - External DLL unable to be loaded
ddsCRTOnly          - Requires an external analog CRT display only
****************************************************************************/
typedef enum {
    ddsOK,
    ddsNotDetected,
    ddsNotPOSTed,
    ddsDriverNotFound,
    ddsCorruptDriver,
    ddsLoadMem,
    ddsOldVersion,
    ddsMemMapError,
    ddsIOError,
    ddsStereoDisabled,
    ddsStereoStarted,
    ddsUnableToFindCRTC,
    ddsLockFailed,
    ddsInternalError,
    ddsUnknownMode,
    ddsVideoMemError,
    ddsDDrawCapsError,
    ddsNotCertified,
    ddsDDrawVersion,
    ddsNotConfigured,
    ddsWindowError,
    ddsMultiMonError,
    ddsDLLError,
    ddsCRTOnly,
    } DDS_errorType;

#ifdef  _D3D8_H_
/* {secret} */
typedef LPDIRECT3DDEVICE8       DDS_LPD3D8;
/* {secret} */
typedef LPDIRECT3DSURFACE8      DDS_LPD3DSURF8;
/* {secret} */
typedef HWND                    DDS_HWND;
#else
/* {secret} */
typedef void                    *DDS_LPD3D8;
/* {secret} */
typedef void                    *DDS_LPD3DSURF8;
/* {secret} */
typedef void                    *DDS_HWND;
#endif

/*--------------------------- Function Prototypes -------------------------*/

#ifdef  __cplusplus
extern "C" {            /* Use "C" linkage when in C++ mode */
#endif

int     DDSAPI DDS_init(int deviceIndex);
int     DDSAPI DDS_getError(void);
char*   DDSAPI DDS_getErrorString(int error);
int     DDSAPI DDS_getStereoMode(void);
int     DDSAPI DDS_getWindowedStereoMode(void);
int     DDSAPI DDS_getBlankIntervalLines(void);
int     DDSAPI DDS_isFlipChainNeeded(void);
int     DDSAPI DDS_start8(DDS_HWND hwnd,DDS_LPD3D8 lpD3D,DDS_LPD3DSURF8 lpPrimarySurf);
void    DDSAPI DDS_stereoOn(void);
int     DDSAPI DDS_scheduleFlip8(DDS_HWND hwnd,DDS_LPD3DSURF8 lpLeftSurf,DDS_LPD3DSURF8 lpRightSurf);
int     DDSAPI DDS_getFlipStatus(void);
void    DDSAPI DDS_waitTillFlipped(void);
void    DDSAPI DDS_stereoOff(void);
void    DDSAPI DDS_stop(DDS_HWND hwnd);
void    DDSAPI DDS_restoreDisplayMode(void);
void    DDSAPI DDS_exit(void);

#ifdef  __cplusplus
}                       /* End of "C" linkage for C++   */
#endif

#endif /* __DDSTEREO_H */
