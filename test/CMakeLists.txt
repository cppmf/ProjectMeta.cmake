# ---------------------------------------------------------------------------- #
# CppMF projects are designed to apply modern CMake practice.
# As such, a decent CMake version is used to benefit from all new features.
#
# Check CMake Release Notes:
#   https://cmake.org/cmake/help/latest/release/3.21.html
# ---------------------------------------------------------------------------- #
cmake_minimum_required(VERSION 3.21 FATAL_ERROR)

# Make use of GetCPM.cmake
include(${CMAKE_CURRENT_LIST_DIR}/cmake/GetCPM.cmake)

# Add ProjectMeta.cmake package
CPMAddPackage(NAME ProjectMeta.cmake SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/..)


# ---------------------------------------------------------------------------- #
# Project configuration
# ---------------------------------------------------------------------------- #
ProjectMeta(
  PROJECT_NAME "Test-App"
  PROJECT_DESCRIPTION "Test project for ProjectMeta.cmake"
  PROJECT_URL "https://github.com/cppmf/ProjectMeta.cmake"

  VERSION_MAJOR 1
  VERSION_MINOR 0
)


# ---------------------------------------------------------------------------- #
# Project
# ---------------------------------------------------------------------------- #
project(
  ${PROJECT_NAME}
  VERSION ${VERSION}
  DESCRIPTION ${PROJECT_DESCRIPTION}
  LANGUAGES CXX
)


# ---------------------------------------------------------------------------- #
# Display project meta data
# ---------------------------------------------------------------------------- #
if(PROJECT_META_CMAKE_INFO)
  ProjectMetaReport()
endif()


# ---------------------------------------------------------------------------- #
# Pass definition to compiler
# ---------------------------------------------------------------------------- #
if(PROJECT_NAME)
  add_definitions(-DPROJECT_NAME="${PROJECT_NAME}")
endif()
if(VERSION)
  add_definitions(-DVERSION="${VERSION}")
endif()


# ---------------------------------------------------------------------------- #
# Add target
# ---------------------------------------------------------------------------- #
add_executable(${PROJECT_NAME} main.cpp)


# ---------------------------------------------------------------------------- #
# Add test
# ---------------------------------------------------------------------------- #
enable_testing()
add_test(NAME test COMMAND ${PROJECT_NAME})