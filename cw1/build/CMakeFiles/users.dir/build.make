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
include CMakeFiles/users.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/users.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/users.dir/flags.make

CMakeFiles/users.dir/book_management.c.o: CMakeFiles/users.dir/flags.make
CMakeFiles/users.dir/book_management.c.o: ../book_management.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/csunix/sc19kb/Desktop/Programming_Project/sc19kb/cw1/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/users.dir/book_management.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/users.dir/book_management.c.o   -c /home/csunix/sc19kb/Desktop/Programming_Project/sc19kb/cw1/book_management.c

CMakeFiles/users.dir/book_management.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/users.dir/book_management.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/csunix/sc19kb/Desktop/Programming_Project/sc19kb/cw1/book_management.c > CMakeFiles/users.dir/book_management.c.i

CMakeFiles/users.dir/book_management.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/users.dir/book_management.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/csunix/sc19kb/Desktop/Programming_Project/sc19kb/cw1/book_management.c -o CMakeFiles/users.dir/book_management.c.s

CMakeFiles/users.dir/book_management.c.o.requires:
.PHONY : CMakeFiles/users.dir/book_management.c.o.requires

CMakeFiles/users.dir/book_management.c.o.provides: CMakeFiles/users.dir/book_management.c.o.requires
	$(MAKE) -f CMakeFiles/users.dir/build.make CMakeFiles/users.dir/book_management.c.o.provides.build
.PHONY : CMakeFiles/users.dir/book_management.c.o.provides

CMakeFiles/users.dir/book_management.c.o.provides.build: CMakeFiles/users.dir/book_management.c.o

CMakeFiles/users.dir/users.c.o: CMakeFiles/users.dir/flags.make
CMakeFiles/users.dir/users.c.o: ../users.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/csunix/sc19kb/Desktop/Programming_Project/sc19kb/cw1/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/users.dir/users.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/users.dir/users.c.o   -c /home/csunix/sc19kb/Desktop/Programming_Project/sc19kb/cw1/users.c

CMakeFiles/users.dir/users.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/users.dir/users.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/csunix/sc19kb/Desktop/Programming_Project/sc19kb/cw1/users.c > CMakeFiles/users.dir/users.c.i

CMakeFiles/users.dir/users.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/users.dir/users.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/csunix/sc19kb/Desktop/Programming_Project/sc19kb/cw1/users.c -o CMakeFiles/users.dir/users.c.s

CMakeFiles/users.dir/users.c.o.requires:
.PHONY : CMakeFiles/users.dir/users.c.o.requires

CMakeFiles/users.dir/users.c.o.provides: CMakeFiles/users.dir/users.c.o.requires
	$(MAKE) -f CMakeFiles/users.dir/build.make CMakeFiles/users.dir/users.c.o.provides.build
.PHONY : CMakeFiles/users.dir/users.c.o.provides

CMakeFiles/users.dir/users.c.o.provides.build: CMakeFiles/users.dir/users.c.o

# Object files for target users
users_OBJECTS = \
"CMakeFiles/users.dir/book_management.c.o" \
"CMakeFiles/users.dir/users.c.o"

# External object files for target users
users_EXTERNAL_OBJECTS =

users: CMakeFiles/users.dir/book_management.c.o
users: CMakeFiles/users.dir/users.c.o
users: CMakeFiles/users.dir/build.make
users: CMakeFiles/users.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable users"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/users.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/users.dir/build: users
.PHONY : CMakeFiles/users.dir/build

CMakeFiles/users.dir/requires: CMakeFiles/users.dir/book_management.c.o.requires
CMakeFiles/users.dir/requires: CMakeFiles/users.dir/users.c.o.requires
.PHONY : CMakeFiles/users.dir/requires

CMakeFiles/users.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/users.dir/cmake_clean.cmake
.PHONY : CMakeFiles/users.dir/clean

CMakeFiles/users.dir/depend:
	cd /home/csunix/sc19kb/Desktop/Programming_Project/sc19kb/cw1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/csunix/sc19kb/Desktop/Programming_Project/sc19kb/cw1 /home/csunix/sc19kb/Desktop/Programming_Project/sc19kb/cw1 /home/csunix/sc19kb/Desktop/Programming_Project/sc19kb/cw1/build /home/csunix/sc19kb/Desktop/Programming_Project/sc19kb/cw1/build /home/csunix/sc19kb/Desktop/Programming_Project/sc19kb/cw1/build/CMakeFiles/users.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/users.dir/depend
