#!/bin/bash

git clone https://github.com/linux-test-project/lcov.git
cd lcov && make install PREFIX=..
