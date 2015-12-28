FIND_PROGRAM( GCOV_PATH gcov )
FIND_PROGRAM( LCOV_PATH lcov )
FIND_PROGRAM( GENHTML_PATH genhtml )

IF(NOT GCOV_PATH)
  MESSAGE(FATAL_ERROR "gcov not found! Aborting...")
ENDIF() # NOT GCOV_PATH

IF(NOT CMAKE_COMPILER_IS_GNUCXX)

  IF(NOT "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    MESSAGE(FATAL_ERROR "Compiler is not GNU gcc! Aborting...")
  ENDIF()
ENDIF()

FUNCTION(SETUP_TARGET_FOR_COVERAGE _targetname _testrunner _outputname)
  IF(NOT LCOV_PATH)
    MESSAGE(FATAL_ERROR "lcov not found! Aborting...")
  ENDIF()

  IF(NOT GENHTML_PATH)
    MESSAGE(FATAL_ERROR "genhtml not found! Aborting...")
  ENDIF()

  ADD_CUSTOM_TARGET(${_targetname}
    ${LCOV_PATH} --directory . --zerocounters
    COMMAND ${_testrunner} ${ARGV3}
    COMMAND ${LCOV_PATH} --directory . --capture --output-file ${_outputname}.info
    COMMAND ${LCOV_PATH} --remove ${_outputname}.info 'test/*' '/usr/*' 'lib/*' --output-file ${_outputname}.info.cleaned
    COMMAND ${GENHTML_PATH} -o ${_outputname} ${_outputname}.info.cleaned
    COMMAND mv ${_outputname}.info.cleaned ${CMAKE_BINARY_DIR}/${_outputname}/
    COMMAND ${CMAKE_COMMAND} -E remove ${_outputname}.info
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
ENDFUNCTION()
