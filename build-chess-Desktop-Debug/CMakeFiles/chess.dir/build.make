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
CMAKE_SOURCE_DIR = /home/formation/Bureau/xjr/chess

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/formation/Bureau/xjr/chess/build-chess-Desktop-Debug

# Include any dependencies generated for this target.
include CMakeFiles/chess.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/chess.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/chess.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chess.dir/flags.make

CMakeFiles/chess.dir/main.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/main.cpp.o: ../main.cpp
CMakeFiles/chess.dir/main.cpp.o: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/formation/Bureau/xjr/chess/build-chess-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/chess.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/main.cpp.o -MF CMakeFiles/chess.dir/main.cpp.o.d -o CMakeFiles/chess.dir/main.cpp.o -c /home/formation/Bureau/xjr/chess/main.cpp

CMakeFiles/chess.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/formation/Bureau/xjr/chess/main.cpp > CMakeFiles/chess.dir/main.cpp.i

CMakeFiles/chess.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/formation/Bureau/xjr/chess/main.cpp -o CMakeFiles/chess.dir/main.cpp.s

CMakeFiles/chess.dir/chessboard.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/chessboard.cpp.o: ../chessboard.cpp
CMakeFiles/chess.dir/chessboard.cpp.o: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/formation/Bureau/xjr/chess/build-chess-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/chess.dir/chessboard.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/chessboard.cpp.o -MF CMakeFiles/chess.dir/chessboard.cpp.o.d -o CMakeFiles/chess.dir/chessboard.cpp.o -c /home/formation/Bureau/xjr/chess/chessboard.cpp

CMakeFiles/chess.dir/chessboard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/chessboard.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/formation/Bureau/xjr/chess/chessboard.cpp > CMakeFiles/chess.dir/chessboard.cpp.i

CMakeFiles/chess.dir/chessboard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/chessboard.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/formation/Bureau/xjr/chess/chessboard.cpp -o CMakeFiles/chess.dir/chessboard.cpp.s

CMakeFiles/chess.dir/piece.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/piece.cpp.o: ../piece.cpp
CMakeFiles/chess.dir/piece.cpp.o: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/formation/Bureau/xjr/chess/build-chess-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/chess.dir/piece.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/piece.cpp.o -MF CMakeFiles/chess.dir/piece.cpp.o.d -o CMakeFiles/chess.dir/piece.cpp.o -c /home/formation/Bureau/xjr/chess/piece.cpp

CMakeFiles/chess.dir/piece.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/piece.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/formation/Bureau/xjr/chess/piece.cpp > CMakeFiles/chess.dir/piece.cpp.i

CMakeFiles/chess.dir/piece.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/piece.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/formation/Bureau/xjr/chess/piece.cpp -o CMakeFiles/chess.dir/piece.cpp.s

CMakeFiles/chess.dir/pawn.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/pawn.cpp.o: ../pawn.cpp
CMakeFiles/chess.dir/pawn.cpp.o: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/formation/Bureau/xjr/chess/build-chess-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/chess.dir/pawn.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/pawn.cpp.o -MF CMakeFiles/chess.dir/pawn.cpp.o.d -o CMakeFiles/chess.dir/pawn.cpp.o -c /home/formation/Bureau/xjr/chess/pawn.cpp

CMakeFiles/chess.dir/pawn.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/pawn.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/formation/Bureau/xjr/chess/pawn.cpp > CMakeFiles/chess.dir/pawn.cpp.i

CMakeFiles/chess.dir/pawn.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/pawn.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/formation/Bureau/xjr/chess/pawn.cpp -o CMakeFiles/chess.dir/pawn.cpp.s

CMakeFiles/chess.dir/rook.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/rook.cpp.o: ../rook.cpp
CMakeFiles/chess.dir/rook.cpp.o: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/formation/Bureau/xjr/chess/build-chess-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/chess.dir/rook.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/rook.cpp.o -MF CMakeFiles/chess.dir/rook.cpp.o.d -o CMakeFiles/chess.dir/rook.cpp.o -c /home/formation/Bureau/xjr/chess/rook.cpp

CMakeFiles/chess.dir/rook.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/rook.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/formation/Bureau/xjr/chess/rook.cpp > CMakeFiles/chess.dir/rook.cpp.i

CMakeFiles/chess.dir/rook.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/rook.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/formation/Bureau/xjr/chess/rook.cpp -o CMakeFiles/chess.dir/rook.cpp.s

CMakeFiles/chess.dir/bishop.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/bishop.cpp.o: ../bishop.cpp
CMakeFiles/chess.dir/bishop.cpp.o: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/formation/Bureau/xjr/chess/build-chess-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/chess.dir/bishop.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/bishop.cpp.o -MF CMakeFiles/chess.dir/bishop.cpp.o.d -o CMakeFiles/chess.dir/bishop.cpp.o -c /home/formation/Bureau/xjr/chess/bishop.cpp

CMakeFiles/chess.dir/bishop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/bishop.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/formation/Bureau/xjr/chess/bishop.cpp > CMakeFiles/chess.dir/bishop.cpp.i

