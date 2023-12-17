# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("samp-plugin-json")

set(CMAKE_CXX_STANDARD 14)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

set(LIB "${CMAKE_SOURCE_DIR}/lib")
set(SDK "${CMAKE_SOURCE_DIR}/lib/sdk")
set(JSON_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(SAMPSVR_PLUGIN_DIR "${CMAKE_SOURCE_DIR}/sampsvr/plugins")
set(SAMPSVR_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/sampsvr/include")

add_definitions("-DSUBHOOK_STATIC")
add_subdirectory ("json")
