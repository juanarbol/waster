#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "libuv::uv_a" for configuration "Debug"
set_property(TARGET libuv::uv_a APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(libuv::uv_a PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "C"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libuv.a"
  )

list(APPEND _cmake_import_check_targets libuv::uv_a )
list(APPEND _cmake_import_check_files_for_libuv::uv_a "${_IMPORT_PREFIX}/lib/libuv.a" )

# Import target "libuv::uv" for configuration "Debug"
set_property(TARGET libuv::uv APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(libuv::uv PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libuv.1.0.0.dylib"
  IMPORTED_SONAME_DEBUG "@rpath/libuv.1.dylib"
  )

list(APPEND _cmake_import_check_targets libuv::uv )
list(APPEND _cmake_import_check_files_for_libuv::uv "${_IMPORT_PREFIX}/lib/libuv.1.0.0.dylib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
