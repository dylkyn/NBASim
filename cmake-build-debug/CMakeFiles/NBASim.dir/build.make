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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/cjburgett/Documents/ECE_4122/Final_project_real

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/cjburgett/Documents/ECE_4122/Final_project_real/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/NBASim.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/NBASim.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/NBASim.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NBASim.dir/flags.make

CMakeFiles/NBASim.dir/main.cpp.o: CMakeFiles/NBASim.dir/flags.make
CMakeFiles/NBASim.dir/main.cpp.o: ../main.cpp
CMakeFiles/NBASim.dir/main.cpp.o: CMakeFiles/NBASim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cjburgett/Documents/ECE_4122/Final_project_real/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/NBASim.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/NBASim.dir/main.cpp.o -MF CMakeFiles/NBASim.dir/main.cpp.o.d -o CMakeFiles/NBASim.dir/main.cpp.o -c /Users/cjburgett/Documents/ECE_4122/Final_project_real/main.cpp

CMakeFiles/NBASim.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NBASim.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cjburgett/Documents/ECE_4122/Final_project_real/main.cpp > CMakeFiles/NBASim.dir/main.cpp.i

CMakeFiles/NBASim.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NBASim.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cjburgett/Documents/ECE_4122/Final_project_real/main.cpp -o CMakeFiles/NBASim.dir/main.cpp.s

# Object files for target NBASim
NBASim_OBJECTS = \
"CMakeFiles/NBASim.dir/main.cpp.o"

# External object files for target NBASim
NBASim_EXTERNAL_OBJECTS =

NBASim: CMakeFiles/NBASim.dir/main.cpp.o
NBASim: CMakeFiles/NBASim.dir/build.make
NBASim: libmy-lib.a
NBASim: /usr/local/lib/libsfml-graphics.2.5.1.dylib
NBASim: /usr/local/lib/libsfml-audio.2.5.1.dylib
NBASim: /usr/local/lib/libsfml-window.2.5.1.dylib
NBASim: /usr/local/lib/libsfml-system.2.5.1.dylib
NBASim: CMakeFiles/NBASim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/cjburgett/Documents/ECE_4122/Final_project_real/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable NBASim"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NBASim.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NBASim.dir/build: NBASim
.PHONY : CMakeFiles/NBASim.dir/build

CMakeFiles/NBASim.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NBASim.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NBASim.dir/clean

CMakeFiles/NBASim.dir/depend:
	cd /Users/cjburgett/Documents/ECE_4122/Final_project_real/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/cjburgett/Documents/ECE_4122/Final_project_real /Users/cjburgett/Documents/ECE_4122/Final_project_real /Users/cjburgett/Documents/ECE_4122/Final_project_real/cmake-build-debug /Users/cjburgett/Documents/ECE_4122/Final_project_real/cmake-build-debug /Users/cjburgett/Documents/ECE_4122/Final_project_real/cmake-build-debug/CMakeFiles/NBASim.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NBASim.dir/depend

