# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/kristian/clion-2018.3.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/kristian/clion-2018.3.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kristian/CLionProjects/da-nan-milestone1/mp1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kristian/CLionProjects/da-nan-milestone1/mp1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/mp1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mp1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mp1.dir/flags.make

CMakeFiles/mp1.dir/main.c.o: CMakeFiles/mp1.dir/flags.make
CMakeFiles/mp1.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kristian/CLionProjects/da-nan-milestone1/mp1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/mp1.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mp1.dir/main.c.o   -c /home/kristian/CLionProjects/da-nan-milestone1/mp1/main.c

CMakeFiles/mp1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mp1.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kristian/CLionProjects/da-nan-milestone1/mp1/main.c > CMakeFiles/mp1.dir/main.c.i

CMakeFiles/mp1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mp1.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kristian/CLionProjects/da-nan-milestone1/mp1/main.c -o CMakeFiles/mp1.dir/main.c.s

# Object files for target mp1
mp1_OBJECTS = \
"CMakeFiles/mp1.dir/main.c.o"

# External object files for target mp1
mp1_EXTERNAL_OBJECTS =

mp1: CMakeFiles/mp1.dir/main.c.o
mp1: CMakeFiles/mp1.dir/build.make
mp1: CMakeFiles/mp1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kristian/CLionProjects/da-nan-milestone1/mp1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable mp1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mp1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mp1.dir/build: mp1

.PHONY : CMakeFiles/mp1.dir/build

CMakeFiles/mp1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mp1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mp1.dir/clean

CMakeFiles/mp1.dir/depend:
	cd /home/kristian/CLionProjects/da-nan-milestone1/mp1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kristian/CLionProjects/da-nan-milestone1/mp1 /home/kristian/CLionProjects/da-nan-milestone1/mp1 /home/kristian/CLionProjects/da-nan-milestone1/mp1/cmake-build-debug /home/kristian/CLionProjects/da-nan-milestone1/mp1/cmake-build-debug /home/kristian/CLionProjects/da-nan-milestone1/mp1/cmake-build-debug/CMakeFiles/mp1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mp1.dir/depend

