# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/闻嘉迅/liucan/code/NJU-FLA-2023FALL-PROJ

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/闻嘉迅/liucan/code/NJU-FLA-2023FALL-PROJ/build

# Include any dependencies generated for this target.
include TuringMachine/CMakeFiles/srftgrdgrdg,.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include TuringMachine/CMakeFiles/srftgrdgrdg,.dir/compiler_depend.make

# Include the progress variables for this target.
include TuringMachine/CMakeFiles/srftgrdgrdg,.dir/progress.make

# Include the compile flags for this target's objects.
include TuringMachine/CMakeFiles/srftgrdgrdg,.dir/flags.make

TuringMachine/CMakeFiles/srftgrdgrdg,.dir/TuringMachine.o: TuringMachine/CMakeFiles/srftgrdgrdg,.dir/flags.make
TuringMachine/CMakeFiles/srftgrdgrdg,.dir/TuringMachine.o: ../TuringMachine/TuringMachine.cpp
TuringMachine/CMakeFiles/srftgrdgrdg,.dir/TuringMachine.o: TuringMachine/CMakeFiles/srftgrdgrdg,.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/闻嘉迅/liucan/code/NJU-FLA-2023FALL-PROJ/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object TuringMachine/CMakeFiles/srftgrdgrdg,.dir/TuringMachine.o"
	cd /mnt/c/Users/闻嘉迅/liucan/code/NJU-FLA-2023FALL-PROJ/build/TuringMachine && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT TuringMachine/CMakeFiles/srftgrdgrdg,.dir/TuringMachine.o -MF CMakeFiles/srftgrdgrdg,.dir/TuringMachine.o.d -o CMakeFiles/srftgrdgrdg,.dir/TuringMachine.o -c /mnt/c/Users/闻嘉迅/liucan/code/NJU-FLA-2023FALL-PROJ/TuringMachine/TuringMachine.cpp

TuringMachine/CMakeFiles/srftgrdgrdg,.dir/TuringMachine.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/srftgrdgrdg,.dir/TuringMachine.i"
	cd /mnt/c/Users/闻嘉迅/liucan/code/NJU-FLA-2023FALL-PROJ/build/TuringMachine && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/闻嘉迅/liucan/code/NJU-FLA-2023FALL-PROJ/TuringMachine/TuringMachine.cpp > CMakeFiles/srftgrdgrdg,.dir/TuringMachine.i

TuringMachine/CMakeFiles/srftgrdgrdg,.dir/TuringMachine.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/srftgrdgrdg,.dir/TuringMachine.s"
	cd /mnt/c/Users/闻嘉迅/liucan/code/NJU-FLA-2023FALL-PROJ/build/TuringMachine && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/闻嘉迅/liucan/code/NJU-FLA-2023FALL-PROJ/TuringMachine/TuringMachine.cpp -o CMakeFiles/srftgrdgrdg,.dir/TuringMachine.s

# Object files for target srftgrdgrdg,
srftgrdgrdg,_OBJECTS = \
"CMakeFiles/srftgrdgrdg,.dir/TuringMachine.o"

# External object files for target srftgrdgrdg,
srftgrdgrdg,_EXTERNAL_OBJECTS =

TuringMachine/libsrftgrdgrdg,.a: TuringMachine/CMakeFiles/srftgrdgrdg,.dir/TuringMachine.o
TuringMachine/libsrftgrdgrdg,.a: TuringMachine/CMakeFiles/srftgrdgrdg,.dir/build.make
TuringMachine/libsrftgrdgrdg,.a: TuringMachine/CMakeFiles/srftgrdgrdg,.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/闻嘉迅/liucan/code/NJU-FLA-2023FALL-PROJ/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libsrftgrdgrdg,.a"
	cd /mnt/c/Users/闻嘉迅/liucan/code/NJU-FLA-2023FALL-PROJ/build/TuringMachine && $(CMAKE_COMMAND) -P CMakeFiles/srftgrdgrdg,.dir/cmake_clean_target.cmake
	cd /mnt/c/Users/闻嘉迅/liucan/code/NJU-FLA-2023FALL-PROJ/build/TuringMachine && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/srftgrdgrdg,.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
TuringMachine/CMakeFiles/srftgrdgrdg,.dir/build: TuringMachine/libsrftgrdgrdg,.a
.PHONY : TuringMachine/CMakeFiles/srftgrdgrdg,.dir/build

TuringMachine/CMakeFiles/srftgrdgrdg,.dir/clean:
	cd /mnt/c/Users/闻嘉迅/liucan/code/NJU-FLA-2023FALL-PROJ/build/TuringMachine && $(CMAKE_COMMAND) -P CMakeFiles/srftgrdgrdg,.dir/cmake_clean.cmake
.PHONY : TuringMachine/CMakeFiles/srftgrdgrdg,.dir/clean

TuringMachine/CMakeFiles/srftgrdgrdg,.dir/depend:
	cd /mnt/c/Users/闻嘉迅/liucan/code/NJU-FLA-2023FALL-PROJ/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/闻嘉迅/liucan/code/NJU-FLA-2023FALL-PROJ /mnt/c/Users/闻嘉迅/liucan/code/NJU-FLA-2023FALL-PROJ/TuringMachine /mnt/c/Users/闻嘉迅/liucan/code/NJU-FLA-2023FALL-PROJ/build /mnt/c/Users/闻嘉迅/liucan/code/NJU-FLA-2023FALL-PROJ/build/TuringMachine /mnt/c/Users/闻嘉迅/liucan/code/NJU-FLA-2023FALL-PROJ/build/TuringMachine/CMakeFiles/srftgrdgrdg,.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : TuringMachine/CMakeFiles/srftgrdgrdg,.dir/depend

