#!/bin/bash

set -ev

coveralls -E "(/usr/.*)|(.*build/.*)|(.*test/.*)(\.cpp)|(\.cc)" -t "$REPO_TOKEN"
