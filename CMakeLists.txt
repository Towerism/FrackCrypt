cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

option(FRACKCRYPT_TEST "Enable testing for FrackCrypt" OFF)
option(FRACKCRYPT_TEST_UNIT "Enable unit testing (only if testing is enabled)" ON)
option(FRACKCRYPT_TEST_INTEGRATION "Enable integration testing (only if testing is enabled)" ON)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

set(CMAKE_CXX_FLAGS "-std=c++14 ${CMAKE_CXX_FLAGS}")

if (${FRACKCRYPT_TEST})
  enable_testing()
  add_subdirectory(test)

  if (${FRACKCRYPT_TEST_UNIT})
    add_test(NAME unit COMMAND $<TARGET_FILE:frackcrypt_test_unit> --gtest_color=yes)
  endif()

  if (${FRACKCRYPT_TEST_INTEGRATION})
    add_test(NAME integration COMMAND $<TARGET_FILE:frackcrypt_test_integration> --gtest_color=yes)
  endif()
endif()
