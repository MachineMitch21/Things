# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mitch/Documents/AntisocialEngine/Sample

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mitch/Documents/AntisocialEngine/Sample/build

# Include any dependencies generated for this target.
include CMakeFiles/antisocial_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/antisocial_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/antisocial_test.dir/flags.make

CMakeFiles/antisocial_test.dir/src/main.cpp.o: CMakeFiles/antisocial_test.dir/flags.make
CMakeFiles/antisocial_test.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mitch/Documents/AntisocialEngine/Sample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/antisocial_test.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/antisocial_test.dir/src/main.cpp.o -c /home/mitch/Documents/AntisocialEngine/Sample/src/main.cpp

CMakeFiles/antisocial_test.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/antisocial_test.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mitch/Documents/AntisocialEngine/Sample/src/main.cpp > CMakeFiles/antisocial_test.dir/src/main.cpp.i

CMakeFiles/antisocial_test.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/antisocial_test.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mitch/Documents/AntisocialEngine/Sample/src/main.cpp -o CMakeFiles/antisocial_test.dir/src/main.cpp.s

CMakeFiles/antisocial_test.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/antisocial_test.dir/src/main.cpp.o.requires

CMakeFiles/antisocial_test.dir/src/main.cpp.o.provides: CMakeFiles/antisocial_test.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/antisocial_test.dir/build.make CMakeFiles/antisocial_test.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/antisocial_test.dir/src/main.cpp.o.provides

CMakeFiles/antisocial_test.dir/src/main.cpp.o.provides.build: CMakeFiles/antisocial_test.dir/src/main.cpp.o


# Object files for target antisocial_test
antisocial_test_OBJECTS = \
"CMakeFiles/antisocial_test.dir/src/main.cpp.o"

# External object files for target antisocial_test
antisocial_test_EXTERNAL_OBJECTS =

antisocial_test: CMakeFiles/antisocial_test.dir/src/main.cpp.o
antisocial_test: CMakeFiles/antisocial_test.dir/build.make
antisocial_test: /usr/local/lib/libantisocial.so
antisocial_test: CMakeFiles/antisocial_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mitch/Documents/AntisocialEngine/Sample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable antisocial_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/antisocial_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/antisocial_test.dir/build: antisocial_test

.PHONY : CMakeFiles/antisocial_test.dir/build

CMakeFiles/antisocial_test.dir/requires: CMakeFiles/antisocial_test.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/antisocial_test.dir/requires

CMakeFiles/antisocial_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/antisocial_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/antisocial_test.dir/clean

CMakeFiles/antisocial_test.dir/depend:
	cd /home/mitch/Documents/AntisocialEngine/Sample/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mitch/Documents/AntisocialEngine/Sample /home/mitch/Documents/AntisocialEngine/Sample /home/mitch/Documents/AntisocialEngine/Sample/build /home/mitch/Documents/AntisocialEngine/Sample/build /home/mitch/Documents/AntisocialEngine/Sample/build/CMakeFiles/antisocial_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/antisocial_test.dir/depend

