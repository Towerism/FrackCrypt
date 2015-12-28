#!/bin/bash
set -ev

TEST_CONFIG=
TEST_FLAG="-DFRACKCRYPT_TEST=ON"
CONFIGURE_COMMAND=
TEST_COMMAND="make all test ARGS=-VV"

if [ "${TEST_SUITE}" == "unit" ]; then
  TEST_CONFIG=-DFRACKCRYPT_TEST_INTEGRATION=OFF
  CONFIGURE_COMMAND="cmake ${TEST_FLAG} ${TEST_CONFIG} .."
elif [ "${TEST_SUITE}" == "integration" ]; then
  TEST_CONFIG=-DFRACKCRYPT_TEST_UNIT=OFF
  CONFIGURE_COMMAND="cmake ${TEST_FLAG} ${TEST_CONFIG} .."
elif [ "${TEST_SUITE}" == "coverage" ]; then
  TEST_CONFIG=-DFRACKCRYPT_COVERAGE=ON
  TEST_COMMAND="ctest -S CTestScript.cmake -V"
fi


export CXX=g++-5
if [ "${TEST_SUITE}" != "coverage" ]; then
  mkdir -p build && cd build
fi
${CONFIGURE_COMMAND}
${TEST_COMMAND}
