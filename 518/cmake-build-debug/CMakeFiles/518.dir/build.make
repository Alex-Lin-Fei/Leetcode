# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\C++\leetcode\518

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\C++\leetcode\518\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/518.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/518.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/518.dir/flags.make

CMakeFiles/518.dir/main.cpp.obj: CMakeFiles/518.dir/flags.make
CMakeFiles/518.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\C++\leetcode\518\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/518.dir/main.cpp.obj"
	D:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\518.dir\main.cpp.obj -c D:\C++\leetcode\518\main.cpp

CMakeFiles/518.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/518.dir/main.cpp.i"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\C++\leetcode\518\main.cpp > CMakeFiles\518.dir\main.cpp.i

CMakeFiles/518.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/518.dir/main.cpp.s"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\C++\leetcode\518\main.cpp -o CMakeFiles\518.dir\main.cpp.s

# Object files for target 518
518_OBJECTS = \
"CMakeFiles/518.dir/main.cpp.obj"

# External object files for target 518
518_EXTERNAL_OBJECTS =

518.exe: CMakeFiles/518.dir/main.cpp.obj
518.exe: CMakeFiles/518.dir/build.make
518.exe: CMakeFiles/518.dir/linklibs.rsp
518.exe: CMakeFiles/518.dir/objects1.rsp
518.exe: CMakeFiles/518.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\C++\leetcode\518\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 518.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\518.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/518.dir/build: 518.exe

.PHONY : CMakeFiles/518.dir/build

CMakeFiles/518.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\518.dir\cmake_clean.cmake
.PHONY : CMakeFiles/518.dir/clean

CMakeFiles/518.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\C++\leetcode\518 D:\C++\leetcode\518 D:\C++\leetcode\518\cmake-build-debug D:\C++\leetcode\518\cmake-build-debug D:\C++\leetcode\518\cmake-build-debug\CMakeFiles\518.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/518.dir/depend

