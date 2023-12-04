# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("samp-plugin-json")

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

set(LIB "${CMAKE_SOURCE_DIR}/lib")
set(SDK "${CMAKE_SOURCE_DIR}/lib/sdk")
set(SAMPSVR_PLUGIN_DIR "${CMAKE_SOURCE_DIR}/sampsvr/plugins")

add_definitions("-DSUBHOOK_STATIC")
add_subdirectory ("samp-plugin-json")