CMakeFiles/chess.dir/bishop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/bishop.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/formation/Bureau/xjr/chess/bishop.cpp -o CMakeFiles/chess.dir/bishop.cpp.s

CMakeFiles/chess.dir/knight.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/knight.cpp.o: ../knight.cpp
CMakeFiles/chess.dir/knight.cpp.o: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/formation/Bureau/xjr/chess/build-chess-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/chess.dir/knight.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/knight.cpp.o -MF CMakeFiles/chess.dir/knight.cpp.o.d -o CMakeFiles/chess.dir/knight.cpp.o -c /home/formation/Bureau/xjr/chess/knight.cpp

CMakeFiles/chess.dir/knight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/knight.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/formation/Bureau/xjr/chess/knight.cpp > CMakeFiles/chess.dir/knight.cpp.i

CMakeFiles/chess.dir/knight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/knight.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/formation/Bureau/xjr/chess/knight.cpp -o CMakeFiles/chess.dir/knight.cpp.s

CMakeFiles/chess.dir/king.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/king.cpp.o: ../king.cpp
CMakeFiles/chess.dir/king.cpp.o: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/formation/Bureau/xjr/chess/build-chess-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/chess.dir/king.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/king.cpp.o -MF CMakeFiles/chess.dir/king.cpp.o.d -o CMakeFiles/chess.dir/king.cpp.o -c /home/formation/Bureau/xjr/chess/king.cpp

CMakeFiles/chess.dir/king.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/king.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/formation/Bureau/xjr/chess/king.cpp > CMakeFiles/chess.dir/king.cpp.i

CMakeFiles/chess.dir/king.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/king.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/formation/Bureau/xjr/chess/king.cpp -o CMakeFiles/chess.dir/king.cpp.s

CMakeFiles/chess.dir/queen.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/queen.cpp.o: ../queen.cpp
CMakeFiles/chess.dir/queen.cpp.o: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/formation/Bureau/xjr/chess/build-chess-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/chess.dir/queen.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/queen.cpp.o -MF CMakeFiles/chess.dir/queen.cpp.o.d -o CMakeFiles/chess.dir/queen.cpp.o -c /home/formation/Bureau/xjr/chess/queen.cpp

CMakeFiles/chess.dir/queen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/queen.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/formation/Bureau/xjr/chess/queen.cpp > CMakeFiles/chess.dir/queen.cpp.i

CMakeFiles/chess.dir/queen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/queen.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/formation/Bureau/xjr/chess/queen.cpp -o CMakeFiles/chess.dir/queen.cpp.s

# Object files for target chess
chess_OBJECTS = \
"CMakeFiles/chess.dir/main.cpp.o" \
"CMakeFiles/chess.dir/chessboard.cpp.o" \
"CMakeFiles/chess.dir/piece.cpp.o" \
"CMakeFiles/chess.dir/pawn.cpp.o" \
"CMakeFiles/chess.dir/rook.cpp.o" \
"CMakeFiles/chess.dir/bishop.cpp.o" \
"CMakeFiles/chess.dir/knight.cpp.o" \
"CMakeFiles/chess.dir/king.cpp.o" \
"CMakeFiles/chess.dir/queen.cpp.o"

# External object files for target chess
chess_EXTERNAL_OBJECTS =

chess: CMakeFiles/chess.dir/main.cpp.o
chess: CMakeFiles/chess.dir/chessboard.cpp.o
chess: CMakeFiles/chess.dir/piece.cpp.o
chess: CMakeFiles/chess.dir/pawn.cpp.o
chess: CMakeFiles/chess.dir/rook.cpp.o
chess: CMakeFiles/chess.dir/bishop.cpp.o
chess: CMakeFiles/chess.dir/knight.cpp.o
chess: CMakeFiles/chess.dir/king.cpp.o
chess: CMakeFiles/chess.dir/queen.cpp.o
chess: CMakeFiles/chess.dir/build.make
chess: /usr/lib/x86_64-linux-gnu/libGLU.so
chess: /usr/lib/x86_64-linux-gnu/libglut.so
chess: /usr/lib/x86_64-linux-gnu/libGLX.so
chess: /usr/lib/x86_64-linux-gnu/libOpenGL.so
chess: /usr/lib/x86_64-linux-gnu/libXi.so
chess: CMakeFiles/chess.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/formation/Bureau/xjr/chess/build-chess-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable chess"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chess.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chess.dir/build: chess
.PHONY : CMakeFiles/chess.dir/build

CMakeFiles/chess.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/chess.dir/cmake_clean.cmake
.PHONY : CMakeFiles/chess.dir/clean

CMakeFiles/chess.dir/depend:
	cd /home/formation/Bureau/xjr/chess/build-chess-Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/formation/Bureau/xjr/chess /home/formation/Bureau/xjr/chess /home/formation/Bureau/xjr/chess/build-chess-Desktop-Debug /home/formation/Bureau/xjr/chess/build-chess-Desktop-Debug /home/formation/Bureau/xjr/chess/build-chess-Desktop-Debug/CMakeFiles/chess.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/chess.dir/depend
