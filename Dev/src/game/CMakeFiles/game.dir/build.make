# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_SOURCE_DIR = /home/kristiandampedersen/Documents/personal/side_projects/KEG

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kristiandampedersen/Documents/personal/side_projects/KEG/Dev

# Include any dependencies generated for this target.
include src/game/CMakeFiles/game.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/game/CMakeFiles/game.dir/compiler_depend.make

# Include the progress variables for this target.
include src/game/CMakeFiles/game.dir/progress.make

# Include the compile flags for this target's objects.
include src/game/CMakeFiles/game.dir/flags.make

src/game/CMakeFiles/game.dir/Game.cpp.o: src/game/CMakeFiles/game.dir/flags.make
src/game/CMakeFiles/game.dir/Game.cpp.o: /home/kristiandampedersen/Documents/personal/side_projects/KEG/src/game/Game.cpp
src/game/CMakeFiles/game.dir/Game.cpp.o: src/game/CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kristiandampedersen/Documents/personal/side_projects/KEG/Dev/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/game/CMakeFiles/game.dir/Game.cpp.o"
	cd /home/kristiandampedersen/Documents/personal/side_projects/KEG/Dev/src/game && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/game/CMakeFiles/game.dir/Game.cpp.o -MF CMakeFiles/game.dir/Game.cpp.o.d -o CMakeFiles/game.dir/Game.cpp.o -c /home/kristiandampedersen/Documents/personal/side_projects/KEG/src/game/Game.cpp

src/game/CMakeFiles/game.dir/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/Game.cpp.i"
	cd /home/kristiandampedersen/Documents/personal/side_projects/KEG/Dev/src/game && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kristiandampedersen/Documents/personal/side_projects/KEG/src/game/Game.cpp > CMakeFiles/game.dir/Game.cpp.i

src/game/CMakeFiles/game.dir/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/Game.cpp.s"
	cd /home/kristiandampedersen/Documents/personal/side_projects/KEG/Dev/src/game && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kristiandampedersen/Documents/personal/side_projects/KEG/src/game/Game.cpp -o CMakeFiles/game.dir/Game.cpp.s

src/game/CMakeFiles/game.dir/TextureManager.cpp.o: src/game/CMakeFiles/game.dir/flags.make
src/game/CMakeFiles/game.dir/TextureManager.cpp.o: /home/kristiandampedersen/Documents/personal/side_projects/KEG/src/game/TextureManager.cpp
src/game/CMakeFiles/game.dir/TextureManager.cpp.o: src/game/CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kristiandampedersen/Documents/personal/side_projects/KEG/Dev/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/game/CMakeFiles/game.dir/TextureManager.cpp.o"
	cd /home/kristiandampedersen/Documents/personal/side_projects/KEG/Dev/src/game && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/game/CMakeFiles/game.dir/TextureManager.cpp.o -MF CMakeFiles/game.dir/TextureManager.cpp.o.d -o CMakeFiles/game.dir/TextureManager.cpp.o -c /home/kristiandampedersen/Documents/personal/side_projects/KEG/src/game/TextureManager.cpp

src/game/CMakeFiles/game.dir/TextureManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/TextureManager.cpp.i"
	cd /home/kristiandampedersen/Documents/personal/side_projects/KEG/Dev/src/game && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kristiandampedersen/Documents/personal/side_projects/KEG/src/game/TextureManager.cpp > CMakeFiles/game.dir/TextureManager.cpp.i

src/game/CMakeFiles/game.dir/TextureManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/TextureManager.cpp.s"
	cd /home/kristiandampedersen/Documents/personal/side_projects/KEG/Dev/src/game && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kristiandampedersen/Documents/personal/side_projects/KEG/src/game/TextureManager.cpp -o CMakeFiles/game.dir/TextureManager.cpp.s

src/game/CMakeFiles/game.dir/Map.cpp.o: src/game/CMakeFiles/game.dir/flags.make
src/game/CMakeFiles/game.dir/Map.cpp.o: /home/kristiandampedersen/Documents/personal/side_projects/KEG/src/game/Map.cpp
src/game/CMakeFiles/game.dir/Map.cpp.o: src/game/CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kristiandampedersen/Documents/personal/side_projects/KEG/Dev/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/game/CMakeFiles/game.dir/Map.cpp.o"
	cd /home/kristiandampedersen/Documents/personal/side_projects/KEG/Dev/src/game && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/game/CMakeFiles/game.dir/Map.cpp.o -MF CMakeFiles/game.dir/Map.cpp.o.d -o CMakeFiles/game.dir/Map.cpp.o -c /home/kristiandampedersen/Documents/personal/side_projects/KEG/src/game/Map.cpp

src/game/CMakeFiles/game.dir/Map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/Map.cpp.i"
	cd /home/kristiandampedersen/Documents/personal/side_projects/KEG/Dev/src/game && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kristiandampedersen/Documents/personal/side_projects/KEG/src/game/Map.cpp > CMakeFiles/game.dir/Map.cpp.i

src/game/CMakeFiles/game.dir/Map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/Map.cpp.s"
	cd /home/kristiandampedersen/Documents/personal/side_projects/KEG/Dev/src/game && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kristiandampedersen/Documents/personal/side_projects/KEG/src/game/Map.cpp -o CMakeFiles/game.dir/Map.cpp.s

# Object files for target game
game_OBJECTS = \
"CMakeFiles/game.dir/Game.cpp.o" \
"CMakeFiles/game.dir/TextureManager.cpp.o" \
"CMakeFiles/game.dir/Map.cpp.o"

# External object files for target game
game_EXTERNAL_OBJECTS =

src/game/libgame.so: src/game/CMakeFiles/game.dir/Game.cpp.o
src/game/libgame.so: src/game/CMakeFiles/game.dir/TextureManager.cpp.o
src/game/libgame.so: src/game/CMakeFiles/game.dir/Map.cpp.o
src/game/libgame.so: src/game/CMakeFiles/game.dir/build.make
src/game/libgame.so: src/game/ECS/libecs.so
src/game/libgame.so: external/SDL_image/libSDL3_image.so.0.0.0
src/game/libgame.so: external/SDL/libSDL3.so.0.0.0
src/game/libgame.so: /home/kristiandampedersen/Documents/personal/side_projects/KEG/external/SDL/src/dynapi/SDL_dynapi.sym
src/game/libgame.so: src/game/CMakeFiles/game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kristiandampedersen/Documents/personal/side_projects/KEG/Dev/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX shared library libgame.so"
	cd /home/kristiandampedersen/Documents/personal/side_projects/KEG/Dev/src/game && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/game/CMakeFiles/game.dir/build: src/game/libgame.so
.PHONY : src/game/CMakeFiles/game.dir/build

src/game/CMakeFiles/game.dir/clean:
	cd /home/kristiandampedersen/Documents/personal/side_projects/KEG/Dev/src/game && $(CMAKE_COMMAND) -P CMakeFiles/game.dir/cmake_clean.cmake
.PHONY : src/game/CMakeFiles/game.dir/clean

src/game/CMakeFiles/game.dir/depend:
	cd /home/kristiandampedersen/Documents/personal/side_projects/KEG/Dev && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kristiandampedersen/Documents/personal/side_projects/KEG /home/kristiandampedersen/Documents/personal/side_projects/KEG/src/game /home/kristiandampedersen/Documents/personal/side_projects/KEG/Dev /home/kristiandampedersen/Documents/personal/side_projects/KEG/Dev/src/game /home/kristiandampedersen/Documents/personal/side_projects/KEG/Dev/src/game/CMakeFiles/game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/game/CMakeFiles/game.dir/depend
