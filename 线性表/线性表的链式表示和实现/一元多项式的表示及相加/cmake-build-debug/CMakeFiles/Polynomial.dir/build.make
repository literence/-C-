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
CMAKE_COMMAND = /home/li/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/201.6668.126/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/li/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/201.6668.126/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/li/CLionProjects/数据结构(C语言版)/线性表/线性表的链式表示和实现/一元多项式的表示及相加"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/li/CLionProjects/数据结构(C语言版)/线性表/线性表的链式表示和实现/一元多项式的表示及相加/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Polynomial.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Polynomial.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Polynomial.dir/flags.make

CMakeFiles/Polynomial.dir/Polynomial.c.o: CMakeFiles/Polynomial.dir/flags.make
CMakeFiles/Polynomial.dir/Polynomial.c.o: ../Polynomial.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/li/CLionProjects/数据结构(C语言版)/线性表/线性表的链式表示和实现/一元多项式的表示及相加/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Polynomial.dir/Polynomial.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Polynomial.dir/Polynomial.c.o   -c "/home/li/CLionProjects/数据结构(C语言版)/线性表/线性表的链式表示和实现/一元多项式的表示及相加/Polynomial.c"

CMakeFiles/Polynomial.dir/Polynomial.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Polynomial.dir/Polynomial.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/li/CLionProjects/数据结构(C语言版)/线性表/线性表的链式表示和实现/一元多项式的表示及相加/Polynomial.c" > CMakeFiles/Polynomial.dir/Polynomial.c.i

CMakeFiles/Polynomial.dir/Polynomial.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Polynomial.dir/Polynomial.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/li/CLionProjects/数据结构(C语言版)/线性表/线性表的链式表示和实现/一元多项式的表示及相加/Polynomial.c" -o CMakeFiles/Polynomial.dir/Polynomial.c.s

# Object files for target Polynomial
Polynomial_OBJECTS = \
"CMakeFiles/Polynomial.dir/Polynomial.c.o"

# External object files for target Polynomial
Polynomial_EXTERNAL_OBJECTS =

Polynomial: CMakeFiles/Polynomial.dir/Polynomial.c.o
Polynomial: CMakeFiles/Polynomial.dir/build.make
Polynomial: CMakeFiles/Polynomial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/li/CLionProjects/数据结构(C语言版)/线性表/线性表的链式表示和实现/一元多项式的表示及相加/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Polynomial"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Polynomial.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Polynomial.dir/build: Polynomial

.PHONY : CMakeFiles/Polynomial.dir/build

CMakeFiles/Polynomial.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Polynomial.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Polynomial.dir/clean

CMakeFiles/Polynomial.dir/depend:
	cd "/home/li/CLionProjects/数据结构(C语言版)/线性表/线性表的链式表示和实现/一元多项式的表示及相加/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/li/CLionProjects/数据结构(C语言版)/线性表/线性表的链式表示和实现/一元多项式的表示及相加" "/home/li/CLionProjects/数据结构(C语言版)/线性表/线性表的链式表示和实现/一元多项式的表示及相加" "/home/li/CLionProjects/数据结构(C语言版)/线性表/线性表的链式表示和实现/一元多项式的表示及相加/cmake-build-debug" "/home/li/CLionProjects/数据结构(C语言版)/线性表/线性表的链式表示和实现/一元多项式的表示及相加/cmake-build-debug" "/home/li/CLionProjects/数据结构(C语言版)/线性表/线性表的链式表示和实现/一元多项式的表示及相加/cmake-build-debug/CMakeFiles/Polynomial.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Polynomial.dir/depend

