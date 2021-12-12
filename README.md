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
  GIT_TAG 1.2.1
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
PROJECT_NAMESPACE | project namespace
PROJECT_COPYRIGHT | project copyright
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
[C] | PROJECT_ID | project identifier
[C] | PROJECT_ID_LOWER | project identifier in lower case
[*] | PROJECT_NAME | project name
[C] | PROJECT_NAME_LOWER | project name in lower case
 -  | PROJECT_DESCRIPTION | project description
 -  | PROJECT_NAMESPACE | project namespace
 -  | PROJECT_COPYRIGHT | project copyright
 -  | PROJECT_URL | project url
 -  | AUTHOR_ORGANIZATION | project organization
 -  | AUTHOR_DOMAIN | project domain url
 -  | AUTHOR_MAINTAINER | project maintainer
[*] | VERSION_MAJOR | version major
[*] | VERSION_MINOR | version minor
[C] | VERSION_PATCH | version patch
[C] | VERSION_REVISION | version revision
[C] | VERSION | version (optional, will be built from version info if not set)
[C] | VERSION_NAME | version name (optional, will be built from version info if not set)

[*] Mandatory meta data
[C] Conditionals meta data which will be setup based on mandatory meta data.
