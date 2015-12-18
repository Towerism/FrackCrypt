add_custom_target(run-tests)
file(WRITE ${CMAKE_BINARY_DIR}/test_sources "")

macro(run_test test_target)
  add_custom_command(
    TARGET run-tests
    POST_BUILD
    COMMAND ${test_target} --gtest_color=yes
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/test")
  add_dependencies(run-tests ${test_target})
endmacro()

macro(add_test_sources)
  foreach(src ${ARGN})
    set(src ${src})
    file(APPEND ${CMAKE_BINARY_DIR}/test_sources ${CMAKE_CURRENT_LIST_DIR}/${src} "\n")
  endforeach()
endmacro()

macro(get_test_sources dest_var)
  file(STRINGS ${CMAKE_BINARY_DIR}/test_sources PATHS)
  foreach(PATH ${PATHS})
    file(RELATIVE_PATH RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${PATH})
    list(APPEND ${dest_var} ${RELATIVE})
  endforeach()
endmacro()
