;****************************************************************************
;*
;*                High Speed Fixed/Floating Point Library
;*
;*  ========================================================================
;*
;*   Copyright (C) 1991-2004 SciTech Software, Inc. All rights reserved.
;*
;*   This file may be distributed and/or modified under the terms of the
;*   GNU General Public License version 2.0 as published by the Free
;*   Software Foundation and appearing in the file LICENSE.GPL included
;*   in the packaging of this file.
;*
;*   Licensees holding a valid Commercial License for this product from
;*   SciTech Software, Inc. may use this file in accordance with the
;*   Commercial License Agreement provided with the Software.
;*
;*   This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING
;*   THE WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR
;*   PURPOSE.
;*
;*   See http://www.scitechsoft.com/license/ for information about
;*   the licensing options available and how to purchase a Commercial
;*   License Agreement.
;*
;*   Contact license@scitechsoft.com if any conditions of this licensing
;*   are not clear to you, or you have questions about licensing options.
;*
;*  ========================================================================
;*
;* Language:    NASM
;* Environment: IBM PC (MS DOS)
;*
;* Description: This module contains routines for high performance 16.16
;*              fixed point inverse trig operations using table lookup and
;*              linear interpolation:
;*
;*                  F386_asin   - 16.16 arc sine
;*                  F386_acos   - 16.16 arc cosine
;*                  F386_atan   - 16.16 arc tangent
;*                  F386_atan2  - 16.16 arc tangent given rise and run
;*
;****************************************************************************

include "scitech.mac"           ; Memory model macros

header  fxatrig                 ; Set up memory model

begdataseg  fxatrig

        cextern FXsin_table,ULONG
        cextern FXatan_table,ULONG

enddataseg  fxatrig

begcodeseg  fxatrig

endcodeseg  fxatrig

        END                     ; End of module
