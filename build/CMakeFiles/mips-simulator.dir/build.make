# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hotine/work/mips-simulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hotine/work/mips-simulator/build

# Include any dependencies generated for this target.
include CMakeFiles/mips-simulator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mips-simulator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mips-simulator.dir/flags.make

CMakeFiles/mips-simulator.dir/src/main.cc.o: CMakeFiles/mips-simulator.dir/flags.make
CMakeFiles/mips-simulator.dir/src/main.cc.o: ../src/main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hotine/work/mips-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mips-simulator.dir/src/main.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mips-simulator.dir/src/main.cc.o -c /home/hotine/work/mips-simulator/src/main.cc

CMakeFiles/mips-simulator.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mips-simulator.dir/src/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hotine/work/mips-simulator/src/main.cc > CMakeFiles/mips-simulator.dir/src/main.cc.i

CMakeFiles/mips-simulator.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mips-simulator.dir/src/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hotine/work/mips-simulator/src/main.cc -o CMakeFiles/mips-simulator.dir/src/main.cc.s

CMakeFiles/mips-simulator.dir/src/scanner.cc.o: CMakeFiles/mips-simulator.dir/flags.make
CMakeFiles/mips-simulator.dir/src/scanner.cc.o: ../src/scanner.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hotine/work/mips-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mips-simulator.dir/src/scanner.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mips-simulator.dir/src/scanner.cc.o -c /home/hotine/work/mips-simulator/src/scanner.cc

CMakeFiles/mips-simulator.dir/src/scanner.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mips-simulator.dir/src/scanner.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hotine/work/mips-simulator/src/scanner.cc > CMakeFiles/mips-simulator.dir/src/scanner.cc.i

CMakeFiles/mips-simulator.dir/src/scanner.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mips-simulator.dir/src/scanner.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hotine/work/mips-simulator/src/scanner.cc -o CMakeFiles/mips-simulator.dir/src/scanner.cc.s

CMakeFiles/mips-simulator.dir/src/dump.cc.o: CMakeFiles/mips-simulator.dir/flags.make
CMakeFiles/mips-simulator.dir/src/dump.cc.o: ../src/dump.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hotine/work/mips-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/mips-simulator.dir/src/dump.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mips-simulator.dir/src/dump.cc.o -c /home/hotine/work/mips-simulator/src/dump.cc

CMakeFiles/mips-simulator.dir/src/dump.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mips-simulator.dir/src/dump.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hotine/work/mips-simulator/src/dump.cc > CMakeFiles/mips-simulator.dir/src/dump.cc.i

CMakeFiles/mips-simulator.dir/src/dump.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mips-simulator.dir/src/dump.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hotine/work/mips-simulator/src/dump.cc -o CMakeFiles/mips-simulator.dir/src/dump.cc.s

CMakeFiles/mips-simulator.dir/src/simulator.cc.o: CMakeFiles/mips-simulator.dir/flags.make
CMakeFiles/mips-simulator.dir/src/simulator.cc.o: ../src/simulator.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hotine/work/mips-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/mips-simulator.dir/src/simulator.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mips-simulator.dir/src/simulator.cc.o -c /home/hotine/work/mips-simulator/src/simulator.cc

CMakeFiles/mips-simulator.dir/src/simulator.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mips-simulator.dir/src/simulator.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hotine/work/mips-simulator/src/simulator.cc > CMakeFiles/mips-simulator.dir/src/simulator.cc.i

CMakeFiles/mips-simulator.dir/src/simulator.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mips-simulator.dir/src/simulator.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hotine/work/mips-simulator/src/simulator.cc -o CMakeFiles/mips-simulator.dir/src/simulator.cc.s

# Object files for target mips-simulator
mips__simulator_OBJECTS = \
"CMakeFiles/mips-simulator.dir/src/main.cc.o" \
"CMakeFiles/mips-simulator.dir/src/scanner.cc.o" \
"CMakeFiles/mips-simulator.dir/src/dump.cc.o" \
"CMakeFiles/mips-simulator.dir/src/simulator.cc.o"

# External object files for target mips-simulator
mips__simulator_EXTERNAL_OBJECTS =

mips-simulator: CMakeFiles/mips-simulator.dir/src/main.cc.o
mips-simulator: CMakeFiles/mips-simulator.dir/src/scanner.cc.o
mips-simulator: CMakeFiles/mips-simulator.dir/src/dump.cc.o
mips-simulator: CMakeFiles/mips-simulator.dir/src/simulator.cc.o
mips-simulator: CMakeFiles/mips-simulator.dir/build.make
mips-simulator: CMakeFiles/mips-simulator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hotine/work/mips-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable mips-simulator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mips-simulator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mips-simulator.dir/build: mips-simulator

.PHONY : CMakeFiles/mips-simulator.dir/build

CMakeFiles/mips-simulator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mips-simulator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mips-simulator.dir/clean

CMakeFiles/mips-simulator.dir/depend:
	cd /home/hotine/work/mips-simulator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hotine/work/mips-simulator /home/hotine/work/mips-simulator /home/hotine/work/mips-simulator/build /home/hotine/work/mips-simulator/build /home/hotine/work/mips-simulator/build/CMakeFiles/mips-simulator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mips-simulator.dir/depend

