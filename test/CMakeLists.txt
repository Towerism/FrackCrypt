include(gtest)

include_directories(${GTEST_INCLUDE_DIR})

set(LIBS_TO_TEST tools)
set(TEST_LIBS gmp pthread ${LIBS_TO_TEST} ${GTEST_LIBRARY} ${GTEST_MAIN})

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
