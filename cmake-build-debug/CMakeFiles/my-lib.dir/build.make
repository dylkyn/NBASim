# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\justi\CLionProjects\NBASim

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\justi\CLionProjects\NBASim\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/my-lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/my-lib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/my-lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my-lib.dir/flags.make

CMakeFiles/my-lib.dir/Player.cpp.obj: CMakeFiles/my-lib.dir/flags.make
CMakeFiles/my-lib.dir/Player.cpp.obj: CMakeFiles/my-lib.dir/includes_CXX.rsp
CMakeFiles/my-lib.dir/Player.cpp.obj: ../Player.cpp
CMakeFiles/my-lib.dir/Player.cpp.obj: CMakeFiles/my-lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\justi\CLionProjects\NBASim\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/my-lib.dir/Player.cpp.obj"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/my-lib.dir/Player.cpp.obj -MF CMakeFiles\my-lib.dir\Player.cpp.obj.d -o CMakeFiles\my-lib.dir\Player.cpp.obj -c C:\Users\justi\CLionProjects\NBASim\Player.cpp

CMakeFiles/my-lib.dir/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my-lib.dir/Player.cpp.i"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\justi\CLionProjects\NBASim\Player.cpp > CMakeFiles\my-lib.dir\Player.cpp.i

CMakeFiles/my-lib.dir/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my-lib.dir/Player.cpp.s"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\justi\CLionProjects\NBASim\Player.cpp -o CMakeFiles\my-lib.dir\Player.cpp.s

CMakeFiles/my-lib.dir/Team.cpp.obj: CMakeFiles/my-lib.dir/flags.make
CMakeFiles/my-lib.dir/Team.cpp.obj: CMakeFiles/my-lib.dir/includes_CXX.rsp
CMakeFiles/my-lib.dir/Team.cpp.obj: ../Team.cpp
CMakeFiles/my-lib.dir/Team.cpp.obj: CMakeFiles/my-lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\justi\CLionProjects\NBASim\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/my-lib.dir/Team.cpp.obj"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/my-lib.dir/Team.cpp.obj -MF CMakeFiles\my-lib.dir\Team.cpp.obj.d -o CMakeFiles\my-lib.dir\Team.cpp.obj -c C:\Users\justi\CLionProjects\NBASim\Team.cpp

CMakeFiles/my-lib.dir/Team.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my-lib.dir/Team.cpp.i"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\justi\CLionProjects\NBASim\Team.cpp > CMakeFiles\my-lib.dir\Team.cpp.i

CMakeFiles/my-lib.dir/Team.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my-lib.dir/Team.cpp.s"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\justi\CLionProjects\NBASim\Team.cpp -o CMakeFiles\my-lib.dir\Team.cpp.s

CMakeFiles/my-lib.dir/Game.cpp.obj: CMakeFiles/my-lib.dir/flags.make
CMakeFiles/my-lib.dir/Game.cpp.obj: CMakeFiles/my-lib.dir/includes_CXX.rsp
CMakeFiles/my-lib.dir/Game.cpp.obj: ../Game.cpp
CMakeFiles/my-lib.dir/Game.cpp.obj: CMakeFiles/my-lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\justi\CLionProjects\NBASim\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/my-lib.dir/Game.cpp.obj"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/my-lib.dir/Game.cpp.obj -MF CMakeFiles\my-lib.dir\Game.cpp.obj.d -o CMakeFiles\my-lib.dir\Game.cpp.obj -c C:\Users\justi\CLionProjects\NBASim\Game.cpp

CMakeFiles/my-lib.dir/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my-lib.dir/Game.cpp.i"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\justi\CLionProjects\NBASim\Game.cpp > CMakeFiles\my-lib.dir\Game.cpp.i

CMakeFiles/my-lib.dir/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my-lib.dir/Game.cpp.s"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\justi\CLionProjects\NBASim\Game.cpp -o CMakeFiles\my-lib.dir\Game.cpp.s

# Object files for target my-lib
my__lib_OBJECTS = \
"CMakeFiles/my-lib.dir/Player.cpp.obj" \
"CMakeFiles/my-lib.dir/Team.cpp.obj" \
"CMakeFiles/my-lib.dir/Game.cpp.obj"

# External object files for target my-lib
my__lib_EXTERNAL_OBJECTS =

libmy-lib.a: CMakeFiles/my-lib.dir/Player.cpp.obj
libmy-lib.a: CMakeFiles/my-lib.dir/Team.cpp.obj
libmy-lib.a: CMakeFiles/my-lib.dir/Game.cpp.obj
libmy-lib.a: CMakeFiles/my-lib.dir/build.make
libmy-lib.a: CMakeFiles/my-lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\justi\CLionProjects\NBASim\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libmy-lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles\my-lib.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\my-lib.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my-lib.dir/build: libmy-lib.a
.PHONY : CMakeFiles/my-lib.dir/build

CMakeFiles/my-lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\my-lib.dir\cmake_clean.cmake
.PHONY : CMakeFiles/my-lib.dir/clean

CMakeFiles/my-lib.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\justi\CLionProjects\NBASim C:\Users\justi\CLionProjects\NBASim C:\Users\justi\CLionProjects\NBASim\cmake-build-debug C:\Users\justi\CLionProjects\NBASim\cmake-build-debug C:\Users\justi\CLionProjects\NBASim\cmake-build-debug\CMakeFiles\my-lib.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my-lib.dir/depend

