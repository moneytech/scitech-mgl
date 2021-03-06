/****************************************************************************
*
*                            Open Watcom Project
*
*    Portions Copyright (c) 1983-2002 Sybase, Inc. All Rights Reserved.
*
*  ========================================================================
*
*    This file contains Original Code and/or Modifications of Original
*    Code as defined in and that are subject to the Sybase Open Watcom
*    Public License version 1.0 (the 'License'). You may not use this file
*    except in compliance with the License. BY USING THIS FILE YOU AGREE TO
*    ALL TERMS AND CONDITIONS OF THE LICENSE. A copy of the License is
*    provided with the Original Code and Modifications, and is also
*    available at www.sybase.com/developer/opensource.
*
*    The Original Code and all software distributed under the License are
*    distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
*    EXPRESS OR IMPLIED, AND SYBASE AND ALL CONTRIBUTORS HEREBY DISCLAIM
*    ALL SUCH WARRANTIES, INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF
*    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR
*    NON-INFRINGEMENT. Please see the License for the specific language
*    governing rights and limitations under the License.
*
*  ========================================================================
*
* Description:  WHEN YOU FIGURE OUT WHAT THIS FILE DOES, PLEASE
*               DESCRIBE IT HERE!
*
****************************************************************************/


// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// %     Copyright (C) 1992, by WATCOM International Inc.  All rights    %
// %     reserved.  No part of this software may be reproduced or        %
// %     used in any form or by any means - graphic, electronic or       %
// %     mechanical, including photocopying, recording, taping or        %
// %     information storage and retrieval systems - except with the     %
// %     written permission of WATCOM International Inc.                 %
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//
//  Modified    By              Reason
//  ========    ==              ======
//  92/02/10    Steve McDowell  Initial implementation.
//  92/02/28    ...             Modified to delay allocation of buffers
//                              until overflow/underflow called.
//  92/09/08    Greg Bentz      Cleanup.
//  93/10/21    Raymond Tang    Split into separate files.
//  93/11/05    Greg Bentz      seekoff with ios::in|ios::out is allowed
//                              and will return the position of the put ptr
//  93/11/16    Greg Bentz      no longer assumes that get area and put area
//                              do not overlap
//  94/04/06    Greg Bentz      combine header files

#ifdef __SW_FH
#include "iost.h"
#else
#include "variety.h"
#include <strstrea.h>
#endif
#include "ssfhdr.h"

streampos strstreambuf::seekoff( streamoff offset, ios::seekdir direction,
/************************************************************************/
    int mode ) {
// Position either the get and/or put pointer to the specified position.
// Note that seekpos also works because the default virtual function for
// seekpos calls seekoff, which will come here.

    streampos  newpos;
    char      *endget;
    char      *pos;

    mode &= (ios::in | ios::out);
    if( (mode == 0) ||
      ( (direction==ios::cur) && (mode == (ios::in | ios::out)) ) ) {
        return( EOF );
    }

    __lock_it( __b_lock );

    // Move the get pointer:
    if( mode & ios::in ) {
        endget = pptr();
        if( endget == NULL || endget < egptr() ) {
            endget = egptr();
        }
        newpos = __get_position( offset, direction, eback(), gptr(), egptr(), endget );
        if( newpos != EOF ) {

            // If the seek went beyond the end of the get area, extend the
            // get area to include the characters in the put area.
            pos = eback() + newpos;
            if( pos > egptr() ) {
                setg( eback(), pos, epptr() );
            } else {
                setg( eback(), pos, egptr() );
            }
        }
    }

    if( mode & ios::out ) {
        // Move the put pointer:
        newpos = __get_position( offset, direction, pbase(), pptr(), epptr(), epptr() );
        if( newpos != EOF ) {
            setp( pbase(), epptr() );
            pbump( newpos );
            if( newpos > __minbuf_size ) {
                __minbuf_size = (int)newpos;
            }
        }
    }
    return( newpos );
}
