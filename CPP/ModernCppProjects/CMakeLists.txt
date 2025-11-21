# Step 1: Tell Cmake the minimum version required to use modern features.
cmake_minimum_required(VERSION 3.15)

#Step 2: Give your project a name and specify that it uses C++
project(ModernCppProjects LANGUAGES CXX)

#Set global C++ standard
# These affect all subprojects by default.
# Use C++ 20 features 
set(CMAKE_CXX_STANDARD 20)
# makes sure the compiler actually supports C++20 (no fallback to older version)
Set(CMAKE_CXX_STANDARD REQUIRED ON)

#Optional: Enable warnings and modern flags, which is a hallmark of good professional C++ practive.
if(MSVC)
   # /w4 - Enables warning level 4 (finds most commont issues.)
   # /permissive - Enforces ISO-compliant C++ (disallows compiler-specific shortcuts)
   # /Zc:__cplusplus - Makes the macro __cpluscplus report the true language version (important for feature detection)
   add_compile_options("/W4" "/permissive-" "/Zc:__cplusplus")
else()
   # -Wall - Enable basic warning 
   # -Wextra - Enable additional, useful warnings.
   # -pedantic - Enforce strict ISO compliance.
   # -Werror - Treat warnigns as werrors, forcing clean code. 
   add_compile_options(-Wall -Wextra -pedantic -Werror)
endif() 

#NEW: Tell CMake we want SQLite from vcpkg 
find_package(unofficial-sqlite3 CONFIG REQUIRED)

#Add sub projects
#line tells CMake to
# 1. Go inside that folder.
# 2. Read its own CMakeLists.txt 
# 3. Build that project as a separate executable. 
add_subdirectory(projects/Project1_StudentMgmt)
#Add more projects as you go 