cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

option(FRACKCRYPT_TEST "Enable testing for FrackCrypt" OFF)
option(FRACKCRYPT_TEST_UNIT "Enable unit testing (only if testing is enabled)" ON)
option(FRACKCRYPT_TEST_INTEGRATION "Enable integration testing (only if testing is enabled)" ON)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

set(CMAKE_CXX_FLAGS "-std=c++14 ${CMAKE_CXX_FLAGS}")

if (${FRACKCRYPT_TEST})
  add_subdirectory(test)
endif()
