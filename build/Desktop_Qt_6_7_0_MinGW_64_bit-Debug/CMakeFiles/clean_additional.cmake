# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\firstGUI_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\firstGUI_autogen.dir\\ParseCache.txt"
  "firstGUI_autogen"
  )
endif()
