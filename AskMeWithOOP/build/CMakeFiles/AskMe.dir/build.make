# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\iti\C++\Mastring c++ udemy\Projects\AskMeWithOOP project"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\iti\C++\Mastring c++ udemy\Projects\AskMeWithOOP project\build"

# Include any dependencies generated for this target.
include CMakeFiles/AskMe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/AskMe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/AskMe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AskMe.dir/flags.make

CMakeFiles/AskMe.dir/HelperFunctions.obj: CMakeFiles/AskMe.dir/flags.make
CMakeFiles/AskMe.dir/HelperFunctions.obj: D:/iti/C++/Mastring\ c++\ udemy/Projects/AskMeWithOOP\ project/HelperFunctions.cpp
CMakeFiles/AskMe.dir/HelperFunctions.obj: CMakeFiles/AskMe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\iti\C++\Mastring c++ udemy\Projects\AskMeWithOOP project\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AskMe.dir/HelperFunctions.obj"
	C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AskMe.dir/HelperFunctions.obj -MF CMakeFiles\AskMe.dir\HelperFunctions.obj.d -o CMakeFiles\AskMe.dir\HelperFunctions.obj -c "D:\iti\C++\Mastring c++ udemy\Projects\AskMeWithOOP project\HelperFunctions.cpp"

CMakeFiles/AskMe.dir/HelperFunctions.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/AskMe.dir/HelperFunctions.i"
	C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\iti\C++\Mastring c++ udemy\Projects\AskMeWithOOP project\HelperFunctions.cpp" > CMakeFiles\AskMe.dir\HelperFunctions.i

CMakeFiles/AskMe.dir/HelperFunctions.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/AskMe.dir/HelperFunctions.s"
	C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\iti\C++\Mastring c++ udemy\Projects\AskMeWithOOP project\HelperFunctions.cpp" -o CMakeFiles\AskMe.dir\HelperFunctions.s

CMakeFiles/AskMe.dir/main.obj: CMakeFiles/AskMe.dir/flags.make
CMakeFiles/AskMe.dir/main.obj: D:/iti/C++/Mastring\ c++\ udemy/Projects/AskMeWithOOP\ project/main.cpp
CMakeFiles/AskMe.dir/main.obj: CMakeFiles/AskMe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\iti\C++\Mastring c++ udemy\Projects\AskMeWithOOP project\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/AskMe.dir/main.obj"
	C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AskMe.dir/main.obj -MF CMakeFiles\AskMe.dir\main.obj.d -o CMakeFiles\AskMe.dir\main.obj -c "D:\iti\C++\Mastring c++ udemy\Projects\AskMeWithOOP project\main.cpp"

CMakeFiles/AskMe.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/AskMe.dir/main.i"
	C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\iti\C++\Mastring c++ udemy\Projects\AskMeWithOOP project\main.cpp" > CMakeFiles\AskMe.dir\main.i

CMakeFiles/AskMe.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/AskMe.dir/main.s"
	C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\iti\C++\Mastring c++ udemy\Projects\AskMeWithOOP project\main.cpp" -o CMakeFiles\AskMe.dir\main.s

CMakeFiles/AskMe.dir/System.obj: CMakeFiles/AskMe.dir/flags.make
CMakeFiles/AskMe.dir/System.obj: D:/iti/C++/Mastring\ c++\ udemy/Projects/AskMeWithOOP\ project/System.cpp
CMakeFiles/AskMe.dir/System.obj: CMakeFiles/AskMe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\iti\C++\Mastring c++ udemy\Projects\AskMeWithOOP project\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/AskMe.dir/System.obj"
	C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AskMe.dir/System.obj -MF CMakeFiles\AskMe.dir\System.obj.d -o CMakeFiles\AskMe.dir\System.obj -c "D:\iti\C++\Mastring c++ udemy\Projects\AskMeWithOOP project\System.cpp"

CMakeFiles/AskMe.dir/System.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/AskMe.dir/System.i"
	C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\iti\C++\Mastring c++ udemy\Projects\AskMeWithOOP project\System.cpp" > CMakeFiles\AskMe.dir\System.i

CMakeFiles/AskMe.dir/System.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/AskMe.dir/System.s"
	C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\iti\C++\Mastring c++ udemy\Projects\AskMeWithOOP project\System.cpp" -o CMakeFiles\AskMe.dir\System.s

