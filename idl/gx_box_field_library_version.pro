function gx_box_field_library_version, lib_location, returnCode = returnCode 

b = bytarr(512)
b(*) = 32B
version_info = STRING(b)
returnCode = CALL_EXTERNAL(lib_location, 'mfoNLFFFVersion', version_info)

return, version_info

end
