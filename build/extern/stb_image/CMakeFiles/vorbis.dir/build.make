# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/saad/.local/lib/python3.10/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/saad/.local/lib/python3.10/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/saad/Desktop/MakerPortfolioProjects/FirstRenderingEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/saad/Desktop/MakerPortfolioProjects/FirstRenderingEngine/build

# Include any dependencies generated for this target.
include extern/stb_image/CMakeFiles/vorbis.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include extern/stb_image/CMakeFiles/vorbis.dir/compiler_depend.make

# Include the progress variables for this target.
include extern/stb_image/CMakeFiles/vorbis.dir/progress.make

# Include the compile flags for this target's objects.
include extern/stb_image/CMakeFiles/vorbis.dir/flags.make

extern/stb_image/CMakeFiles/vorbis.dir/stb/stb_vorbis.c.o: extern/stb_image/CMakeFiles/vorbis.dir/flags.make
extern/stb_image/CMakeFiles/vorbis.dir/stb/stb_vorbis.c.o: /home/saad/Desktop/MakerPortfolioProjects/FirstRenderingEngine/extern/stb_image/stb/stb_vorbis.c
extern/stb_image/CMakeFiles/vorbis.dir/stb/stb_vorbis.c.o: extern/stb_image/CMakeFiles/vorbis.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/saad/Desktop/MakerPortfolioProjects/FirstRenderingEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object extern/stb_image/CMakeFiles/vorbis.dir/stb/stb_vorbis.c.o"
	cd /home/saad/Desktop/MakerPortfolioProjects/FirstRenderingEngine/build/extern/stb_image && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT extern/stb_image/CMakeFiles/vorbis.dir/stb/stb_vorbis.c.o -MF CMakeFiles/vorbis.dir/stb/stb_vorbis.c.o.d -o CMakeFiles/vorbis.dir/stb/stb_vorbis.c.o -c /home/saad/Desktop/MakerPortfolioProjects/FirstRenderingEngine/extern/stb_image/stb/stb_vorbis.c

extern/stb_image/CMakeFiles/vorbis.dir/stb/stb_vorbis.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/vorbis.dir/stb/stb_vorbis.c.i"
	cd /home/saad/Desktop/MakerPortfolioProjects/FirstRenderingEngine/build/extern/stb_image && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/saad/Desktop/MakerPortfolioProjects/FirstRenderingEngine/extern/stb_image/stb/stb_vorbis.c > CMakeFiles/vorbis.dir/stb/stb_vorbis.c.i

extern/stb_image/CMakeFiles/vorbis.dir/stb/stb_vorbis.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/vorbis.dir/stb/stb_vorbis.c.s"
	cd /home/saad/Desktop/MakerPortfolioProjects/FirstRenderingEngine/build/extern/stb_image && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/saad/Desktop/MakerPortfolioProjects/FirstRenderingEngine/extern/stb_image/stb/stb_vorbis.c -o CMakeFiles/vorbis.dir/stb/stb_vorbis.c.s

# Object files for target vorbis
vorbis_OBJECTS = \
"CMakeFiles/vorbis.dir/stb/stb_vorbis.c.o"

# External object files for target vorbis
vorbis_EXTERNAL_OBJECTS =

extern/stb_image/libstb-vorbis.a: extern/stb_image/CMakeFiles/vorbis.dir/stb/stb_vorbis.c.o
extern/stb_image/libstb-vorbis.a: extern/stb_image/CMakeFiles/vorbis.dir/build.make
extern/stb_image/libstb-vorbis.a: extern/stb_image/CMakeFiles/vorbis.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/saad/Desktop/MakerPortfolioProjects/FirstRenderingEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libstb-vorbis.a"
	cd /home/saad/Desktop/MakerPortfolioProjects/FirstRenderingEngine/build/extern/stb_image && $(CMAKE_COMMAND) -P CMakeFiles/vorbis.dir/cmake_clean_target.cmake
	cd /home/saad/Desktop/MakerPortfolioProjects/FirstRenderingEngine/build/extern/stb_image && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vorbis.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
extern/stb_image/CMakeFiles/vorbis.dir/build: extern/stb_image/libstb-vorbis.a
.PHONY : extern/stb_image/CMakeFiles/vorbis.dir/build

extern/stb_image/CMakeFiles/vorbis.dir/clean:
	cd /home/saad/Desktop/MakerPortfolioProjects/FirstRenderingEngine/build/extern/stb_image && $(CMAKE_COMMAND) -P CMakeFiles/vorbis.dir/cmake_clean.cmake
.PHONY : extern/stb_image/CMakeFiles/vorbis.dir/clean

extern/stb_image/CMakeFiles/vorbis.dir/depend:
	cd /home/saad/Desktop/MakerPortfolioProjects/FirstRenderingEngine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/saad/Desktop/MakerPortfolioProjects/FirstRenderingEngine /home/saad/Desktop/MakerPortfolioProjects/FirstRenderingEngine/extern/stb_image /home/saad/Desktop/MakerPortfolioProjects/FirstRenderingEngine/build /home/saad/Desktop/MakerPortfolioProjects/FirstRenderingEngine/build/extern/stb_image /home/saad/Desktop/MakerPortfolioProjects/FirstRenderingEngine/build/extern/stb_image/CMakeFiles/vorbis.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : extern/stb_image/CMakeFiles/vorbis.dir/depend

