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
include examples/CMakeFiles/ex_draw_bitmap.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/ex_draw_bitmap.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/ex_draw_bitmap.dir/flags.make

examples/CMakeFiles/ex_draw_bitmap.dir/ex_draw_bitmap.c.o: examples/CMakeFiles/ex_draw_bitmap.dir/flags.make
examples/CMakeFiles/ex_draw_bitmap.dir/ex_draw_bitmap.c.o: ../examples/ex_draw_bitmap.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object examples/CMakeFiles/ex_draw_bitmap.dir/ex_draw_bitmap.c.o"
	cd /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/build/examples && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/ex_draw_bitmap.dir/ex_draw_bitmap.c.o   -c /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/examples/ex_draw_bitmap.c

examples/CMakeFiles/ex_draw_bitmap.dir/ex_draw_bitmap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ex_draw_bitmap.dir/ex_draw_bitmap.c.i"
	cd /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/build/examples && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/examples/ex_draw_bitmap.c > CMakeFiles/ex_draw_bitmap.dir/ex_draw_bitmap.c.i

examples/CMakeFiles/ex_draw_bitmap.dir/ex_draw_bitmap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ex_draw_bitmap.dir/ex_draw_bitmap.c.s"
	cd /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/build/examples && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/examples/ex_draw_bitmap.c -o CMakeFiles/ex_draw_bitmap.dir/ex_draw_bitmap.c.s

examples/CMakeFiles/ex_draw_bitmap.dir/ex_draw_bitmap.c.o.requires:
.PHONY : examples/CMakeFiles/ex_draw_bitmap.dir/ex_draw_bitmap.c.o.requires

examples/CMakeFiles/ex_draw_bitmap.dir/ex_draw_bitmap.c.o.provides: examples/CMakeFiles/ex_draw_bitmap.dir/ex_draw_bitmap.c.o.requires
	$(MAKE) -f examples/CMakeFiles/ex_draw_bitmap.dir/build.make examples/CMakeFiles/ex_draw_bitmap.dir/ex_draw_bitmap.c.o.provides.build
.PHONY : examples/CMakeFiles/ex_draw_bitmap.dir/ex_draw_bitmap.c.o.provides

examples/CMakeFiles/ex_draw_bitmap.dir/ex_draw_bitmap.c.o.provides.build: examples/CMakeFiles/ex_draw_bitmap.dir/ex_draw_bitmap.c.o

# Object files for target ex_draw_bitmap
ex_draw_bitmap_OBJECTS = \
"CMakeFiles/ex_draw_bitmap.dir/ex_draw_bitmap.c.o"

# External object files for target ex_draw_bitmap
ex_draw_bitmap_EXTERNAL_OBJECTS =

examples/ex_draw_bitmap: examples/CMakeFiles/ex_draw_bitmap.dir/ex_draw_bitmap.c.o
examples/ex_draw_bitmap: examples/CMakeFiles/ex_draw_bitmap.dir/build.make
examples/ex_draw_bitmap: lib/liballegro_image.so.5.0.10
examples/ex_draw_bitmap: lib/liballegro_font.so.5.0.10
examples/ex_draw_bitmap: lib/liballegro.so.5.0.10
examples/ex_draw_bitmap: lib/liballegro_main.so.5.0.10
examples/ex_draw_bitmap: lib/liballegro_dialog.so.5.0.10
examples/ex_draw_bitmap: /usr/lib/x86_64-linux-gnu/libpng.so
examples/ex_draw_bitmap: /usr/lib/x86_64-linux-gnu/libz.so
examples/ex_draw_bitmap: /usr/lib/x86_64-linux-gnu/libjpeg.so
examples/ex_draw_bitmap: lib/liballegro.so.5.0.10
examples/ex_draw_bitmap: /usr/lib/x86_64-linux-gnu/libSM.so
examples/ex_draw_bitmap: /usr/lib/x86_64-linux-gnu/libICE.so
examples/ex_draw_bitmap: /usr/lib/x86_64-linux-gnu/libX11.so
examples/ex_draw_bitmap: /usr/lib/x86_64-linux-gnu/libXext.so
examples/ex_draw_bitmap: /usr/lib/x86_64-linux-gnu/libGL.so
examples/ex_draw_bitmap: /usr/lib/x86_64-linux-gnu/libGLU.so
examples/ex_draw_bitmap: examples/CMakeFiles/ex_draw_bitmap.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable ex_draw_bitmap"
	cd /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ex_draw_bitmap.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/ex_draw_bitmap.dir/build: examples/ex_draw_bitmap
.PHONY : examples/CMakeFiles/ex_draw_bitmap.dir/build

examples/CMakeFiles/ex_draw_bitmap.dir/requires: examples/CMakeFiles/ex_draw_bitmap.dir/ex_draw_bitmap.c.o.requires
.PHONY : examples/CMakeFiles/ex_draw_bitmap.dir/requires

examples/CMakeFiles/ex_draw_bitmap.dir/clean:
	cd /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/ex_draw_bitmap.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/ex_draw_bitmap.dir/clean

examples/CMakeFiles/ex_draw_bitmap.dir/depend:
	cd /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10 /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/examples /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/build /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/build/examples /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/build/examples/CMakeFiles/ex_draw_bitmap.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/ex_draw_bitmap.dir/depend

