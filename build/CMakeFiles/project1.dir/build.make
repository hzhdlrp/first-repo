# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/vadimleonov/CLionProjects/project1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/vadimleonov/CLionProjects/project1/build

# Include any dependencies generated for this target.
include CMakeFiles/project1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/project1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/project1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project1.dir/flags.make

CMakeFiles/project1.dir/main.cpp.o: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/main.cpp.o: /Users/vadimleonov/CLionProjects/project1/main.cpp
CMakeFiles/project1.dir/main.cpp.o: CMakeFiles/project1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/vadimleonov/CLionProjects/project1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project1.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project1.dir/main.cpp.o -MF CMakeFiles/project1.dir/main.cpp.o.d -o CMakeFiles/project1.dir/main.cpp.o -c /Users/vadimleonov/CLionProjects/project1/main.cpp

CMakeFiles/project1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/project1.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vadimleonov/CLionProjects/project1/main.cpp > CMakeFiles/project1.dir/main.cpp.i

CMakeFiles/project1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/project1.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vadimleonov/CLionProjects/project1/main.cpp -o CMakeFiles/project1.dir/main.cpp.s

CMakeFiles/project1.dir/LongNum.cpp.o: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/LongNum.cpp.o: /Users/vadimleonov/CLionProjects/project1/LongNum.cpp
CMakeFiles/project1.dir/LongNum.cpp.o: CMakeFiles/project1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/vadimleonov/CLionProjects/project1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/project1.dir/LongNum.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project1.dir/LongNum.cpp.o -MF CMakeFiles/project1.dir/LongNum.cpp.o.d -o CMakeFiles/project1.dir/LongNum.cpp.o -c /Users/vadimleonov/CLionProjects/project1/LongNum.cpp

CMakeFiles/project1.dir/LongNum.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/project1.dir/LongNum.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vadimleonov/CLionProjects/project1/LongNum.cpp > CMakeFiles/project1.dir/LongNum.cpp.i

CMakeFiles/project1.dir/LongNum.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/project1.dir/LongNum.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vadimleonov/CLionProjects/project1/LongNum.cpp -o CMakeFiles/project1.dir/LongNum.cpp.s

# Object files for target project1
project1_OBJECTS = \
"CMakeFiles/project1.dir/main.cpp.o" \
"CMakeFiles/project1.dir/LongNum.cpp.o"

# External object files for target project1
project1_EXTERNAL_OBJECTS =

project1: CMakeFiles/project1.dir/main.cpp.o
project1: CMakeFiles/project1.dir/LongNum.cpp.o
project1: CMakeFiles/project1.dir/build.make
project1: liblongnum.dylib
project1: CMakeFiles/project1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/vadimleonov/CLionProjects/project1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable project1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project1.dir/build: project1
.PHONY : CMakeFiles/project1.dir/build

CMakeFiles/project1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project1.dir/clean

CMakeFiles/project1.dir/depend:
	cd /Users/vadimleonov/CLionProjects/project1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/vadimleonov/CLionProjects/project1 /Users/vadimleonov/CLionProjects/project1 /Users/vadimleonov/CLionProjects/project1/build /Users/vadimleonov/CLionProjects/project1/build /Users/vadimleonov/CLionProjects/project1/build/CMakeFiles/project1.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/project1.dir/depend

