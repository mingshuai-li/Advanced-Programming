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
CMAKE_SOURCE_DIR = /home/lims/ap/project_sprint3/21ws-ap-group-cs-project/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lims/ap/project_sprint3/21ws-ap-group-cs-project/build_src

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/main.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/main.cpp.o: /home/lims/ap/project_sprint3/21ws-ap-group-cs-project/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lims/ap/project_sprint3/21ws-ap-group-cs-project/build_src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/main.cpp.o -c /home/lims/ap/project_sprint3/21ws-ap-group-cs-project/src/main.cpp

CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lims/ap/project_sprint3/21ws-ap-group-cs-project/src/main.cpp > CMakeFiles/main.dir/main.cpp.i

CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lims/ap/project_sprint3/21ws-ap-group-cs-project/src/main.cpp -o CMakeFiles/main.dir/main.cpp.s

CMakeFiles/main.dir/image.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/image.cpp.o: /home/lims/ap/project_sprint3/21ws-ap-group-cs-project/src/image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lims/ap/project_sprint3/21ws-ap-group-cs-project/build_src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/image.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/image.cpp.o -c /home/lims/ap/project_sprint3/21ws-ap-group-cs-project/src/image.cpp

CMakeFiles/main.dir/image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/image.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lims/ap/project_sprint3/21ws-ap-group-cs-project/src/image.cpp > CMakeFiles/main.dir/image.cpp.i

CMakeFiles/main.dir/image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/image.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lims/ap/project_sprint3/21ws-ap-group-cs-project/src/image.cpp -o CMakeFiles/main.dir/image.cpp.s

CMakeFiles/main.dir/image_processing_system.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/image_processing_system.cpp.o: /home/lims/ap/project_sprint3/21ws-ap-group-cs-project/src/image_processing_system.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lims/ap/project_sprint3/21ws-ap-group-cs-project/build_src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/image_processing_system.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/image_processing_system.cpp.o -c /home/lims/ap/project_sprint3/21ws-ap-group-cs-project/src/image_processing_system.cpp

CMakeFiles/main.dir/image_processing_system.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/image_processing_system.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lims/ap/project_sprint3/21ws-ap-group-cs-project/src/image_processing_system.cpp > CMakeFiles/main.dir/image_processing_system.cpp.i

CMakeFiles/main.dir/image_processing_system.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/image_processing_system.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lims/ap/project_sprint3/21ws-ap-group-cs-project/src/image_processing_system.cpp -o CMakeFiles/main.dir/image_processing_system.cpp.s

CMakeFiles/main.dir/menu.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/menu.cpp.o: /home/lims/ap/project_sprint3/21ws-ap-group-cs-project/src/menu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lims/ap/project_sprint3/21ws-ap-group-cs-project/build_src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/menu.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/menu.cpp.o -c /home/lims/ap/project_sprint3/21ws-ap-group-cs-project/src/menu.cpp

CMakeFiles/main.dir/menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/menu.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lims/ap/project_sprint3/21ws-ap-group-cs-project/src/menu.cpp > CMakeFiles/main.dir/menu.cpp.i

CMakeFiles/main.dir/menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/menu.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lims/ap/project_sprint3/21ws-ap-group-cs-project/src/menu.cpp -o CMakeFiles/main.dir/menu.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cpp.o" \
"CMakeFiles/main.dir/image.cpp.o" \
"CMakeFiles/main.dir/image_processing_system.cpp.o" \
"CMakeFiles/main.dir/menu.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/main.cpp.o
main: CMakeFiles/main.dir/image.cpp.o
main: CMakeFiles/main.dir/image_processing_system.cpp.o
main: CMakeFiles/main.dir/menu.cpp.o
main: CMakeFiles/main.dir/build.make
main: /usr/local/lib/libopencv_dnn.so.3.4.5
main: /usr/local/lib/libopencv_ml.so.3.4.5
main: /usr/local/lib/libopencv_objdetect.so.3.4.5
main: /usr/local/lib/libopencv_shape.so.3.4.5
main: /usr/local/lib/libopencv_stitching.so.3.4.5
main: /usr/local/lib/libopencv_superres.so.3.4.5
main: /usr/local/lib/libopencv_videostab.so.3.4.5
main: /usr/local/lib/libopencv_calib3d.so.3.4.5
main: /usr/local/lib/libopencv_features2d.so.3.4.5
main: /usr/local/lib/libopencv_flann.so.3.4.5
main: /usr/local/lib/libopencv_highgui.so.3.4.5
main: /usr/local/lib/libopencv_photo.so.3.4.5
main: /usr/local/lib/libopencv_video.so.3.4.5
main: /usr/local/lib/libopencv_videoio.so.3.4.5
main: /usr/local/lib/libopencv_imgcodecs.so.3.4.5
main: /usr/local/lib/libopencv_imgproc.so.3.4.5
main: /usr/local/lib/libopencv_core.so.3.4.5
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lims/ap/project_sprint3/21ws-ap-group-cs-project/build_src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main

.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /home/lims/ap/project_sprint3/21ws-ap-group-cs-project/build_src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lims/ap/project_sprint3/21ws-ap-group-cs-project/src /home/lims/ap/project_sprint3/21ws-ap-group-cs-project/src /home/lims/ap/project_sprint3/21ws-ap-group-cs-project/build_src /home/lims/ap/project_sprint3/21ws-ap-group-cs-project/build_src /home/lims/ap/project_sprint3/21ws-ap-group-cs-project/build_src/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

