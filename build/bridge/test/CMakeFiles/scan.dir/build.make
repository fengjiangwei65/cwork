# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/andrew/Document/Project/网关/git/cwork

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andrew/Document/Project/网关/git/cwork/build

# Include any dependencies generated for this target.
include bridge/test/CMakeFiles/scan.dir/depend.make

# Include the progress variables for this target.
include bridge/test/CMakeFiles/scan.dir/progress.make

# Include the compile flags for this target's objects.
include bridge/test/CMakeFiles/scan.dir/flags.make

bridge/test/CMakeFiles/scan.dir/scan.c.o: bridge/test/CMakeFiles/scan.dir/flags.make
bridge/test/CMakeFiles/scan.dir/scan.c.o: ../bridge/test/scan.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrew/Document/Project/网关/git/cwork/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object bridge/test/CMakeFiles/scan.dir/scan.c.o"
	cd /home/andrew/Document/Project/网关/git/cwork/build/bridge/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/scan.dir/scan.c.o   -c /home/andrew/Document/Project/网关/git/cwork/bridge/test/scan.c

bridge/test/CMakeFiles/scan.dir/scan.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/scan.dir/scan.c.i"
	cd /home/andrew/Document/Project/网关/git/cwork/build/bridge/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/andrew/Document/Project/网关/git/cwork/bridge/test/scan.c > CMakeFiles/scan.dir/scan.c.i

bridge/test/CMakeFiles/scan.dir/scan.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/scan.dir/scan.c.s"
	cd /home/andrew/Document/Project/网关/git/cwork/build/bridge/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/andrew/Document/Project/网关/git/cwork/bridge/test/scan.c -o CMakeFiles/scan.dir/scan.c.s

# Object files for target scan
scan_OBJECTS = \
"CMakeFiles/scan.dir/scan.c.o"

# External object files for target scan
scan_EXTERNAL_OBJECTS =

bridge/test/scan: bridge/test/CMakeFiles/scan.dir/scan.c.o
bridge/test/scan: bridge/test/CMakeFiles/scan.dir/build.make
bridge/test/scan: bridge/ble/libble.a
bridge/test/scan: bridge/mqtt/libmqtt.a
bridge/test/scan: bridge/proto/libign_proto.a
bridge/test/scan: bridge/bridge_main/libign_lib.a
bridge/test/scan: bridge/wifi/libign_wifi.a
bridge/test/scan: bridge/lock/liblock.a
bridge/test/scan: bridge/gattlib/dbus/libgattlib.so
bridge/test/scan: bridge/test/CMakeFiles/scan.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/andrew/Document/Project/网关/git/cwork/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable scan"
	cd /home/andrew/Document/Project/网关/git/cwork/build/bridge/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/scan.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bridge/test/CMakeFiles/scan.dir/build: bridge/test/scan

.PHONY : bridge/test/CMakeFiles/scan.dir/build

bridge/test/CMakeFiles/scan.dir/clean:
	cd /home/andrew/Document/Project/网关/git/cwork/build/bridge/test && $(CMAKE_COMMAND) -P CMakeFiles/scan.dir/cmake_clean.cmake
.PHONY : bridge/test/CMakeFiles/scan.dir/clean

bridge/test/CMakeFiles/scan.dir/depend:
	cd /home/andrew/Document/Project/网关/git/cwork/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andrew/Document/Project/网关/git/cwork /home/andrew/Document/Project/网关/git/cwork/bridge/test /home/andrew/Document/Project/网关/git/cwork/build /home/andrew/Document/Project/网关/git/cwork/build/bridge/test /home/andrew/Document/Project/网关/git/cwork/build/bridge/test/CMakeFiles/scan.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bridge/test/CMakeFiles/scan.dir/depend

