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
CMAKE_SOURCE_DIR = /home/marvin/UGR/TFG/PRM_Genetico

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marvin/UGR/TFG/PRM_Genetico/build

# Include any dependencies generated for this target.
include CMakeFiles/test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test.dir/flags.make

CMakeFiles/test.dir/tests/test.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/tests/test.cpp.o: ../tests/test.cpp
CMakeFiles/test.dir/tests/test.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marvin/UGR/TFG/PRM_Genetico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test.dir/tests/test.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/tests/test.cpp.o -MF CMakeFiles/test.dir/tests/test.cpp.o.d -o CMakeFiles/test.dir/tests/test.cpp.o -c /home/marvin/UGR/TFG/PRM_Genetico/tests/test.cpp

CMakeFiles/test.dir/tests/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/tests/test.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/UGR/TFG/PRM_Genetico/tests/test.cpp > CMakeFiles/test.dir/tests/test.cpp.i

CMakeFiles/test.dir/tests/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/tests/test.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/UGR/TFG/PRM_Genetico/tests/test.cpp -o CMakeFiles/test.dir/tests/test.cpp.s

CMakeFiles/test.dir/src/age.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/age.cpp.o: ../src/age.cpp
CMakeFiles/test.dir/src/age.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marvin/UGR/TFG/PRM_Genetico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test.dir/src/age.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/src/age.cpp.o -MF CMakeFiles/test.dir/src/age.cpp.o.d -o CMakeFiles/test.dir/src/age.cpp.o -c /home/marvin/UGR/TFG/PRM_Genetico/src/age.cpp

CMakeFiles/test.dir/src/age.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/age.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/UGR/TFG/PRM_Genetico/src/age.cpp > CMakeFiles/test.dir/src/age.cpp.i

CMakeFiles/test.dir/src/age.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/age.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/UGR/TFG/PRM_Genetico/src/age.cpp -o CMakeFiles/test.dir/src/age.cpp.s

CMakeFiles/test.dir/src/agg.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/agg.cpp.o: ../src/agg.cpp
CMakeFiles/test.dir/src/agg.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marvin/UGR/TFG/PRM_Genetico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test.dir/src/agg.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/src/agg.cpp.o -MF CMakeFiles/test.dir/src/agg.cpp.o.d -o CMakeFiles/test.dir/src/agg.cpp.o -c /home/marvin/UGR/TFG/PRM_Genetico/src/agg.cpp

CMakeFiles/test.dir/src/agg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/agg.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/UGR/TFG/PRM_Genetico/src/agg.cpp > CMakeFiles/test.dir/src/agg.cpp.i

CMakeFiles/test.dir/src/agg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/agg.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/UGR/TFG/PRM_Genetico/src/agg.cpp -o CMakeFiles/test.dir/src/agg.cpp.s

CMakeFiles/test.dir/src/bitmap.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/bitmap.cpp.o: ../src/bitmap.cpp
CMakeFiles/test.dir/src/bitmap.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marvin/UGR/TFG/PRM_Genetico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/test.dir/src/bitmap.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/src/bitmap.cpp.o -MF CMakeFiles/test.dir/src/bitmap.cpp.o.d -o CMakeFiles/test.dir/src/bitmap.cpp.o -c /home/marvin/UGR/TFG/PRM_Genetico/src/bitmap.cpp

CMakeFiles/test.dir/src/bitmap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/bitmap.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/UGR/TFG/PRM_Genetico/src/bitmap.cpp > CMakeFiles/test.dir/src/bitmap.cpp.i

CMakeFiles/test.dir/src/bitmap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/bitmap.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/UGR/TFG/PRM_Genetico/src/bitmap.cpp -o CMakeFiles/test.dir/src/bitmap.cpp.s

CMakeFiles/test.dir/src/chromosome.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/chromosome.cpp.o: ../src/chromosome.cpp
CMakeFiles/test.dir/src/chromosome.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marvin/UGR/TFG/PRM_Genetico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/test.dir/src/chromosome.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/src/chromosome.cpp.o -MF CMakeFiles/test.dir/src/chromosome.cpp.o.d -o CMakeFiles/test.dir/src/chromosome.cpp.o -c /home/marvin/UGR/TFG/PRM_Genetico/src/chromosome.cpp

CMakeFiles/test.dir/src/chromosome.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/chromosome.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/UGR/TFG/PRM_Genetico/src/chromosome.cpp > CMakeFiles/test.dir/src/chromosome.cpp.i

CMakeFiles/test.dir/src/chromosome.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/chromosome.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/UGR/TFG/PRM_Genetico/src/chromosome.cpp -o CMakeFiles/test.dir/src/chromosome.cpp.s

CMakeFiles/test.dir/src/imageES.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/imageES.cpp.o: ../src/imageES.cpp
CMakeFiles/test.dir/src/imageES.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marvin/UGR/TFG/PRM_Genetico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/test.dir/src/imageES.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/src/imageES.cpp.o -MF CMakeFiles/test.dir/src/imageES.cpp.o.d -o CMakeFiles/test.dir/src/imageES.cpp.o -c /home/marvin/UGR/TFG/PRM_Genetico/src/imageES.cpp

