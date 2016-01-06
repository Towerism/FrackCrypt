cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)

project(frackcrypt)

option(FRACKCRYPT_TEST "Enable testing for FrackCrypt" OFF)
option(FRACKCRYPT_TEST_UNIT "Enable unit testing (only if testing is enabled)" ON)
option(FRACKCRYPT_TEST_INTEGRATION "Enable integration testing (only if testing is enabled)" ON)
option(FRACKCRYPT_COVERAGE "Enable test coverage analysis (debug, linux builds only)" OFF)

if (FRACKCRYPT_COVERAGE AND NOT WIN32 AND NOT APPLE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage -lgcov")
endif()

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

set(CMAKE_CXX_FLAGS "-std=c++14 ${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

find_package(GMP REQUIRED)
include_directories(${GMP_INCLUDE_DIR})

include_directories(.)

add_subdirectory(frackcrypt)

if (${FRACKCRYPT_TEST})
  enable_testing()
  add_subdirectory(test)

  if (${FRACKCRYPT_TEST_UNIT})
    add_test(NAME unit COMMAND $<TARGET_FILE:frackcrypt_test_unit>)
  endif()

  if (${FRACKCRYPT_TEST_INTEGRATION})
    add_test(NAME integration COMMAND $<TARGET_FILE:frackcrypt_test_integration>)
  endif()
endif()
