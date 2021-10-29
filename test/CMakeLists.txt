# ---------------------------------------------------------------------------- #
# CppMF projects are designed to apply modern CMake practice.
# As such, a decent CMake version is used to benefit from all new features.
#
# Check CMake Release Notes:
#   https://cmake.org/cmake/help/latest/release/3.22.html
# ---------------------------------------------------------------------------- #
cmake_minimum_required(VERSION 3.21 FATAL_ERROR)


# Add the directory containing the main CMakeLists file
# and declare the output directory
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/.. ${CMAKE_CURRENT_BINARY_DIR}/ProjectMetaCmake)


# ---------------------------------------------------------------------------- #
# Project configuration
# ---------------------------------------------------------------------------- #
ProjectMeta(
  # Name of the project
  PROJECT_NAME "test_app"
  # Major version
  VERSION_MAJOR 1
  # Minor version
  VERSION_MINOR 0
  # Patch version
  # VERSION_PATCH 0
)


# ---------------------------------------------------------------------------- #
# Project
# ---------------------------------------------------------------------------- #
project(
  ${META_PROJECT_NAME}
  VERSION ${META_VERSION}
  LANGUAGES CXX
)


# ---------------------------------------------------------------------------- #
# Display project meta data
# ---------------------------------------------------------------------------- #
if(PROJECT_META_CMAKE_INFO)
  ProjectMetaInfo()
endif()


# ---------------------------------------------------------------------------- #
# Pass definition to compiler
# ---------------------------------------------------------------------------- #
if(META_PROJECT_NAME)
  add_definitions(-DMETA_PROJECT_NAME="${META_PROJECT_NAME}")
endif()
if(META_VERSION)
  add_definitions(-DMETA_VERSION="${META_VERSION}")
endif()


# ---------------------------------------------------------------------------- #
# Add target
# ---------------------------------------------------------------------------- #
add_executable(${META_PROJECT_NAME} main.cpp)


# ---------------------------------------------------------------------------- #
# Add test
# ---------------------------------------------------------------------------- #
enable_testing()
add_test(NAME test COMMAND ${META_PROJECT_NAME})