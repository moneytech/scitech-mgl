;****************************************************************************
;*
;* Language:    NASM
;* Environment: IBM PC 32 bit Protected Mode.
;*
;* Description: Module to implement the export stubs for all the JPEG
;*              image library.
;*
;****************************************************************************

include "scitech.mac"           ; Memory model macros

BEGIN_IMPORTS_DEF   _JPEG_exports
DECLARE_IMP __jpeg_std_error,0    ; Handled in C code!
DECLARE_IMP jpeg_CreateCompress,0
DECLARE_IMP jpeg_CreateDecompress,0
DECLARE_IMP jpeg_destroy_compress,0
DECLARE_IMP jpeg_destroy_decompress,0
DECLARE_IMP jpeg_stdio_dest,0
DECLARE_IMP jpeg_stdio_src,0
DECLARE_IMP jpeg_set_defaults,0
DECLARE_IMP jpeg_set_colorspace,0
DECLARE_IMP jpeg_default_colorspace,0
DECLARE_IMP jpeg_set_quality,0
DECLARE_IMP jpeg_set_linear_quality,0
DECLARE_IMP jpeg_add_quant_table,0
DECLARE_IMP jpeg_quality_scaling,0
DECLARE_IMP jpeg_simple_progression,0
DECLARE_IMP jpeg_suppress_tables,0
DECLARE_IMP jpeg_alloc_quant_table,0
DECLARE_IMP jpeg_alloc_huff_table,0
DECLARE_IMP jpeg_start_compress,0
DECLARE_IMP jpeg_write_scanlines,0
DECLARE_IMP jpeg_finish_compress,0
DECLARE_IMP jpeg_write_raw_data,0
DECLARE_IMP jpeg_write_marker,0
DECLARE_IMP jpeg_write_tables,0
DECLARE_IMP jpeg_read_header,0
DECLARE_IMP jpeg_start_decompress,0
DECLARE_IMP jpeg_read_scanlines,0
DECLARE_IMP jpeg_finish_decompress,0
DECLARE_IMP jpeg_read_raw_data,0
DECLARE_IMP jpeg_has_multiple_scans,0
DECLARE_IMP jpeg_start_output,0
DECLARE_IMP jpeg_finish_output,0
DECLARE_IMP jpeg_input_complete,0
DECLARE_IMP jpeg_new_colormap,0
DECLARE_IMP jpeg_consume_input,0
DECLARE_IMP jpeg_calc_output_dimensions,0
DECLARE_IMP jpeg_set_marker_processor,0
DECLARE_IMP jpeg_read_coefficients,0
DECLARE_IMP jpeg_write_coefficients,0
DECLARE_IMP jpeg_copy_critical_parameters,0
DECLARE_IMP jpeg_abort_compress,0
DECLARE_IMP jpeg_abort_decompress,0
DECLARE_IMP jpeg_abort,0
DECLARE_IMP jpeg_destroy,0
DECLARE_IMP jpeg_resync_to_restart,0
END_IMPORTS_DEF

        END
