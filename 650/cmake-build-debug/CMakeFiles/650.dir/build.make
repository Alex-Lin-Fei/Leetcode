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
CMAKE_SOURCE_DIR = D:\algorithm\leetcode\650

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\algorithm\leetcode\650\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/650.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/650.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/650.dir/flags.make

CMakeFiles/650.dir/main.cpp.obj: CMakeFiles/650.dir/flags.make
CMakeFiles/650.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\algorithm\leetcode\650\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/650.dir/main.cpp.obj"
	D:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\650.dir\main.cpp.obj -c D:\algorithm\leetcode\650\main.cpp

CMakeFiles/650.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/650.dir/main.cpp.i"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\algorithm\leetcode\650\main.cpp > CMakeFiles\650.dir\main.cpp.i

CMakeFiles/650.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/650.dir/main.cpp.s"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\algorithm\leetcode\650\main.cpp -o CMakeFiles\650.dir\main.cpp.s

# Object files for target 650
650_OBJECTS = \
"CMakeFiles/650.dir/main.cpp.obj"

# External object files for target 650
650_EXTERNAL_OBJECTS =

650.exe: CMakeFiles/650.dir/main.cpp.obj
650.exe: CMakeFiles/650.dir/build.make
650.exe: CMakeFiles/650.dir/linklibs.rsp
650.exe: CMakeFiles/650.dir/objects1.rsp
650.exe: CMakeFiles/650.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\algorithm\leetcode\650\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 650.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\650.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/650.dir/build: 650.exe

.PHONY : CMakeFiles/650.dir/build

CMakeFiles/650.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\650.dir\cmake_clean.cmake
.PHONY : CMakeFiles/650.dir/clean

CMakeFiles/650.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\algorithm\leetcode\650 D:\algorithm\leetcode\650 D:\algorithm\leetcode\650\cmake-build-debug D:\algorithm\leetcode\650\cmake-build-debug D:\algorithm\leetcode\650\cmake-build-debug\CMakeFiles\650.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/650.dir/depend