CMakeFiles/test.dir/src/imageES.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/imageES.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/UGR/TFG/PRM_Genetico/src/imageES.cpp > CMakeFiles/test.dir/src/imageES.cpp.i

CMakeFiles/test.dir/src/imageES.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/imageES.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/UGR/TFG/PRM_Genetico/src/imageES.cpp -o CMakeFiles/test.dir/src/imageES.cpp.s

CMakeFiles/test.dir/src/point.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/point.cpp.o: ../src/point.cpp
CMakeFiles/test.dir/src/point.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marvin/UGR/TFG/PRM_Genetico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/test.dir/src/point.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/src/point.cpp.o -MF CMakeFiles/test.dir/src/point.cpp.o.d -o CMakeFiles/test.dir/src/point.cpp.o -c /home/marvin/UGR/TFG/PRM_Genetico/src/point.cpp

CMakeFiles/test.dir/src/point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/point.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/UGR/TFG/PRM_Genetico/src/point.cpp > CMakeFiles/test.dir/src/point.cpp.i

CMakeFiles/test.dir/src/point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/point.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/UGR/TFG/PRM_Genetico/src/point.cpp -o CMakeFiles/test.dir/src/point.cpp.s

CMakeFiles/test.dir/src/prm_utilities.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/prm_utilities.cpp.o: ../src/prm_utilities.cpp
CMakeFiles/test.dir/src/prm_utilities.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marvin/UGR/TFG/PRM_Genetico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/test.dir/src/prm_utilities.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/src/prm_utilities.cpp.o -MF CMakeFiles/test.dir/src/prm_utilities.cpp.o.d -o CMakeFiles/test.dir/src/prm_utilities.cpp.o -c /home/marvin/UGR/TFG/PRM_Genetico/src/prm_utilities.cpp

CMakeFiles/test.dir/src/prm_utilities.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/prm_utilities.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/UGR/TFG/PRM_Genetico/src/prm_utilities.cpp > CMakeFiles/test.dir/src/prm_utilities.cpp.i

CMakeFiles/test.dir/src/prm_utilities.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/prm_utilities.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/UGR/TFG/PRM_Genetico/src/prm_utilities.cpp -o CMakeFiles/test.dir/src/prm_utilities.cpp.s

CMakeFiles/test.dir/src/shade.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/shade.cpp.o: ../src/shade.cpp
CMakeFiles/test.dir/src/shade.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marvin/UGR/TFG/PRM_Genetico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/test.dir/src/shade.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/src/shade.cpp.o -MF CMakeFiles/test.dir/src/shade.cpp.o.d -o CMakeFiles/test.dir/src/shade.cpp.o -c /home/marvin/UGR/TFG/PRM_Genetico/src/shade.cpp

CMakeFiles/test.dir/src/shade.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/shade.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marvin/UGR/TFG/PRM_Genetico/src/shade.cpp > CMakeFiles/test.dir/src/shade.cpp.i

CMakeFiles/test.dir/src/shade.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/shade.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marvin/UGR/TFG/PRM_Genetico/src/shade.cpp -o CMakeFiles/test.dir/src/shade.cpp.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/tests/test.cpp.o" \
"CMakeFiles/test.dir/src/age.cpp.o" \
"CMakeFiles/test.dir/src/agg.cpp.o" \
"CMakeFiles/test.dir/src/bitmap.cpp.o" \
"CMakeFiles/test.dir/src/chromosome.cpp.o" \
"CMakeFiles/test.dir/src/imageES.cpp.o" \
"CMakeFiles/test.dir/src/point.cpp.o" \
"CMakeFiles/test.dir/src/prm_utilities.cpp.o" \
"CMakeFiles/test.dir/src/shade.cpp.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

test: CMakeFiles/test.dir/tests/test.cpp.o
test: CMakeFiles/test.dir/src/age.cpp.o
test: CMakeFiles/test.dir/src/agg.cpp.o
test: CMakeFiles/test.dir/src/bitmap.cpp.o
test: CMakeFiles/test.dir/src/chromosome.cpp.o
test: CMakeFiles/test.dir/src/imageES.cpp.o
test: CMakeFiles/test.dir/src/point.cpp.o
test: CMakeFiles/test.dir/src/prm_utilities.cpp.o
test: CMakeFiles/test.dir/src/shade.cpp.o
test: CMakeFiles/test.dir/build.make
test: CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marvin/UGR/TFG/PRM_Genetico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test.dir/build: test
.PHONY : CMakeFiles/test.dir/build

CMakeFiles/test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test.dir/clean

CMakeFiles/test.dir/depend:
	cd /home/marvin/UGR/TFG/PRM_Genetico/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marvin/UGR/TFG/PRM_Genetico /home/marvin/UGR/TFG/PRM_Genetico /home/marvin/UGR/TFG/PRM_Genetico/build /home/marvin/UGR/TFG/PRM_Genetico/build /home/marvin/UGR/TFG/PRM_Genetico/build/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test.dir/depend

