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
CMAKE_SOURCE_DIR = D:\algorithm\leetcode\103

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\algorithm\leetcode\103\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/103.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/103.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/103.dir/flags.make

CMakeFiles/103.dir/main.cpp.obj: CMakeFiles/103.dir/flags.make
CMakeFiles/103.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\algorithm\leetcode\103\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/103.dir/main.cpp.obj"
	D:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\103.dir\main.cpp.obj -c D:\algorithm\leetcode\103\main.cpp

CMakeFiles/103.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/103.dir/main.cpp.i"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\algorithm\leetcode\103\main.cpp > CMakeFiles\103.dir\main.cpp.i

CMakeFiles/103.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/103.dir/main.cpp.s"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\algorithm\leetcode\103\main.cpp -o CMakeFiles\103.dir\main.cpp.s

# Object files for target 103
103_OBJECTS = \
"CMakeFiles/103.dir/main.cpp.obj"

# External object files for target 103
103_EXTERNAL_OBJECTS =

103.exe: CMakeFiles/103.dir/main.cpp.obj
103.exe: CMakeFiles/103.dir/build.make
103.exe: CMakeFiles/103.dir/linklibs.rsp
103.exe: CMakeFiles/103.dir/objects1.rsp
103.exe: CMakeFiles/103.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\algorithm\leetcode\103\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 103.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\103.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/103.dir/build: 103.exe

.PHONY : CMakeFiles/103.dir/build

CMakeFiles/103.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\103.dir\cmake_clean.cmake
.PHONY : CMakeFiles/103.dir/clean

CMakeFiles/103.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\algorithm\leetcode\103 D:\algorithm\leetcode\103 D:\algorithm\leetcode\103\cmake-build-debug D:\algorithm\leetcode\103\cmake-build-debug D:\algorithm\leetcode\103\cmake-build-debug\CMakeFiles\103.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/103.dir/depend

