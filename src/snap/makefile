############################################################################
#
#  ========================================================================
#
#   Copyright (C) 1991-2004 SciTech Software, Inc. All rights reserved.
#
#   This file may be distributed and/or modified under the terms of the
#   GNU General Public License version 2.0 as published by the Free
#   Software Foundation and appearing in the file LICENSE.GPL included
#   in the packaging of this file.
#
#   Licensees holding a valid Commercial License for this product from
#   SciTech Software, Inc. may use this file in accordance with the
#   Commercial License Agreement provided with the Software.
#
#   This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING
#   THE WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR
#   PURPOSE.
#
#   See http://www.scitechsoft.com/license/ for information about
#   the licensing options available and how to purchase a Commercial
#   License Agreement.
#
#   Contact license@scitechsoft.com if any conditions of this licensing
#   are not clear to you, or you have questions about licensing options.
#
#  ========================================================================
#
# Descripton:   Makefile script to build the SNAP Graphics simple SDK.
#
#############################################################################

#----------------------------------------------------------------------------
# DOS extender dependant flags
#----------------------------------------------------------------------------

CFLAGS      += $(DX_CFLAGS)
ASFLAGS     += $(DX_ASFLAGS)

#----------------------------------------------------------------------------
# Define the lists of object files
#----------------------------------------------------------------------------

GA_OBJS     = gasdk$O vgapal$O

#----------------------------------------------------------------------------
# Find the name of the library file to build
#----------------------------------------------------------------------------

OBJECTS     = $(GA_OBJS)
.IF $(STKCALL)
LIBFILE     = $(LP)sn_ga$L
.ELSE
LIBFILE     = $(LP)n_ga$L
.ENDIF

LIBCLEAN    = *.lib *.a *.dll

#----------------------------------------------------------------------------
# Default target to build the library file
#----------------------------------------------------------------------------

all: $(LIBFILE)

#----------------------------------------------------------------------------
# Define the list of object files to create dependency information for
#----------------------------------------------------------------------------

DEPEND_OBJ      = $(GA_OBJS)
DEPEND_INC      = $(SCITECH)\include\snap

.INCLUDE: "$(SCITECH)/makedefs/common.mk"

