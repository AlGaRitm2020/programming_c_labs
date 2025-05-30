# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/graph_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/graph_autogen.dir/ParseCache.txt"
  "graph_autogen"
  )
endif()
