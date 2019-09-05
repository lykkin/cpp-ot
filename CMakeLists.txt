cmake_minimum_required(VERSION 3.1.0)
project(open-telemetry)
set(OPEN_TELEMETRY_VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(open-telemetry_build_include_dirs
  "${open-telemetry_SOURCE_DIR}/include"
  "${open-telemetry_SOURCE_DIR}")
include_directories(${open-telemetry_build_include_dirs})

add_library(open-telemetry "${cxx_strict}" src/open-telemetry.cc)

add_subdirectory(vendor/googletest)
add_subdirectory(test)
