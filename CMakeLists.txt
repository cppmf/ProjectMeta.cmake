# ---------------------------------------------------------------------------- #
#
# Copyright (c) 2020 C++ Modern Framework
#
# ---------------------------------------------------------------------------- #

# ---------------------------------------------------------------------------- #
# CppMF projects are designed to apply modern CMake practice.
# As such, a decent CMake version is used to benefit from all new features.
#
# Check CMake Release Notes:
#   https://cmake.org/cmake/help/latest/release/3.21.html
# ---------------------------------------------------------------------------- #
cmake_minimum_required(VERSION 3.21 FATAL_ERROR)

# ---------------------------------------------------------------------------- #
# Project configuration
# ---------------------------------------------------------------------------- #
project(
  ProjectMeta.cmake
  LANGUAGES C CXX
)

# ---------------------------------------------------------------------------- #
#
# Following variables will be set when calling ProjectMeta
#
#   [C]   META_PROJECT_ID :
#   [*]   META_PROJECT_NAME: project name
#         META_PROJECT_DESCRIPTION: project description
#         META_AUTHOR_ORGANIZATION : project organisation
#         META_AUTHOR_DOMAIN: project domain url
#         META_AUTHOR_MAINTAINER: project maintainer
#   [*]   META_VERSION_MAJOR: version major
#   [*]   META_VERSION_MINOR : version minor
#   [C]   META_VERSION_PATCH : version patch
#   [C]   META_VERSION_REVISION : version revision
#   [C]   META_VERSION : version (optional, will be built from version info if not set)
#   [C]   META_VERSION_NAME : version name (optional, will be built from version info if not set)
#
# [*] Mandatory meta data
# [C] Conditionals meta data which will be setup based on mandatory meta data.
#
# ---------------------------------------------------------------------------- #

# This is the main function to call in project CMakeLists.txt
function(ProjectMeta)

  # Parsing ProjectMeta function arguments
  cmake_parse_arguments(
          META
          ""
          "PROJECT_ID;PROJECT_NAME;PROJECT_DESCRIPTION;AUTHOR_ORGANIZATION;AUTHOR_DOMAIN;AUTHOR_MAINTAINER;VERSION_MAJOR;VERSION_MINOR;VERSION_PATCH;VERSION_REVISION;VERSION;VERSION_NAME"
          ""
          ${ARGN}
  )

  # Helper function to check if mandatory meta data exist
  function(_check_and_set_mandatory_meta_data meta description)
    if(NOT DEFINED ${meta})
      message(FATAL_ERROR  "Mandatory project meta data '${meta}' is not defined")
    else()
      set(${meta} ${${meta}} CACHE INTERNAL "${description}")
    endif()
  endfunction()

  # Helper function to check if optional meta data exist
  function(_check_and_set_optional_meta_data meta)
    if(DEFINED ${meta})
      set(${meta} ${${meta}} CACHE INTERNAL "${description}")
    endif()
  endfunction()

  # Check mandatory meta data
  _check_and_set_mandatory_meta_data(META_PROJECT_NAME "Project name")
  _check_and_set_mandatory_meta_data(META_VERSION_MAJOR "Project major version")
  _check_and_set_mandatory_meta_data(META_VERSION_MINOR "Project minor version")

  # Check optional meta data
  _check_and_set_optional_meta_data(META_VERSION_PATCH "Project patch version")
  _check_and_set_optional_meta_data(META_PROJECT_DESCRIPTION)
  _check_and_set_optional_meta_data(META_AUTHOR_ORGANIZATION)
  _check_and_set_optional_meta_data(META_AUTHOR_DOMAIN)
  _check_and_set_optional_meta_data(META_AUTHOR_MAINTAINER)

  # Project ID
  if(NOT DEFINED META_PROJECT_ID)
    string(MAKE_C_IDENTIFIER ${META_PROJECT_NAME} META_PROJECT_ID)
    string(TOUPPER ${META_PROJECT_ID} META_PROJECT_ID)
  endif()
  _check_and_set_mandatory_meta_data(META_PROJECT_ID "Project ID")

  # Project patch version
  if(NOT DEFINED META_VERSION_PATCH)
    set(META_VERSION_PATCH 0)
  endif()
  _check_and_set_mandatory_meta_data(META_VERSION_PATCH "Project patch version")

  # Project revision
  if(NOT DEFINED META_VERSION_REVISION)
    if(DEFINED GIT_REVISION)
      set(META_VERSION_REVISION "${GIT_REVISION}")
    else()
      set(META_VERSION_REVISION "")
    endif()
  endif()
  _check_and_set_mandatory_meta_data(META_VERSION_REVISION "Project version revision")

  # Project version
  if(NOT DEFINED META_VERSION)
    set(META_VERSION "${META_VERSION_MAJOR}.${META_VERSION_MINOR}.${META_VERSION_PATCH}")
  endif()
  _check_and_set_mandatory_meta_data(META_VERSION "Project version")

  # Project version name
  if(NOT DEFINED META_VERSION_NAME)
    if(META_VERSION_REVISION STREQUAL "")
      set(META_VERSION_NAME "${META_PROJECT_NAME} v${META_VERSION}")
    else()
      set(META_VERSION_NAME "${META_PROJECT_NAME} v${META_VERSION} (${META_VERSION_REVISION})")
    endif()
  endif()
  _check_and_set_mandatory_meta_data(META_VERSION_NAME "Project version name")

  # Remove check functions
  unset(_check_and_set_mandatory_meta_data)
  unset(_check_and_set_optional_meta_data)

endfunction()

function(ProjectMetaInfo)
  message(STATUS "")
  message(STATUS "----------------------------------------------------")
  message(STATUS "                 ProjectMeta.cmake")
  message(STATUS "")
  message(STATUS "META_PROJECT_ID: ${META_PROJECT_ID}")
  message(STATUS "META_PROJECT_NAME: ${META_PROJECT_NAME}")
  message(STATUS "META_PROJECT_DESCRIPTION: ${META_PROJECT_DESCRIPTION}")
  message(STATUS "META_AUTHOR_ORGANIZATION: ${META_AUTHOR_ORGANIZATION}")
  message(STATUS "META_AUTHOR_DOMAIN: ${META_AUTHOR_DOMAIN}")
  message(STATUS "META_AUTHOR_MAINTAINER: ${META_AUTHOR_MAINTAINER}")
  message(STATUS "")
  message(STATUS "META_VERSION_MAJOR: ${META_VERSION_MAJOR}")
  message(STATUS "META_VERSION_MINOR: ${META_VERSION_MINOR}")
  message(STATUS "META_VERSION_PATCH: ${META_VERSION_PATCH}")
  message(STATUS "META_VERSION_REVISION: ${META_VERSION_REVISION}")
  message(STATUS "META_VERSION: ${META_VERSION}")
  message(STATUS "META_VERSION_NAME: ${META_VERSION_NAME}")
  message(STATUS "")
  message(STATUS "----------------------------------------------------")
  message(STATUS "")
endfunction()
