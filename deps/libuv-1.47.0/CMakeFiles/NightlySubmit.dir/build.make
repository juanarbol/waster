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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/juanjose/GitHub/waster

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/juanjose/GitHub/waster

# Utility rule file for NightlySubmit.

# Include any custom commands dependencies for this target.
include deps/libuv-1.47.0/CMakeFiles/NightlySubmit.dir/compiler_depend.make

# Include the progress variables for this target.
include deps/libuv-1.47.0/CMakeFiles/NightlySubmit.dir/progress.make

deps/libuv-1.47.0/CMakeFiles/NightlySubmit:
	cd /Users/juanjose/GitHub/waster/deps/libuv-1.47.0 && /opt/homebrew/Cellar/cmake/3.27.3/bin/ctest -D NightlySubmit

NightlySubmit: deps/libuv-1.47.0/CMakeFiles/NightlySubmit
NightlySubmit: deps/libuv-1.47.0/CMakeFiles/NightlySubmit.dir/build.make
.PHONY : NightlySubmit

# Rule to build all files generated by this target.
deps/libuv-1.47.0/CMakeFiles/NightlySubmit.dir/build: NightlySubmit
.PHONY : deps/libuv-1.47.0/CMakeFiles/NightlySubmit.dir/build

deps/libuv-1.47.0/CMakeFiles/NightlySubmit.dir/clean:
	cd /Users/juanjose/GitHub/waster/deps/libuv-1.47.0 && $(CMAKE_COMMAND) -P CMakeFiles/NightlySubmit.dir/cmake_clean.cmake
.PHONY : deps/libuv-1.47.0/CMakeFiles/NightlySubmit.dir/clean

deps/libuv-1.47.0/CMakeFiles/NightlySubmit.dir/depend:
	cd /Users/juanjose/GitHub/waster && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/juanjose/GitHub/waster /Users/juanjose/GitHub/waster/deps/libuv-1.47.0 /Users/juanjose/GitHub/waster /Users/juanjose/GitHub/waster/deps/libuv-1.47.0 /Users/juanjose/GitHub/waster/deps/libuv-1.47.0/CMakeFiles/NightlySubmit.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : deps/libuv-1.47.0/CMakeFiles/NightlySubmit.dir/depend

