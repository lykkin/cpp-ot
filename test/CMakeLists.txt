project(open-telemetry-test)
include(CTest)

add_executable(span-context_unittest span-context_unittest.cc)
target_link_libraries(span-context_unittest gtest_main open-telemetry)
add_test(NAME span-context COMMAND span-context_unittest)

add_executable(span_unittest span_unittest.cc)
target_link_libraries(span_unittest gtest_main open-telemetry)
add_test(NAME span COMMAND span_unittest)

add_executable(tracer_unittest tracer_unittest.cc)
target_link_libraries(tracer_unittest gtest_main open-telemetry)
add_test(NAME tracer COMMAND tracer_unittest)
