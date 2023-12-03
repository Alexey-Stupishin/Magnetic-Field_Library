;
; IDL Wrapper to external call to get version of
;   Weighted Wiegelmann NLFF Field Reconstruction library
;   
; v 3.4.23.1202 (rev.796)
; min WWWNLFFFReconstruction version: v 3.4.22.1025 (rev.626)
; 
; Call (see parameters and comments below):
; version_info = gx_box_field_library_version(lib_location, version_num = version_num, info_length = info_length)
; 
; Parameters required:
;   (in)      lib_location   (string)       full path to calling library
;   
; Parameters optional (out):
;   (out)     version_num    (string)       version number itself (e.g. '3.4.22.1025')
;   (out)     info_length    (integer)      length of version_info string
;   
; Return value:
;   string containing version information. Sample:
;   "Weighted Wiegelmann NLFFF Reconstruction Library v.3.4.22.1025 (rev.626). Copyright (C) Alexey G. Stupishin (agstup@yandex.ru), 2017-2022, St. Petersburg State University, Russia"
;    
;   Note, that wrapping library also provides interfaces for C/C++, Python, and MATLAB
;   
; (c) Alexey G. Stupishin, Saint Petersburg State University, Saint Petersburg, Russia, 2017-2023
;     mailto:agstup@yandex.ru
;
;--------------------------------------------------------------------------;
;     \|/     Set the Controls for the Heart of the Sun           \|/      ;
;    --O--        Pink Floyd, "A Saucerful Of Secrets", 1968     --O--     ;
;     /|\                                                         /|\      ;  
;--------------------------------------------------------------------------;
;                                                              
function gx_box_field_library_version, lib_location, version_num = version_num, info_length = info_length

b = bytarr(512)
b(*) = 32B
version_info = STRING(b)
info_length = CALL_EXTERNAL(lib_location, 'mfoNLFFFVersion', version_info)

pos = strpos(version_info, 'v.')
rest = strmid(version_info, pos+2)
pos = strpos(rest, ' ')

version_num = strmid(rest, 0, pos)

return, version_info

end
