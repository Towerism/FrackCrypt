include(gtest)
include(testing)

include_directories(${GTEST_INCLUDE_DIR})

add_subdirectory(unit)

get_test_sources(TEST_SRCS)
add_executable(frackcrypt_test_suite ${TEST_SRCS})

set(TEST_SUITE_LIBS ${GTEST_LIBRARY} ${GTEST_MAIN} pthread)
target_link_libraries(frackcrypt_test_suite ${TEST_SUITE_LIBS})

run_test(frackcrypt_test_suite)
