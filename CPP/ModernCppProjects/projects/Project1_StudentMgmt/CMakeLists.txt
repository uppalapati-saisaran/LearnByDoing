# Tell CMake that your project needs at least version 3.15 to work.
cmake_minimum_required(VERSION 3.15)
# Defines the name of your main project
# and tells CMake we'll use the C++ language only. 
project(Project1_StudentMgmt LANGUAGES CXX)

# You are telling CMake that all targets (all subprojects) must use C++ 20 features.
set(CMAKE_CXX_STANDARD 20)
# makes this a hard rule - no fallback to older standards.
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Defines which file belong to this project.
set(SOURCES
    src/main.cpp 
    src/Student.cpp 
    src/StudentManager.cpp 
)

set(HEADERS 
    include/Student.hpp
    include/StudentManager.hpp 
)

# Create an executable (a .exe on Windows or binary on Linux)
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PRIVATE include)

if(MSVC)
   target_compile_options(${PROJECT_NAME} PRIVATE "/w4" "/permissive-" "/Zc:__cplusplus")
else()
   target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
endif()

#Puts the compiled .exe files into a clean bin/ folder (instead of scattered build folders).
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
