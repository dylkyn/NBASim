# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\kynoc\OneDrive\Documents\GT\Classes\ECE 4122\Project\NBASim"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\kynoc\OneDrive\Documents\GT\Classes\ECE 4122\Project\NBASim\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/NBASim.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/NBASim.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NBASim.dir/flags.make

CMakeFiles/NBASim.dir/main.cpp.obj: CMakeFiles/NBASim.dir/flags.make
CMakeFiles/NBASim.dir/main.cpp.obj: CMakeFiles/NBASim.dir/includes_CXX.rsp
CMakeFiles/NBASim.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\kynoc\OneDrive\Documents\GT\Classes\ECE 4122\Project\NBASim\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/NBASim.dir/main.cpp.obj"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\NBASim.dir\main.cpp.obj -c "C:\Users\kynoc\OneDrive\Documents\GT\Classes\ECE 4122\Project\NBASim\main.cpp"

CMakeFiles/NBASim.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NBASim.dir/main.cpp.i"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\kynoc\OneDrive\Documents\GT\Classes\ECE 4122\Project\NBASim\main.cpp" > CMakeFiles\NBASim.dir\main.cpp.i

CMakeFiles/NBASim.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NBASim.dir/main.cpp.s"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\kynoc\OneDrive\Documents\GT\Classes\ECE 4122\Project\NBASim\main.cpp" -o CMakeFiles\NBASim.dir\main.cpp.s

# Object files for target NBASim
NBASim_OBJECTS = \
"CMakeFiles/NBASim.dir/main.cpp.obj"

# External object files for target NBASim
NBASim_EXTERNAL_OBJECTS =

CMAKE_CURRENT_SOURCE_DIR/NBASim.exe: CMakeFiles/NBASim.dir/main.cpp.obj
CMAKE_CURRENT_SOURCE_DIR/NBASim.exe: CMakeFiles/NBASim.dir/build.make
CMAKE_CURRENT_SOURCE_DIR/NBASim.exe: ../SFML/lib/libsfml-graphics-d.a
CMAKE_CURRENT_SOURCE_DIR/NBASim.exe: ../SFML/lib/libsfml-audio-d.a
CMAKE_CURRENT_SOURCE_DIR/NBASim.exe: ../SFML/lib/libsfml-window-d.a
CMAKE_CURRENT_SOURCE_DIR/NBASim.exe: ../SFML/lib/libsfml-system-d.a
CMAKE_CURRENT_SOURCE_DIR/NBASim.exe: CMakeFiles/NBASim.dir/linklibs.rsp
CMAKE_CURRENT_SOURCE_DIR/NBASim.exe: CMakeFiles/NBASim.dir/objects1.rsp
CMAKE_CURRENT_SOURCE_DIR/NBASim.exe: CMakeFiles/NBASim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\kynoc\OneDrive\Documents\GT\Classes\ECE 4122\Project\NBASim\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CMAKE_CURRENT_SOURCE_DIR\NBASim.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\NBASim.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NBASim.dir/build: CMAKE_CURRENT_SOURCE_DIR/NBASim.exe
.PHONY : CMakeFiles/NBASim.dir/build

CMakeFiles/NBASim.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\NBASim.dir\cmake_clean.cmake
.PHONY : CMakeFiles/NBASim.dir/clean

CMakeFiles/NBASim.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\kynoc\OneDrive\Documents\GT\Classes\ECE 4122\Project\NBASim" "C:\Users\kynoc\OneDrive\Documents\GT\Classes\ECE 4122\Project\NBASim" "C:\Users\kynoc\OneDrive\Documents\GT\Classes\ECE 4122\Project\NBASim\cmake-build-debug" "C:\Users\kynoc\OneDrive\Documents\GT\Classes\ECE 4122\Project\NBASim\cmake-build-debug" "C:\Users\kynoc\OneDrive\Documents\GT\Classes\ECE 4122\Project\NBASim\cmake-build-debug\CMakeFiles\NBASim.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/NBASim.dir/depend

