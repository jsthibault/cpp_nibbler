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

# Utility rule file for run_tests_d3d.

# Include the progress variables for this target.
include tests/CMakeFiles/run_tests_d3d.dir/progress.make

tests/CMakeFiles/run_tests_d3d: tests/test_driver
	cd /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/build/tests && ./test_driver --force-d3d /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/tests/test_bitmaps.ini /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/tests/test_bitmaps2.ini /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/tests/test_blend.ini /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/tests/test_locking.ini /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/tests/test_locking2.ini /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/tests/test_backbuffer.ini /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/tests/test_image.ini /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/tests/test_fonts.ini /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/tests/test_prim.ini

run_tests_d3d: tests/CMakeFiles/run_tests_d3d
run_tests_d3d: tests/CMakeFiles/run_tests_d3d.dir/build.make
.PHONY : run_tests_d3d

# Rule to build all files generated by this target.
tests/CMakeFiles/run_tests_d3d.dir/build: run_tests_d3d
.PHONY : tests/CMakeFiles/run_tests_d3d.dir/build

tests/CMakeFiles/run_tests_d3d.dir/clean:
	cd /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/run_tests_d3d.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/run_tests_d3d.dir/clean

tests/CMakeFiles/run_tests_d3d.dir/depend:
	cd /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10 /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/tests /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/build /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/build/tests /home/loic/dev/epitech/cpp/Nibbler/allegro/allegro-5.0.10/build/tests/CMakeFiles/run_tests_d3d.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/run_tests_d3d.dir/depend

