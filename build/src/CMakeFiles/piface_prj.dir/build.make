# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_SOURCE_DIR = /home/frank/hpbProject/RaspberryPi/rpi_prj/rpi_piface

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/frank/hpbProject/RaspberryPi/rpi_prj/rpi_piface/build

# Include any dependencies generated for this target.
include src/CMakeFiles/piface_prj.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/piface_prj.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/piface_prj.dir/flags.make

src/CMakeFiles/piface_prj.dir/blink.c.o: src/CMakeFiles/piface_prj.dir/flags.make
src/CMakeFiles/piface_prj.dir/blink.c.o: ../src/blink.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/frank/hpbProject/RaspberryPi/rpi_prj/rpi_piface/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/CMakeFiles/piface_prj.dir/blink.c.o"
	cd /home/frank/hpbProject/RaspberryPi/rpi_prj/rpi_piface/build/src && /home/frank/hpbProject/pi_cross/tools-master/arm-bcm2708/arm-bcm2708hardfp-linux-gnueabi/bin/arm-bcm2708hardfp-linux-gnueabi-gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/piface_prj.dir/blink.c.o   -c /home/frank/hpbProject/RaspberryPi/rpi_prj/rpi_piface/src/blink.c

src/CMakeFiles/piface_prj.dir/blink.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/piface_prj.dir/blink.c.i"
	cd /home/frank/hpbProject/RaspberryPi/rpi_prj/rpi_piface/build/src && /home/frank/hpbProject/pi_cross/tools-master/arm-bcm2708/arm-bcm2708hardfp-linux-gnueabi/bin/arm-bcm2708hardfp-linux-gnueabi-gcc  $(C_DEFINES) $(C_FLAGS) -E /home/frank/hpbProject/RaspberryPi/rpi_prj/rpi_piface/src/blink.c > CMakeFiles/piface_prj.dir/blink.c.i

src/CMakeFiles/piface_prj.dir/blink.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/piface_prj.dir/blink.c.s"
	cd /home/frank/hpbProject/RaspberryPi/rpi_prj/rpi_piface/build/src && /home/frank/hpbProject/pi_cross/tools-master/arm-bcm2708/arm-bcm2708hardfp-linux-gnueabi/bin/arm-bcm2708hardfp-linux-gnueabi-gcc  $(C_DEFINES) $(C_FLAGS) -S /home/frank/hpbProject/RaspberryPi/rpi_prj/rpi_piface/src/blink.c -o CMakeFiles/piface_prj.dir/blink.c.s

src/CMakeFiles/piface_prj.dir/blink.c.o.requires:
.PHONY : src/CMakeFiles/piface_prj.dir/blink.c.o.requires

src/CMakeFiles/piface_prj.dir/blink.c.o.provides: src/CMakeFiles/piface_prj.dir/blink.c.o.requires
	$(MAKE) -f src/CMakeFiles/piface_prj.dir/build.make src/CMakeFiles/piface_prj.dir/blink.c.o.provides.build
.PHONY : src/CMakeFiles/piface_prj.dir/blink.c.o.provides

src/CMakeFiles/piface_prj.dir/blink.c.o.provides.build: src/CMakeFiles/piface_prj.dir/blink.c.o

src/CMakeFiles/piface_prj.dir/button.c.o: src/CMakeFiles/piface_prj.dir/flags.make
src/CMakeFiles/piface_prj.dir/button.c.o: ../src/button.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/frank/hpbProject/RaspberryPi/rpi_prj/rpi_piface/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/CMakeFiles/piface_prj.dir/button.c.o"
	cd /home/frank/hpbProject/RaspberryPi/rpi_prj/rpi_piface/build/src && /home/frank/hpbProject/pi_cross/tools-master/arm-bcm2708/arm-bcm2708hardfp-linux-gnueabi/bin/arm-bcm2708hardfp-linux-gnueabi-gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/piface_prj.dir/button.c.o   -c /home/frank/hpbProject/RaspberryPi/rpi_prj/rpi_piface/src/button.c

src/CMakeFiles/piface_prj.dir/button.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/piface_prj.dir/button.c.i"
	cd /home/frank/hpbProject/RaspberryPi/rpi_prj/rpi_piface/build/src && /home/frank/hpbProject/pi_cross/tools-master/arm-bcm2708/arm-bcm2708hardfp-linux-gnueabi/bin/arm-bcm2708hardfp-linux-gnueabi-gcc  $(C_DEFINES) $(C_FLAGS) -E /home/frank/hpbProject/RaspberryPi/rpi_prj/rpi_piface/src/button.c > CMakeFiles/piface_prj.dir/button.c.i

src/CMakeFiles/piface_prj.dir/button.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/piface_prj.dir/button.c.s"
	cd /home/frank/hpbProject/RaspberryPi/rpi_prj/rpi_piface/build/src && /home/frank/hpbProject/pi_cross/tools-master/arm-bcm2708/arm-bcm2708hardfp-linux-gnueabi/bin/arm-bcm2708hardfp-linux-gnueabi-gcc  $(C_DEFINES) $(C_FLAGS) -S /home/frank/hpbProject/RaspberryPi/rpi_prj/rpi_piface/src/button.c -o CMakeFiles/piface_prj.dir/button.c.s

src/CMakeFiles/piface_prj.dir/button.c.o.requires:
.PHONY : src/CMakeFiles/piface_prj.dir/button.c.o.requires

src/CMakeFiles/piface_prj.dir/button.c.o.provides: src/CMakeFiles/piface_prj.dir/button.c.o.requires
	$(MAKE) -f src/CMakeFiles/piface_prj.dir/build.make src/CMakeFiles/piface_prj.dir/button.c.o.provides.build
