#!/bin/sh
set -ev
TEST_CONFIG=

if [ "${TEST_SUITE}" == "unit"]; then
  TEST_CONFIG=-DFRACKCRYPT_TEST_INTEGRATION=OFF
elif [ "${TEST_SUITE}" == "integration" ]; then
  TEST_CONFIG=-DFRACKCRYPT_TEST_UNIT=OFF
fi

export CXX=g++-5
cmake -DFRACKCRYPT_TEST=ON ${TEST_CONFIG} . && ctest -VV
