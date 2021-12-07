# ---------------------------------------------------------------------------- #
#
# Copyright (c) 2020 C++ Modern Framework
#
# ---------------------------------------------------------------------------- #

# ---------------------------------------------------------------------------- #
#
# Following variables will be set when calling ProjectMeta
#
#   [C]   PROJECT_ID :
#   [*]   PROJECT_NAME: project name
#         PROJECT_DESCRIPTION: project description
#         AUTHOR_ORGANIZATION : project organisation
#         AUTHOR_DOMAIN: project domain url
#         AUTHOR_MAINTAINER: project maintainer
#   [*]   VERSION_MAJOR: version major
#   [*]   VERSION_MINOR : version minor
#   [C]   VERSION_PATCH : version patch
#   [C]   VERSION_REVISION : version revision
#   [C]   VERSION : version (optional, will be built from version info if not set)
#   [C]   VERSION_NAME : version name (optional, will be built from version info if not set)
#
# [*] Mandatory meta data
# [C] Conditionals meta data which will be setup based on mandatory meta data.
#
# ---------------------------------------------------------------------------- #

# This is the main function to call in project CMakeLists.txt
function(ProjectMeta)

  # Option overrides
  set(options)
  set(oneValueArgs
        PROJECT_ID PROJECT_NAME PROJECT_DESCRIPTION
        AUTHOR_ORGANIZATION AUTHOR_DOMAIN AUTHOR_MAINTAINER
        VERSION_MAJOR VERSION_MINOR VERSION_PATCH VERSION_REVISION VERSION VERSION_NAME)
  set(multiValueArgs)

  # Parsing ProjectMeta function arguments
  cmake_parse_arguments(META "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

  # Check for unparsed arguments
  if(META_UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "Unknown keywords given to ProjectMeta(): \"${META_UNPARSED_ARGUMENTS}\"")
  endif()

  # Check if PROJECT_NAME is define
  if(NOT DEFINED META_PROJECT_NAME)
    message(FATAL_ERROR  "Mandatory project meta data 'PROJECT_NAME' is not defined")
  endif()

  # Helper function to check if mandatory meta data exist
  function(_check_and_set_mandatory_meta_data meta name description)
    if(NOT DEFINED ${meta})
      message(FATAL_ERROR  "Mandatory project meta data '${name}' is not defined")
    else()
      set(${name} ${${meta}} CACHE INTERNAL "${description}")
    endif()
  endfunction()

  # Helper function to check if optional meta data exist
  function(_check_and_set_optional_meta_data meta name description)
    if(DEFINED ${meta})
      set(${name} ${${meta}} CACHE INTERNAL "${description}")
    endif()
  endfunction()

  # Project ID
  if(NOT DEFINED META_PROJECT_ID)
    string(MAKE_C_IDENTIFIER ${META_PROJECT_NAME} META_PROJECT_ID)
    string(TOUPPER ${META_PROJECT_ID} META_PROJECT_ID)
  endif()
  _check_and_set_mandatory_meta_data(META_PROJECT_ID PROJECT_ID "Project ID")

  # Project ID (lower)
  string(TOLOWER ${PROJECT_ID} PROJECT_ID_LOWER)
  _check_and_set_mandatory_meta_data(PROJECT_ID_LOWER PROJECT_ID_LOWER "Project ID lower case")

  # Project NAME
  _check_and_set_mandatory_meta_data(META_PROJECT_NAME PROJECT_NAME "Project name")
  _check_and_set_mandatory_meta_data(META_PROJECT_NAME ${PROJECT_ID}_PROJECT_NAME "Project name")

  # Project NAME (lower)
  string(TOLOWER ${PROJECT_NAME} PROJECT_NAME_LOWER)
  _check_and_set_mandatory_meta_data(PROJECT_NAME_LOWER PROJECT_NAME_LOWER "Project name lower case")
  _check_and_set_mandatory_meta_data(PROJECT_NAME_LOWER ${PROJECT_ID_LOWER}_PROJECT_NAME_LOWER "Project name lower case")

  # Project description
  _check_and_set_optional_meta_data(META_PROJECT_DESCRIPTION PROJECT_DESCRIPTION "")
  _check_and_set_optional_meta_data(META_PROJECT_DESCRIPTION ${PROJECT_ID}_PROJECT_DESCRIPTION "")

  # Version major
  _check_and_set_mandatory_meta_data(META_VERSION_MAJOR VERSION_MAJOR "Project major version")
  _check_and_set_mandatory_meta_data(META_VERSION_MAJOR ${PROJECT_ID}_VERSION_MAJOR "Project major version")

  # Version minor
  _check_and_set_mandatory_meta_data(META_VERSION_MINOR VERSION_MINOR "Project minor version")
  _check_and_set_mandatory_meta_data(META_VERSION_MINOR ${PROJECT_ID}_VERSION_MINOR "Project minor version")

  # Version patch
  if(NOT DEFINED META_VERSION_PATCH)
    set(META_VERSION_PATCH 0)
  endif()
  _check_and_set_mandatory_meta_data(META_VERSION_PATCH VERSION_PATCH "Project patch version")
  _check_and_set_mandatory_meta_data(META_VERSION_PATCH ${PROJECT_ID}_VERSION_PATCH "Project patch version")

  # Project revision
  if(NOT DEFINED META_VERSION_REVISION)
    if(DEFINED GIT_REVISION)
      set(META_VERSION_REVISION "${GIT_REVISION}")
    else()
      set(META_VERSION_REVISION "")
    endif()
  endif()
  _check_and_set_mandatory_meta_data(META_VERSION_REVISION VERSION_REVISION "Project version revision")
  _check_and_set_mandatory_meta_data(META_VERSION_REVISION ${PROJECT_ID}_VERSION_REVISION "Project version revision")

  # Project version
  if(NOT DEFINED META_VERSION)
    set(META_VERSION "${META_VERSION_MAJOR}.${META_VERSION_MINOR}.${META_VERSION_PATCH}")
  endif()
  _check_and_set_mandatory_meta_data(META_VERSION VERSION "Project version")
  _check_and_set_mandatory_meta_data(META_VERSION ${PROJECT_ID}_VERSION "Project version")

  # Project version name
  if(NOT DEFINED META_VERSION_NAME)
    if(META_VERSION_REVISION STREQUAL "")
      set(META_VERSION_NAME "${META_PROJECT_NAME} v${META_VERSION}")
    else()
      set(META_VERSION_NAME "${META_PROJECT_NAME} v${META_VERSION} (${META_VERSION_REVISION})")
    endif()
  endif()
  _check_and_set_mandatory_meta_data(META_VERSION_NAME VERSION_NAME "Project version name")
  _check_and_set_mandatory_meta_data(META_VERSION_NAME ${PROJECT_ID}_VERSION_NAME "Project version name")

  # Author organisation
  _check_and_set_optional_meta_data(META_AUTHOR_ORGANIZATION AUTHOR_ORGANIZATION "")
  _check_and_set_optional_meta_data(META_AUTHOR_ORGANIZATION ${PROJECT_ID}_AUTHOR_ORGANIZATION "")

  # Author domain
  _check_and_set_optional_meta_data(META_AUTHOR_DOMAIN AUTHOR_DOMAIN "")
  _check_and_set_optional_meta_data(META_AUTHOR_DOMAIN ${PROJECT_ID}_AUTHOR_DOMAIN "")

  # Author maintainer
  _check_and_set_optional_meta_data(META_AUTHOR_MAINTAINER AUTHOR_MAINTAINER "")
  _check_and_set_optional_meta_data(META_AUTHOR_MAINTAINER ${PROJECT_ID}_AUTHOR_MAINTAINER "")

  # Remove check functions
  unset(_check_and_set_mandatory_meta_data)
  unset(_check_and_set_optional_meta_data)

endfunction()

# Report project information
function(ProjectMetaReport)
  message(STATUS "")
  message(STATUS "----------------------------------------------------")
  message(STATUS "                 ProjectMeta.cmake")
  message(STATUS "")
  message(STATUS "PROJECT_ID: ${PROJECT_ID}")
  message(STATUS "PROJECT_NAME: ${PROJECT_NAME}")
  message(STATUS "PROJECT_DESCRIPTION: ${PROJECT_DESCRIPTION}")
  message(STATUS "AUTHOR_ORGANIZATION: ${AUTHOR_ORGANIZATION}")
  message(STATUS "AUTHOR_DOMAIN: ${AUTHOR_DOMAIN}")
  message(STATUS "AUTHOR_MAINTAINER: ${AUTHOR_MAINTAINER}")
  message(STATUS "")
  message(STATUS "VERSION_MAJOR: ${VERSION_MAJOR}")
  message(STATUS "VERSION_MINOR: ${VERSION_MINOR}")
  message(STATUS "VERSION_PATCH: ${VERSION_PATCH}")
  message(STATUS "VERSION_REVISION: ${VERSION_REVISION}")
  message(STATUS "VERSION: ${VERSION}")
  message(STATUS "VERSION_NAME: ${VERSION_NAME}")
  message(STATUS "")
  message(STATUS "----------------------------------------------------")
  message(STATUS "")
endfunction()
