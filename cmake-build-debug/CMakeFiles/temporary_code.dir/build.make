# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/yaokangpeng/Documents/CODE/DataStructure_mission/DataStructure_mission

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yaokangpeng/Documents/CODE/DataStructure_mission/DataStructure_mission/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/temporary_code.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/temporary_code.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/temporary_code.dir/flags.make

CMakeFiles/temporary_code.dir/main.c.o: CMakeFiles/temporary_code.dir/flags.make
CMakeFiles/temporary_code.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yaokangpeng/Documents/CODE/DataStructure_mission/DataStructure_mission/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/temporary_code.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/temporary_code.dir/main.c.o   -c /Users/yaokangpeng/Documents/CODE/DataStructure_mission/DataStructure_mission/main.c

CMakeFiles/temporary_code.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/temporary_code.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/yaokangpeng/Documents/CODE/DataStructure_mission/DataStructure_mission/main.c > CMakeFiles/temporary_code.dir/main.c.i

CMakeFiles/temporary_code.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/temporary_code.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/yaokangpeng/Documents/CODE/DataStructure_mission/DataStructure_mission/main.c -o CMakeFiles/temporary_code.dir/main.c.s

CMakeFiles/temporary_code.dir/main.c.o.requires:

.PHONY : CMakeFiles/temporary_code.dir/main.c.o.requires

CMakeFiles/temporary_code.dir/main.c.o.provides: CMakeFiles/temporary_code.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/temporary_code.dir/build.make CMakeFiles/temporary_code.dir/main.c.o.provides.build
.PHONY : CMakeFiles/temporary_code.dir/main.c.o.provides

CMakeFiles/temporary_code.dir/main.c.o.provides.build: CMakeFiles/temporary_code.dir/main.c.o


# Object files for target temporary_code
temporary_code_OBJECTS = \
"CMakeFiles/temporary_code.dir/main.c.o"

# External object files for target temporary_code
temporary_code_EXTERNAL_OBJECTS =

temporary_code: CMakeFiles/temporary_code.dir/main.c.o
temporary_code: CMakeFiles/temporary_code.dir/build.make
temporary_code: CMakeFiles/temporary_code.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yaokangpeng/Documents/CODE/DataStructure_mission/DataStructure_mission/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable temporary_code"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/temporary_code.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/temporary_code.dir/build: temporary_code

.PHONY : CMakeFiles/temporary_code.dir/build

CMakeFiles/temporary_code.dir/requires: CMakeFiles/temporary_code.dir/main.c.o.requires

.PHONY : CMakeFiles/temporary_code.dir/requires

CMakeFiles/temporary_code.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/temporary_code.dir/cmake_clean.cmake
.PHONY : CMakeFiles/temporary_code.dir/clean

CMakeFiles/temporary_code.dir/depend:
	cd /Users/yaokangpeng/Documents/CODE/DataStructure_mission/DataStructure_mission/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yaokangpeng/Documents/CODE/DataStructure_mission/DataStructure_mission /Users/yaokangpeng/Documents/CODE/DataStructure_mission/DataStructure_mission /Users/yaokangpeng/Documents/CODE/DataStructure_mission/DataStructure_mission/cmake-build-debug /Users/yaokangpeng/Documents/CODE/DataStructure_mission/DataStructure_mission/cmake-build-debug /Users/yaokangpeng/Documents/CODE/DataStructure_mission/DataStructure_mission/cmake-build-debug/CMakeFiles/temporary_code.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/temporary_code.dir/depend