.PHONY : src/CMakeFiles/piface_prj.dir/button.c.o.provides

src/CMakeFiles/piface_prj.dir/button.c.o.provides.build: src/CMakeFiles/piface_prj.dir/button.c.o

src/CMakeFiles/piface_prj.dir/fr_softServo.c.o: src/CMakeFiles/piface_prj.dir/flags.make
src/CMakeFiles/piface_prj.dir/fr_softServo.c.o: ../src/fr_softServo.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/frank/hpbProject/RaspberryPi/rpi_prj/rpi_piface/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/CMakeFiles/piface_prj.dir/fr_softServo.c.o"
	cd /home/frank/hpbProject/RaspberryPi/rpi_prj/rpi_piface/build/src && /home/frank/hpbProject/pi_cross/tools-master/arm-bcm2708/arm-bcm2708hardfp-linux-gnueabi/bin/arm-bcm2708hardfp-linux-gnueabi-gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/piface_prj.dir/fr_softServo.c.o   -c /home/frank/hpbProject/RaspberryPi/rpi_prj/rpi_piface/src/fr_softServo.c

src/CMakeFiles/piface_prj.dir/fr_softServo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/piface_prj.dir/fr_softServo.c.i"
	cd /home/frank/hpbProject/RaspberryPi/rpi_prj/rpi_piface/build/src && /home/frank/hpbProject/pi_cross/tools-master/arm-bcm2708/arm-bcm2708hardfp-linux-gnueabi/bin/arm-bcm2708hardfp-linux-gnueabi-gcc  $(C_DEFINES) $(C_FLAGS) -E /home/frank/hpbProject/RaspberryPi/rpi_prj/rpi_piface/src/fr_softServo.c > CMakeFiles/piface_prj.dir/fr_softServo.c.i

src/CMakeFiles/piface_prj.dir/fr_softServo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/piface_prj.dir/fr_softServo.c.s"
	cd /home/frank/hpbProject/RaspberryPi/rpi_prj/rpi_piface/build/src && /home/frank/hpbProject/pi_cross/tools-master/arm-bcm2708/arm-bcm2708hardfp-linux-gnueabi/bin/arm-bcm2708hardfp-linux-gnueabi-gcc  $(C_DEFINES) $(C_FLAGS) -S /home/frank/hpbProject/RaspberryPi/rpi_prj/rpi_piface/src/fr_softServo.c -o CMakeFiles/piface_prj.dir/fr_softServo.c.s

src/CMakeFiles/piface_prj.dir/fr_softServo.c.o.requires:
.PHONY : src/CMakeFiles/piface_prj.dir/fr_softServo.c.o.requires

src/CMakeFiles/piface_prj.dir/fr_softServo.c.o.provides: src/CMakeFiles/piface_prj.dir/fr_softServo.c.o.requires
	$(MAKE) -f src/CMakeFiles/piface_prj.dir/build.make src/CMakeFiles/piface_prj.dir/fr_softServo.c.o.provides.build
.PHONY : src/CMakeFiles/piface_prj.dir/fr_softServo.c.o.provides

src/CMakeFiles/piface_prj.dir/fr_softServo.c.o.provides.build: src/CMakeFiles/piface_prj.dir/fr_softServo.c.o

# Object files for target piface_prj
piface_prj_OBJECTS = \
"CMakeFiles/piface_prj.dir/blink.c.o" \
"CMakeFiles/piface_prj.dir/button.c.o" \
"CMakeFiles/piface_prj.dir/fr_softServo.c.o"

# External object files for target piface_prj
piface_prj_EXTERNAL_OBJECTS =

src/piface_prj: src/CMakeFiles/piface_prj.dir/blink.c.o
src/piface_prj: src/CMakeFiles/piface_prj.dir/button.c.o
src/piface_prj: src/CMakeFiles/piface_prj.dir/fr_softServo.c.o
src/piface_prj: src/CMakeFiles/piface_prj.dir/build.make
src/piface_prj: src/wiringPi_lib/libpiface_lib.a
src/piface_prj: src/CMakeFiles/piface_prj.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable piface_prj"
	cd /home/frank/hpbProject/RaspberryPi/rpi_prj/rpi_piface/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/piface_prj.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/piface_prj.dir/build: src/piface_prj
.PHONY : src/CMakeFiles/piface_prj.dir/build

src/CMakeFiles/piface_prj.dir/requires: src/CMakeFiles/piface_prj.dir/blink.c.o.requires
src/CMakeFiles/piface_prj.dir/requires: src/CMakeFiles/piface_prj.dir/button.c.o.requires
src/CMakeFiles/piface_prj.dir/requires: src/CMakeFiles/piface_prj.dir/fr_softServo.c.o.requires
.PHONY : src/CMakeFiles/piface_prj.dir/requires

src/CMakeFiles/piface_prj.dir/clean:
	cd /home/frank/hpbProject/RaspberryPi/rpi_prj/rpi_piface/build/src && $(CMAKE_COMMAND) -P CMakeFiles/piface_prj.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/piface_prj.dir/clean

src/CMakeFiles/piface_prj.dir/depend:
	cd /home/frank/hpbProject/RaspberryPi/rpi_prj/rpi_piface/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/frank/hpbProject/RaspberryPi/rpi_prj/rpi_piface /home/frank/hpbProject/RaspberryPi/rpi_prj/rpi_piface/src /home/frank/hpbProject/RaspberryPi/rpi_prj/rpi_piface/build /home/frank/hpbProject/RaspberryPi/rpi_prj/rpi_piface/build/src /home/frank/hpbProject/RaspberryPi/rpi_prj/rpi_piface/build/src/CMakeFiles/piface_prj.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/piface_prj.dir/depend
