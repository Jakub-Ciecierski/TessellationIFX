# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/jakub/apps/cmake/cmake-3.5.2/bin/cmake

# The command to remove a file.
RM = /home/jakub/apps/cmake/cmake-3.5.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jakub/programming/duck

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jakub/programming/duck

# Include any dependencies generated for this target.
include dependencies/glm/examples/CMakeFiles/splitview.dir/depend.make

# Include the progress variables for this target.
include dependencies/glm/examples/CMakeFiles/splitview.dir/progress.make

# Include the compile flags for this target's objects.
include dependencies/glm/examples/CMakeFiles/splitview.dir/flags.make

dependencies/glm/examples/CMakeFiles/splitview.dir/splitview.c.o: dependencies/glm/examples/CMakeFiles/splitview.dir/flags.make
dependencies/glm/examples/CMakeFiles/splitview.dir/splitview.c.o: dependencies/glfw-3.1.2/examples/splitview.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jakub/programming/duck/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object dependencies/glm/examples/CMakeFiles/splitview.dir/splitview.c.o"
	cd /home/jakub/programming/duck/dependencies/glm/examples && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/splitview.dir/splitview.c.o   -c /home/jakub/programming/duck/dependencies/glfw-3.1.2/examples/splitview.c

dependencies/glm/examples/CMakeFiles/splitview.dir/splitview.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/splitview.dir/splitview.c.i"
	cd /home/jakub/programming/duck/dependencies/glm/examples && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jakub/programming/duck/dependencies/glfw-3.1.2/examples/splitview.c > CMakeFiles/splitview.dir/splitview.c.i

dependencies/glm/examples/CMakeFiles/splitview.dir/splitview.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/splitview.dir/splitview.c.s"
	cd /home/jakub/programming/duck/dependencies/glm/examples && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jakub/programming/duck/dependencies/glfw-3.1.2/examples/splitview.c -o CMakeFiles/splitview.dir/splitview.c.s

dependencies/glm/examples/CMakeFiles/splitview.dir/splitview.c.o.requires:

.PHONY : dependencies/glm/examples/CMakeFiles/splitview.dir/splitview.c.o.requires

dependencies/glm/examples/CMakeFiles/splitview.dir/splitview.c.o.provides: dependencies/glm/examples/CMakeFiles/splitview.dir/splitview.c.o.requires
	$(MAKE) -f dependencies/glm/examples/CMakeFiles/splitview.dir/build.make dependencies/glm/examples/CMakeFiles/splitview.dir/splitview.c.o.provides.build
.PHONY : dependencies/glm/examples/CMakeFiles/splitview.dir/splitview.c.o.provides

dependencies/glm/examples/CMakeFiles/splitview.dir/splitview.c.o.provides.build: dependencies/glm/examples/CMakeFiles/splitview.dir/splitview.c.o


# Object files for target splitview
splitview_OBJECTS = \
"CMakeFiles/splitview.dir/splitview.c.o"

# External object files for target splitview
splitview_EXTERNAL_OBJECTS =

dependencies/glm/examples/splitview: dependencies/glm/examples/CMakeFiles/splitview.dir/splitview.c.o
dependencies/glm/examples/splitview: dependencies/glm/examples/CMakeFiles/splitview.dir/build.make
dependencies/glm/examples/splitview: dependencies/glm/src/libglfw3.a
dependencies/glm/examples/splitview: /usr/lib/x86_64-linux-gnu/librt.so
dependencies/glm/examples/splitview: /usr/lib/x86_64-linux-gnu/libm.so
dependencies/glm/examples/splitview: /usr/lib/x86_64-linux-gnu/libX11.so
dependencies/glm/examples/splitview: /usr/lib/x86_64-linux-gnu/libXrandr.so
dependencies/glm/examples/splitview: /usr/lib/x86_64-linux-gnu/libXinerama.so
dependencies/glm/examples/splitview: /usr/lib/x86_64-linux-gnu/libXi.so
dependencies/glm/examples/splitview: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
dependencies/glm/examples/splitview: /usr/lib/x86_64-linux-gnu/libXcursor.so
dependencies/glm/examples/splitview: /usr/lib/x86_64-linux-gnu/libGL.so
dependencies/glm/examples/splitview: dependencies/glm/examples/CMakeFiles/splitview.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jakub/programming/duck/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable splitview"
	cd /home/jakub/programming/duck/dependencies/glm/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/splitview.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
dependencies/glm/examples/CMakeFiles/splitview.dir/build: dependencies/glm/examples/splitview

.PHONY : dependencies/glm/examples/CMakeFiles/splitview.dir/build

dependencies/glm/examples/CMakeFiles/splitview.dir/requires: dependencies/glm/examples/CMakeFiles/splitview.dir/splitview.c.o.requires

.PHONY : dependencies/glm/examples/CMakeFiles/splitview.dir/requires

dependencies/glm/examples/CMakeFiles/splitview.dir/clean:
	cd /home/jakub/programming/duck/dependencies/glm/examples && $(CMAKE_COMMAND) -P CMakeFiles/splitview.dir/cmake_clean.cmake
.PHONY : dependencies/glm/examples/CMakeFiles/splitview.dir/clean

dependencies/glm/examples/CMakeFiles/splitview.dir/depend:
	cd /home/jakub/programming/duck && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jakub/programming/duck /home/jakub/programming/duck/dependencies/glfw-3.1.2/examples /home/jakub/programming/duck /home/jakub/programming/duck/dependencies/glm/examples /home/jakub/programming/duck/dependencies/glm/examples/CMakeFiles/splitview.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : dependencies/glm/examples/CMakeFiles/splitview.dir/depend
