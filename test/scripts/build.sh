#!/bin/bash

# Build the test project
cmake -S ".." -B "../build" -DPROJECT_META_CMAKE_INFO=ON
cmake --build "../build"
cmake --build "../build" --target test