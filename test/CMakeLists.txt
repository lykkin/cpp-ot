project(open-telemetry-test)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${open-telemetry_SOURCE_DIR}/out)

enable_testing()
include_directories(${open-telemetry_SOURCE_DIR}/include)

add_executable(span-context_unittest span-context_unittest.cc)
target_link_libraries(span-context_unittest gtest_main open-telemetry)
add_executable(span_unittest span_unittest.cc)
target_link_libraries(span_unittest gtest_main open-telemetry)
add_executable(tracer_unittest tracer_unittest.cc)
target_link_libraries(tracer_unittest gtest_main open-telemetry)
