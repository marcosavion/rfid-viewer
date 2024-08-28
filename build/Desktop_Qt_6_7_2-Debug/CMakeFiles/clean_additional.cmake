# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/rfid-viewer_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/rfid-viewer_autogen.dir/ParseCache.txt"
  "rfid-viewer_autogen"
  )
endif()
