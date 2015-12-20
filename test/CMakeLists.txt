include(gtest)
include(testing)

include_directories(${GTEST_INCLUDE_DIR})

if (${FRACKCRYPT_TEST_UNIT})
  add_subdirectory(unit)

  get_test_sources(unit UNIT_SRCS)
  add_executable(frackcrypt_test_unit ${UNIT_SRCS})

  set(LIBS_TO_TEST base64)
  set(TEST_UNIT_LIBS ${LIBS_TO_TEST} ${GTEST_LIBRARY} ${GTEST_MAIN} pthread)
  target_link_libraries(frackcrypt_test_unit ${TEST_UNIT_LIBS})
endif()

if (${FRACKCRYPT_TEST_INTEGRATION})
  add_subdirectory(integration)

  get_test_sources(integration INTEGRATION_SRCS)
  add_executable(frackcrypt_test_integration ${INTEGRATION_SRCS})

  set(TEST_INTEGRATION_LIBS ${GTEST_LIBRARY} ${GTEST_MAIN} pthread)
  target_link_libraries(frackcrypt_test_integration ${TEST_INTEGRATION_LIBS})
endif()
