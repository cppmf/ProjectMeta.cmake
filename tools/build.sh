#!/bin/bash

# go to the root directory
cd ..

# Build the test project
cmake -S "test" -B "build/test" -DPROJECT_META_CMAKE_INFO=ON
cmake --build "build/test"
cmake --build "build/test" --target test
