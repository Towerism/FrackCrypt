cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

option(FRACKCRYPT_TEST "Enable testing for FrackCrypt" OFF)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

set(CMAKE_CXX_FLAGS "-std=c++14 ${CMAKE_CXX_FLAGS}")

if (${FRACKCRYPT_TEST})
  add_subdirectory(test)
endif()