CMakeFiles/AskMe.dir/User.obj: CMakeFiles/AskMe.dir/flags.make
CMakeFiles/AskMe.dir/User.obj: D:/iti/C++/Mastring\ c++\ udemy/Projects/AskMeWithOOP\ project/User.cpp
CMakeFiles/AskMe.dir/User.obj: CMakeFiles/AskMe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\iti\C++\Mastring c++ udemy\Projects\AskMeWithOOP project\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/AskMe.dir/User.obj"
	C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AskMe.dir/User.obj -MF CMakeFiles\AskMe.dir\User.obj.d -o CMakeFiles\AskMe.dir\User.obj -c "D:\iti\C++\Mastring c++ udemy\Projects\AskMeWithOOP project\User.cpp"

CMakeFiles/AskMe.dir/User.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/AskMe.dir/User.i"
	C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\iti\C++\Mastring c++ udemy\Projects\AskMeWithOOP project\User.cpp" > CMakeFiles\AskMe.dir\User.i

CMakeFiles/AskMe.dir/User.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/AskMe.dir/User.s"
	C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\iti\C++\Mastring c++ udemy\Projects\AskMeWithOOP project\User.cpp" -o CMakeFiles\AskMe.dir\User.s

CMakeFiles/AskMe.dir/Question.obj: CMakeFiles/AskMe.dir/flags.make
CMakeFiles/AskMe.dir/Question.obj: D:/iti/C++/Mastring\ c++\ udemy/Projects/AskMeWithOOP\ project/Question.cpp
CMakeFiles/AskMe.dir/Question.obj: CMakeFiles/AskMe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\iti\C++\Mastring c++ udemy\Projects\AskMeWithOOP project\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/AskMe.dir/Question.obj"
	C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AskMe.dir/Question.obj -MF CMakeFiles\AskMe.dir\Question.obj.d -o CMakeFiles\AskMe.dir\Question.obj -c "D:\iti\C++\Mastring c++ udemy\Projects\AskMeWithOOP project\Question.cpp"

CMakeFiles/AskMe.dir/Question.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/AskMe.dir/Question.i"
	C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\iti\C++\Mastring c++ udemy\Projects\AskMeWithOOP project\Question.cpp" > CMakeFiles\AskMe.dir\Question.i

CMakeFiles/AskMe.dir/Question.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/AskMe.dir/Question.s"
	C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\iti\C++\Mastring c++ udemy\Projects\AskMeWithOOP project\Question.cpp" -o CMakeFiles\AskMe.dir\Question.s

# Object files for target AskMe
AskMe_OBJECTS = \
"CMakeFiles/AskMe.dir/HelperFunctions.obj" \
"CMakeFiles/AskMe.dir/main.obj" \
"CMakeFiles/AskMe.dir/System.obj" \
"CMakeFiles/AskMe.dir/User.obj" \
"CMakeFiles/AskMe.dir/Question.obj"

# External object files for target AskMe
AskMe_EXTERNAL_OBJECTS =

AskMe.exe: CMakeFiles/AskMe.dir/HelperFunctions.obj
AskMe.exe: CMakeFiles/AskMe.dir/main.obj
AskMe.exe: CMakeFiles/AskMe.dir/System.obj
AskMe.exe: CMakeFiles/AskMe.dir/User.obj
AskMe.exe: CMakeFiles/AskMe.dir/Question.obj
AskMe.exe: CMakeFiles/AskMe.dir/build.make
AskMe.exe: CMakeFiles/AskMe.dir/linkLibs.rsp
AskMe.exe: CMakeFiles/AskMe.dir/objects1.rsp
AskMe.exe: CMakeFiles/AskMe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="D:\iti\C++\Mastring c++ udemy\Projects\AskMeWithOOP project\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable AskMe.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\AskMe.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AskMe.dir/build: AskMe.exe
.PHONY : CMakeFiles/AskMe.dir/build

CMakeFiles/AskMe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\AskMe.dir\cmake_clean.cmake
.PHONY : CMakeFiles/AskMe.dir/clean

CMakeFiles/AskMe.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\iti\C++\Mastring c++ udemy\Projects\AskMeWithOOP project" "D:\iti\C++\Mastring c++ udemy\Projects\AskMeWithOOP project" "D:\iti\C++\Mastring c++ udemy\Projects\AskMeWithOOP project\build" "D:\iti\C++\Mastring c++ udemy\Projects\AskMeWithOOP project\build" "D:\iti\C++\Mastring c++ udemy\Projects\AskMeWithOOP project\build\CMakeFiles\AskMe.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/AskMe.dir/depend

