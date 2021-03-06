;*****************************************************************************
;*
;*                            Open Watcom Project
;*
;*    Portions Copyright (c) 1983-2002 Sybase, Inc. All Rights Reserved.
;*
;*  ========================================================================
;*
;*    This file contains Original Code and/or Modifications of Original
;*    Code as defined in and that are subject to the Sybase Open Watcom
;*    Public License version 1.0 (the 'License'). You may not use this file
;*    except in compliance with the License. BY USING THIS FILE YOU AGREE TO
;*    ALL TERMS AND CONDITIONS OF THE LICENSE. A copy of the License is
;*    provided with the Original Code and Modifications, and is also
;*    available at www.sybase.com/developer/opensource.
;*
;*    The Original Code and all software distributed under the License are
;*    distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
;*    EXPRESS OR IMPLIED, AND SYBASE AND ALL CONTRIBUTORS HEREBY DISCLAIM
;*    ALL SUCH WARRANTIES, INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF
;*    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR
;*    NON-INFRINGEMENT. Please see the License for the specific language
;*    governing rights and limitations under the License.
;*
;*  ========================================================================
;*
;* Description:  WHEN YOU FIGURE OUT WHAT THIS FILE DOES, PLEASE
;*               DESCRIBE IT HERE!
;*
;*****************************************************************************


;========================================================================
;==     Name:           LDIV                                           ==
;==     Operation:      Signed 4 byte divide                           ==
;==     Inputs:         EAX     Dividend                               ==
;==                     EDX     Divisor                                ==
;==                     SS:ESI  pointer to result structure            ==
;==     Volatile:       none                                           ==
;========================================================================
include mdef.inc
include struct.inc

ifdef _PROFILE
include p5prof.inc
endif
        modstart        ldiv386

        defpe   div
        xdefp   "C",div
        defpe   ldiv
        xdefp   "C",ldiv
    ifdef _PROFILE
        P5Prolog
    endif
    ifdef __STACK__
        mov     EDX,8[ESP]      ; get divisor
        mov     EAX,4[ESP]      ; get numerator
    endif
        push    EBX             ; save EBX
        mov     EBX,EDX         ; get divisor
        cdq                     ; sign extend dividend
        idiv    EBX             ; do the divide
        mov     [ESI],EAX       ; store quotient
        mov     4[ESI],EDX      ; store remainder
        pop     EBX             ; restore EBX
    ifdef _PROFILE
        P5Epilog
    endif
        ret                     ; return
        endproc ldiv
        endproc div

        endmod
        end
