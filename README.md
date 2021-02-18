# Magnetic-Field library

The repository contains Magnetic Field Library (Windows DLL written on c++) and wrappers for IDL calls.

## Dependencies
All routines are designed to be used in _gxbox_ subpackage of _GX-simulator_ package, which includes in [Solar Soft](http://www.lmsal.com/solarsoft/sswdoc/sswdoc_jtop.html) environment.

## Routines
* _WWNLFFFReconstruction.dll_ - mail calculation library
* _gx_box_calculate_lines.pro_ - IDL wrapper to calculate megnetic field lines
* _gx_box_make_nlfff_wwas_field.pro_ - IDL wrapper to reconstruct non-linear force-free magnetic field (NLFFF) by Wiegelmann (weighted) method

## Update History
* 04 October 2020 (v 2.1.20.1004, rev.363): _weight_bound_size_ key added to _gx_box_make_nlfff_wwas_field.pro_, see comment inside
* 25 January 2021 (v 2.2.21.125, rev.384): bug fixed (_extra parameters could prevent NLFFF in some cases)
* 18 February 2021 (v 2.3.21.217, rev.392):
	* bug fixed (it was crash when calculated with seeds)
	* improvement (all lines calculated, even if seed below chromo_level); but only part above chromo_level is stored
	* comment in _gx_box_calculate_lines.pro_ utility corrected, so that is less confusing
