# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/csunix/sc19kb/Desktop/Programming_Project/sc19kb/cw1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/csunix/sc19kb/Desktop/Programming_Project/sc19kb/cw1/build

# Include any dependencies generated for this target.
include CMakeFiles/book_management.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/book_management.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/book_management.dir/flags.make

CMakeFiles/book_management.dir/book_management.c.o: CMakeFiles/book_management.dir/flags.make
CMakeFiles/book_management.dir/book_management.c.o: ../book_management.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/csunix/sc19kb/Desktop/Programming_Project/sc19kb/cw1/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/book_management.dir/book_management.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/book_management.dir/book_management.c.o   -c /home/csunix/sc19kb/Desktop/Programming_Project/sc19kb/cw1/book_management.c

CMakeFiles/book_management.dir/book_management.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/book_management.dir/book_management.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/csunix/sc19kb/Desktop/Programming_Project/sc19kb/cw1/book_management.c > CMakeFiles/book_management.dir/book_management.c.i

CMakeFiles/book_management.dir/book_management.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/book_management.dir/book_management.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/csunix/sc19kb/Desktop/Programming_Project/sc19kb/cw1/book_management.c -o CMakeFiles/book_management.dir/book_management.c.s

CMakeFiles/book_management.dir/book_management.c.o.requires:
.PHONY : CMakeFiles/book_management.dir/book_management.c.o.requires

CMakeFiles/book_management.dir/book_management.c.o.provides: CMakeFiles/book_management.dir/book_management.c.o.requires
	$(MAKE) -f CMakeFiles/book_management.dir/build.make CMakeFiles/book_management.dir/book_management.c.o.provides.build
.PHONY : CMakeFiles/book_management.dir/book_management.c.o.provides

CMakeFiles/book_management.dir/book_management.c.o.provides.build: CMakeFiles/book_management.dir/book_management.c.o

# Object files for target book_management
book_management_OBJECTS = \
"CMakeFiles/book_management.dir/book_management.c.o"

# External object files for target book_management
book_management_EXTERNAL_OBJECTS =

book_management: CMakeFiles/book_management.dir/book_management.c.o
book_management: CMakeFiles/book_management.dir/build.make
book_management: CMakeFiles/book_management.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable book_management"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/book_management.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/book_management.dir/build: book_management
.PHONY : CMakeFiles/book_management.dir/build

CMakeFiles/book_management.dir/requires: CMakeFiles/book_management.dir/book_management.c.o.requires
.PHONY : CMakeFiles/book_management.dir/requires

CMakeFiles/book_management.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/book_management.dir/cmake_clean.cmake
.PHONY : CMakeFiles/book_management.dir/clean

CMakeFiles/book_management.dir/depend:
	cd /home/csunix/sc19kb/Desktop/Programming_Project/sc19kb/cw1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/csunix/sc19kb/Desktop/Programming_Project/sc19kb/cw1 /home/csunix/sc19kb/Desktop/Programming_Project/sc19kb/cw1 /home/csunix/sc19kb/Desktop/Programming_Project/sc19kb/cw1/build /home/csunix/sc19kb/Desktop/Programming_Project/sc19kb/cw1/build /home/csunix/sc19kb/Desktop/Programming_Project/sc19kb/cw1/build/CMakeFiles/book_management.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/book_management.dir/depend

