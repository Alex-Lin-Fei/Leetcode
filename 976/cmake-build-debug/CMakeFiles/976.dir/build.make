# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\JetBrains\CLion\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\JetBrains\CLion\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\algorithm\leetcode\976

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\algorithm\leetcode\976\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/976.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/976.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/976.dir/flags.make

CMakeFiles/976.dir/main.cpp.obj: CMakeFiles/976.dir/flags.make
CMakeFiles/976.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\algorithm\leetcode\976\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/976.dir/main.cpp.obj"
	D:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\976.dir\main.cpp.obj -c D:\algorithm\leetcode\976\main.cpp

CMakeFiles/976.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/976.dir/main.cpp.i"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\algorithm\leetcode\976\main.cpp > CMakeFiles\976.dir\main.cpp.i

CMakeFiles/976.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/976.dir/main.cpp.s"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\algorithm\leetcode\976\main.cpp -o CMakeFiles\976.dir\main.cpp.s

# Object files for target 976
976_OBJECTS = \
"CMakeFiles/976.dir/main.cpp.obj"

# External object files for target 976
976_EXTERNAL_OBJECTS =

976.exe: CMakeFiles/976.dir/main.cpp.obj
976.exe: CMakeFiles/976.dir/build.make
976.exe: CMakeFiles/976.dir/linklibs.rsp
976.exe: CMakeFiles/976.dir/objects1.rsp
976.exe: CMakeFiles/976.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\algorithm\leetcode\976\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 976.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\976.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/976.dir/build: 976.exe

.PHONY : CMakeFiles/976.dir/build

CMakeFiles/976.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\976.dir\cmake_clean.cmake
.PHONY : CMakeFiles/976.dir/clean

CMakeFiles/976.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\algorithm\leetcode\976 D:\algorithm\leetcode\976 D:\algorithm\leetcode\976\cmake-build-debug D:\algorithm\leetcode\976\cmake-build-debug D:\algorithm\leetcode\976\cmake-build-debug\CMakeFiles\976.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/976.dir/depend

