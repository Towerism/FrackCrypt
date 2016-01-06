include(gtest)

set(LIBS_TO_TEST
  tools
  )
set(TEST_LIBS
  ${LIBS_TO_TEST}
  ${GMP_LIBRARIES}
  gtest
  gtest_main
  )

if (${THREADS_FOUND})
  set(TEST_LIBS
    ${TEST_LIBS}
    Threads::Threads
    )
endif()


if (${FRACKCRYPT_TEST_UNIT})
  add_subdirectory(unit)

  add_executable(frackcrypt_test_unit $<TARGET_OBJECTS:unit>)

  target_link_libraries(frackcrypt_test_unit ${TEST_LIBS})
endif()

if (${FRACKCRYPT_TEST_INTEGRATION})
  add_subdirectory(integration)

  add_executable(frackcrypt_test_integration $<TARGET_OBJECTS:integration>)

  target_link_libraries(frackcrypt_test_integration ${TEST_LIBS})
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
