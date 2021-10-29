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
wget -O cmake/GetCPM.cmake https://raw.githubusercontent.com/cppmf/GetCPM.cmake/master/GetCPM.cmake
```

Then add the following lines to the project's `CMakeLists.txt`.


```bash
# include CPM.cmake module
include(cmake/GetCPM.cmake)

# add ProjectMeta.cmake
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

## Available parameters

List of available parameters while calling ProjectMeta function

parameter | description
---------|------------
PROJECT_ID | project identifier
PROJECT_NAME | project name
PROJECT_DESCRIPTION | project description
AUTHOR_ORGANIZATION | project
AUTHOR_DOMAIN | project domain url
AUTHOR_MAINTAINER | project maintainer
VERSION_MAJOR | version major
VERSION_MINOR | version minor
VERSION_PATCH | version patch
VERSION_REVISION | version revision
VERSION | version
VERSION_NAME | version name

## Available variables

After calling ProjectMeta function, the following variables will be set

 !  | variable | description
----|----------|------------
[C] | META_PROJECT_ID | project identifier
[*] | META_PROJECT_NAME | project name
 -  | META_PROJECT_DESCRIPTION | project description
 -  | META_AUTHOR_ORGANIZATION | project organization
 -  | META_AUTHOR_DOMAIN | project domain url
 -  | META_AUTHOR_MAINTAINER | project maintainer
[*] | META_VERSION_MAJOR | version major
[*] | META_VERSION_MINOR | version minor
[C] | META_VERSION_PATCH | version patch
[C] | META_VERSION_REVISION | version revision
[C] | META_VERSION | version (optional, will be built from version info if not set)
[C] | META_VERSION_NAME | version name (optional, will be built from version info if not set)

[*] Mandatory meta data
[C] Conditionals meta data which will be setup based on mandatory meta data.
