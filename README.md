# Magnetic-Field library

See [Licence](https://github.com/Alexey-Stupishin/Magnetic-Field_Library/blob/master/LICENCE.md)

[Refer to the latest stable release (v 2.1.20.428): doi:10.5281/zenodo.3896222](https://zenodo.org/record/3896223#.Y13LRHZBxJQ)

The repository contains:
* sources of Magnetic Field Library (C++11)
* Windows .dll and Linux .so libraries
* project for build under Windows and Linux
* wrappers for IDL calls

## Dependencies
IDL wrappers are designed to be used as subpackage of [GX-simulator](https://github.com/Gelu-Nita/GX_SIMULATOR) package, which included in [Solar Soft](http://www.lmsal.com/solarsoft/sswdoc/sswdoc_jtop.html) environment.

To rebild the project it is necessry to clone [common](https://github.com/Alexey-Stupishin/Common) repository and placed it at the same directory tree level as Magnetic Field Library.

## Routines
* _/binaries/WWNLFFFReconstruction.dll_ - Calculation library for Windows
* _/binaries/WWNLFFFReconstruction.so_ - Calculation library for Linux
* _/idl/gx_box_calculate_lines.pro_ - IDL wrapper to calculate megnetic field lines
* _/idl/gx_box_make_nlfff_wwas_field.pro_ - IDL wrapper to reconstruct non-linear force-free magnetic field (NLFFF) by T.Wiegelmann (weighted) method
* _/idl/gx_box_field_library_version.pro_ - IDL wrapper to get
* _/sources_ - source codes (C++11)
* _/Windows_ - MSVC project for Windows
* _/Linux_ - makefile for Linux

For NLFFF Weghted method please refer to:
Wiegelmann, T. Optimization code with weighting function for the reconstruction of coronal magnetic fields. _Solar Phys_., 2004, __219__, 87–108. ([doi:10.1023/B:SOLA.0000021799.39465.36](https://link.springer.com/article/10.1023/B:SOLA.0000021799.39465.36), [ADS:2004SoPh..219...87W](https://ui.adsabs.harvard.edu/abs/2004SoPh..219...87W/abstract), [arXiv:0802.0124](https://arxiv.org/abs/0802.0124))

Some proofs and using of this library can be found in:

Fleishman, G.D., Anfinogentov, S., Loukitcheva, M., Mysh'yakov, I., Stupishin, A. Casting the Coronal Magnetic Field Reconstruction Tools in 3D Using the MHD Bifrost Model. ApJ, 2017, __839__, 30 ([doi:10.3847/1538-4357/aa6840](https://iopscience.iop.org/article/10.3847/1538-4357/aa6840), [ADS:2017ApJ...839...30F](https://ui.adsabs.harvard.edu/abs/2017ApJ...839...30F/abstract), [arXiv:1703.06360](https://ui.adsabs.harvard.edu/link_gateway/2017ApJ...839...30F/arxiv:1703.06360))


## Update History
* 16 June 2020 - 1st release (v 2.1.20.428), [doi:10.5281/zenodo.3896222](https://zenodo.org/record/3896223#.Y13LRHZBxJQ)
* 04 October 2020 (v 2.1.20.1004, rev.363): _weight_bound_size_ key added to _gx_box_make_nlfff_wwas_field.pro_, see comment inside
* 25 January 2021 (v 2.2.21.125, rev.384): bug fixed (_extra parameters could prevent NLFFF in some cases)
* 18 February 2021 (v 2.3.21.217, rev.392):
	* bug fixed (it was crash when calculated with seeds)
	* improvement (all lines calculated, even if seed below chromo_level); but only part above chromo_level is stored
	* comment in _gx_box_calculate_lines.pro_ utility corrected, so that is less confusing
* 16 October 2022 (v 2.4.22.1016, rev.625):
	* Significant code reorganization 
	* Linux version started 
	* small bug for short low loops fixed
	* small lines wrapper correction
* 30 October 2022 (v 3.4.22.1025, rev.626): 
	* Major structure changes 
