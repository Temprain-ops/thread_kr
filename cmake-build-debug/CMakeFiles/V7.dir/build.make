# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\Donsg\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\203.7717.62\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Donsg\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\203.7717.62\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Donsg\Documents\GitHub\thread_kr

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Donsg\Documents\GitHub\thread_kr\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\V7.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\V7.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\V7.dir\flags.make

CMakeFiles\V7.dir\V7.cpp.obj: CMakeFiles\V7.dir\flags.make
CMakeFiles\V7.dir\V7.cpp.obj: ..\V7.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Donsg\Documents\GitHub\thread_kr\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/V7.dir/V7.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\V7.dir\V7.cpp.obj /FdCMakeFiles\V7.dir\ /FS -c C:\Users\Donsg\Documents\GitHub\thread_kr\V7.cpp
<<

CMakeFiles\V7.dir\V7.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/V7.dir/V7.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\V7.dir\V7.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Donsg\Documents\GitHub\thread_kr\V7.cpp
<<

CMakeFiles\V7.dir\V7.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/V7.dir/V7.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\V7.dir\V7.cpp.s /c C:\Users\Donsg\Documents\GitHub\thread_kr\V7.cpp
<<

# Object files for target V7
V7_OBJECTS = \
"CMakeFiles\V7.dir\V7.cpp.obj"

# External object files for target V7
V7_EXTERNAL_OBJECTS =

V7.exe: CMakeFiles\V7.dir\V7.cpp.obj
V7.exe: CMakeFiles\V7.dir\build.make
V7.exe: CMakeFiles\V7.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Donsg\Documents\GitHub\thread_kr\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable V7.exe"
	C:\Users\Donsg\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\203.7717.62\bin\cmake\win\bin\cmake.exe -E vs_link_exe --intdir=CMakeFiles\V7.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\V7.dir\objects1.rsp @<<
 /out:V7.exe /implib:V7.lib /pdb:C:\Users\Donsg\Documents\GitHub\thread_kr\cmake-build-debug\V7.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\V7.dir\build: V7.exe

.PHONY : CMakeFiles\V7.dir\build

CMakeFiles\V7.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\V7.dir\cmake_clean.cmake
.PHONY : CMakeFiles\V7.dir\clean

CMakeFiles\V7.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\Donsg\Documents\GitHub\thread_kr C:\Users\Donsg\Documents\GitHub\thread_kr C:\Users\Donsg\Documents\GitHub\thread_kr\cmake-build-debug C:\Users\Donsg\Documents\GitHub\thread_kr\cmake-build-debug C:\Users\Donsg\Documents\GitHub\thread_kr\cmake-build-debug\CMakeFiles\V7.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\V7.dir\depend

