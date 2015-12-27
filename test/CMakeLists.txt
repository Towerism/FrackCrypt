# Download and unpack googletest at configure time
configure_file(${CMAKE_MODULE_PATH}/gtest.cmake
               googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/test/googletest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/test/googletest-download )

# Add googletest directly to our build. This adds
# the following targets: gtest, gtest_main, gmock
# and gmock_main
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL )

# The gtest/gmock targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
include_directories("${gtest_SOURCE_DIR}/include"
                    "${gmock_SOURCE_DIR}/include")

include_directories(${GTEST_INCLUDE_DIR})

set(LIBS_TO_TEST tools)
set(TEST_LIBS gmp pthread ${LIBS_TO_TEST} gtest gtest_main)

if (${FRACKCRYPT_TEST_UNIT})
  add_subdirectory(unit)

  add_executable(frackcrypt_test_unit $<TARGET_OBJECTS:unit>)

  target_link_libraries(frackcrypt_test_unit ${TEST_LIBS})
endif()

if (${FRACKCRYPT_TEST_INTEGRATION})
  add_subdirectory(integration)

  add_executable(frackcrypt_test_integration $<TARGET_OBJECTS:integration>)

  set(TEST_INTEGRATION_LIBS ${TEST_LIBS})
  target_link_libraries(frackcrypt_test_integration ${TEST_INTEGRATION_LIBS})
endif()

if (FRACKCRYPT_COVERAGE AND NOT WIN32 AND NOT APPLE)
  include(code_coverage)
  setup_target_for_coverage(
    coverage
    ctest
    coverage
    "-VV"
  )
endif()
