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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/build

# Include any dependencies generated for this target.
include addons/ttf/CMakeFiles/allegro_ttf.dir/depend.make

# Include the progress variables for this target.
include addons/ttf/CMakeFiles/allegro_ttf.dir/progress.make

# Include the compile flags for this target's objects.
include addons/ttf/CMakeFiles/allegro_ttf.dir/flags.make

lib/Headers/allegro5/allegro_ttf.h: ../addons/ttf/allegro5/allegro_ttf.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Copying OS X content lib/Headers/allegro5/allegro_ttf.h"
	$(CMAKE_COMMAND) -E copy /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/addons/ttf/allegro5/allegro_ttf.h lib/Headers/allegro5/allegro_ttf.h

addons/ttf/CMakeFiles/allegro_ttf.dir/ttf.c.o: addons/ttf/CMakeFiles/allegro_ttf.dir/flags.make
addons/ttf/CMakeFiles/allegro_ttf.dir/ttf.c.o: ../addons/ttf/ttf.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object addons/ttf/CMakeFiles/allegro_ttf.dir/ttf.c.o"
	cd /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/build/addons/ttf && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -DALLEGRO_TTF_SRC  -DALLEGRO_LIB_BUILD -o CMakeFiles/allegro_ttf.dir/ttf.c.o   -c /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/addons/ttf/ttf.c

addons/ttf/CMakeFiles/allegro_ttf.dir/ttf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/allegro_ttf.dir/ttf.c.i"
	cd /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/build/addons/ttf && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -DALLEGRO_TTF_SRC  -DALLEGRO_LIB_BUILD -E /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/addons/ttf/ttf.c > CMakeFiles/allegro_ttf.dir/ttf.c.i

addons/ttf/CMakeFiles/allegro_ttf.dir/ttf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/allegro_ttf.dir/ttf.c.s"
	cd /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/build/addons/ttf && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -DALLEGRO_TTF_SRC  -DALLEGRO_LIB_BUILD -S /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/addons/ttf/ttf.c -o CMakeFiles/allegro_ttf.dir/ttf.c.s

addons/ttf/CMakeFiles/allegro_ttf.dir/ttf.c.o.requires:
.PHONY : addons/ttf/CMakeFiles/allegro_ttf.dir/ttf.c.o.requires

addons/ttf/CMakeFiles/allegro_ttf.dir/ttf.c.o.provides: addons/ttf/CMakeFiles/allegro_ttf.dir/ttf.c.o.requires
	$(MAKE) -f addons/ttf/CMakeFiles/allegro_ttf.dir/build.make addons/ttf/CMakeFiles/allegro_ttf.dir/ttf.c.o.provides.build
.PHONY : addons/ttf/CMakeFiles/allegro_ttf.dir/ttf.c.o.provides

addons/ttf/CMakeFiles/allegro_ttf.dir/ttf.c.o.provides.build: addons/ttf/CMakeFiles/allegro_ttf.dir/ttf.c.o

# Object files for target allegro_ttf
allegro_ttf_OBJECTS = \
"CMakeFiles/allegro_ttf.dir/ttf.c.o"

# External object files for target allegro_ttf
allegro_ttf_EXTERNAL_OBJECTS =

lib/liballegro_ttf.so.5.0.10: addons/ttf/CMakeFiles/allegro_ttf.dir/ttf.c.o
lib/liballegro_ttf.so.5.0.10: addons/ttf/CMakeFiles/allegro_ttf.dir/build.make
lib/liballegro_ttf.so.5.0.10: lib/liballegro_font.so.5.0.10
lib/liballegro_ttf.so.5.0.10: /usr/lib/x86_64-linux-gnu/libfreetype.so
lib/liballegro_ttf.so.5.0.10: /usr/lib/x86_64-linux-gnu/libz.so
lib/liballegro_ttf.so.5.0.10: lib/liballegro.so.5.0.10
lib/liballegro_ttf.so.5.0.10: /usr/lib/x86_64-linux-gnu/libSM.so
lib/liballegro_ttf.so.5.0.10: /usr/lib/x86_64-linux-gnu/libICE.so
lib/liballegro_ttf.so.5.0.10: /usr/lib/x86_64-linux-gnu/libX11.so
lib/liballegro_ttf.so.5.0.10: /usr/lib/x86_64-linux-gnu/libXext.so
lib/liballegro_ttf.so.5.0.10: /usr/lib/x86_64-linux-gnu/libGL.so
lib/liballegro_ttf.so.5.0.10: /usr/lib/x86_64-linux-gnu/libGLU.so
lib/liballegro_ttf.so.5.0.10: addons/ttf/CMakeFiles/allegro_ttf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C shared library ../../lib/liballegro_ttf.so"
	cd /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/build/addons/ttf && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/allegro_ttf.dir/link.txt --verbose=$(VERBOSE)
	cd /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/build/addons/ttf && $(CMAKE_COMMAND) -E cmake_symlink_library ../../lib/liballegro_ttf.so.5.0.10 ../../lib/liballegro_ttf.so.5.0 ../../lib/liballegro_ttf.so

lib/liballegro_ttf.so.5.0: lib/liballegro_ttf.so.5.0.10

lib/liballegro_ttf.so: lib/liballegro_ttf.so.5.0.10

# Rule to build all files generated by this target.
addons/ttf/CMakeFiles/allegro_ttf.dir/build: lib/liballegro_ttf.so
addons/ttf/CMakeFiles/allegro_ttf.dir/build: lib/Headers/allegro5/allegro_ttf.h
.PHONY : addons/ttf/CMakeFiles/allegro_ttf.dir/build

addons/ttf/CMakeFiles/allegro_ttf.dir/requires: addons/ttf/CMakeFiles/allegro_ttf.dir/ttf.c.o.requires
.PHONY : addons/ttf/CMakeFiles/allegro_ttf.dir/requires

addons/ttf/CMakeFiles/allegro_ttf.dir/clean:
	cd /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/build/addons/ttf && $(CMAKE_COMMAND) -P CMakeFiles/allegro_ttf.dir/cmake_clean.cmake
.PHONY : addons/ttf/CMakeFiles/allegro_ttf.dir/clean

addons/ttf/CMakeFiles/allegro_ttf.dir/depend:
	cd /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10 /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/addons/ttf /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/build /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/build/addons/ttf /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/build/addons/ttf/CMakeFiles/allegro_ttf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : addons/ttf/CMakeFiles/allegro_ttf.dir/depend

