#!/bin/bash
set -ev

TEST_CONFIG=
TEST_COMMAND="make test ARGS=-VV"

if [ "${TEST_SUITE}" == "unit" ]; then
  TEST_CONFIG=-DFRACKCRYPT_TEST_INTEGRATION=OFF
elif [ "${TEST_SUITE}" == "integration" ]; then
  TEST_CONFIG=-DFRACKCRYPT_TEST_UNIT=OFF
elif [ "${TEST_SUITE}" == "coverage" ]; then
  TEST_CONFIG=-DFRACKCRYPT_COVERAGE=ON
  TEST_COMMAND="make coverage"
fi

export CXX=g++-5
mkdir -p build && cd build
cmake -DFRACKCRYPT_TEST=ON ${TEST_CONFIG} ..
make build-tests
${TEST_COMMAND}
