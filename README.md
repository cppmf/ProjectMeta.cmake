<p align="center">
  <img src="https://github.com/cppmf/artwork/raw/master/banner/ProjectMeta.cmake/ProjectMeta.png" height="100" />
</p>

<p align="center">
  CMake module to easily define meta data about your project
</p>

---

## Usage
The easiest way to use [ProjectMeta.cmake](https://github.com/cppmf/ProjectMeta.cmake) is by adding [GetCPM.cmake](https://github.com/cppmf/GetCPM.cmake) to your project.

First add GetCPM.cmake module :

```bash
mkdir cmake
wget -O cmake/CPM.cmake https://raw.githubusercontent.com/cppmf/GetCPM.cmake/master/GetCPM.cmake
```

Then add the following lines to the project's `CMakeLists.txt`.


```bash
# include GetCPM.cmake module
include(cmake/CPM.cmake)

# add GitInfo.cmake and tell where to find the root project
# by specifying the GIT_INFO_SOURCE_DIR variable.
CPMAddPackage(
  NAME ProjectMeta.cmake
  GITHUB_REPOSITORY cppmf/ProjectMeta.cmake
  VERSION 1.0.0
)

# then add meta data project before calling the project function
ProjectMeta(
        # Name of the project
        PROJECT_NAME "${PROJECT_NAME}"
        # Major version
        VERSION_MAJOR 1
        # Minor version
        VERSION_MINOR 0
        # Patch version
        # VERSION_PATCH 0
)
```

## Available variables

After calling ProjectMeta function, the following variables will be set

variable | description
---------|------------
META_PROJECT_ID | project identifier
META_PROJECT_NAME | project name
META_PROJECT_DESCRIPTION | project description
META_AUTHOR_ORGANIZATION | project organisation
META_AUTHOR_DOMAIN | project domain url
META_AUTHOR_MAINTAINER | project maintainer
META_VERSION_MAJOR | version major
META_VERSION_MINOR | version minor
META_VERSION_PATCH | version patch
META_VERSION_REVISION | version revision
META_VERSION | version (optional, will be built from version info if not set)
META_VERSION_NAME | version name (optional, will be built from version info if not set)
