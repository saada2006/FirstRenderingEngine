# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.8)
   message(FATAL_ERROR "CMake >= 2.8.0 required")
endif()
if(CMAKE_VERSION VERSION_LESS "2.8.3")
   message(FATAL_ERROR "CMake >= 2.8.3 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.8.3...3.25)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_cmake_targets_defined "")
set(_cmake_targets_not_defined "")
set(_cmake_expected_targets "")
foreach(_cmake_expected_target IN ITEMS stb::image stb::image-write stb::image-resize stb::perlin stb::vorbis)
  list(APPEND _cmake_expected_targets "${_cmake_expected_target}")
  if(TARGET "${_cmake_expected_target}")
    list(APPEND _cmake_targets_defined "${_cmake_expected_target}")
  else()
    list(APPEND _cmake_targets_not_defined "${_cmake_expected_target}")
  endif()
endforeach()
unset(_cmake_expected_target)
if(_cmake_targets_defined STREQUAL _cmake_expected_targets)
  unset(_cmake_targets_defined)
  unset(_cmake_targets_not_defined)
  unset(_cmake_expected_targets)
  unset(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT _cmake_targets_defined STREQUAL "")
  string(REPLACE ";" ", " _cmake_targets_defined_text "${_cmake_targets_defined}")
  string(REPLACE ";" ", " _cmake_targets_not_defined_text "${_cmake_targets_not_defined}")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_cmake_targets_defined_text}\nTargets not yet defined: ${_cmake_targets_not_defined_text}\n")
endif()
unset(_cmake_targets_defined)
unset(_cmake_targets_not_defined)
unset(_cmake_expected_targets)


# Create imported target stb::image
add_library(stb::image STATIC IMPORTED)

set_target_properties(stb::image PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/home/saad/Desktop/MakerPortfolioProjects/FirstRenderingEngine/extern/stb_image"
)

# Create imported target stb::image-write
add_library(stb::image-write STATIC IMPORTED)

set_target_properties(stb::image-write PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/home/saad/Desktop/MakerPortfolioProjects/FirstRenderingEngine/extern/stb_image"
)

# Create imported target stb::image-resize
add_library(stb::image-resize STATIC IMPORTED)

set_target_properties(stb::image-resize PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/home/saad/Desktop/MakerPortfolioProjects/FirstRenderingEngine/extern/stb_image"
)

# Create imported target stb::perlin
add_library(stb::perlin STATIC IMPORTED)

set_target_properties(stb::perlin PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/home/saad/Desktop/MakerPortfolioProjects/FirstRenderingEngine/extern/stb_image"
)

# Create imported target stb::vorbis
add_library(stb::vorbis STATIC IMPORTED)

set_target_properties(stb::vorbis PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/home/saad/Desktop/MakerPortfolioProjects/FirstRenderingEngine/build/extern/stb_image/include"
)

# Import target "stb::image" for configuration ""
set_property(TARGET stb::image APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(stb::image PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "C"
  IMPORTED_LOCATION_NOCONFIG "/home/saad/Desktop/MakerPortfolioProjects/FirstRenderingEngine/build/extern/stb_image/libstb-image.a"
  )

# Import target "stb::image-write" for configuration ""
set_property(TARGET stb::image-write APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(stb::image-write PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "C"
  IMPORTED_LOCATION_NOCONFIG "/home/saad/Desktop/MakerPortfolioProjects/FirstRenderingEngine/build/extern/stb_image/libstb-image-write.a"
  )

# Import target "stb::image-resize" for configuration ""
set_property(TARGET stb::image-resize APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(stb::image-resize PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "C"
  IMPORTED_LOCATION_NOCONFIG "/home/saad/Desktop/MakerPortfolioProjects/FirstRenderingEngine/build/extern/stb_image/libstb-image-resize.a"
  )

# Import target "stb::perlin" for configuration ""
set_property(TARGET stb::perlin APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(stb::perlin PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "C"
  IMPORTED_LOCATION_NOCONFIG "/home/saad/Desktop/MakerPortfolioProjects/FirstRenderingEngine/build/extern/stb_image/libstb-perlin.a"
  )

# Import target "stb::vorbis" for configuration ""
set_property(TARGET stb::vorbis APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(stb::vorbis PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "C"
  IMPORTED_LOCATION_NOCONFIG "/home/saad/Desktop/MakerPortfolioProjects/FirstRenderingEngine/build/extern/stb_image/libstb-vorbis.a"
  )

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)