#!/bin/bash

if [ "${TEST_SUITE}" == "coverage" ]; then
  coveralls-lcov build/coverage/coverage.info.cleaned
fi
