cmake_minimum_required(VERSION 3.7...3.22)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# set the project name and version
project(Backpack VERSION 1.0
		DESCRIPTION "A Runtime Game Engine"
		LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Build library
add_subdirectory(systems)

set (CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/backpack/)

set (GAME_PROJECT
	main.cpp
	unit_tests.h
	unit_tests.cpp
)
# prepend path before source files
list(TRANSFORM GAME_PROJECT PREPEND "./backpack/")

# Create project
add_executable (${PROJECT_NAME} ${GAME_PROJECT})

# Link Library
target_link_libraries(${PROJECT_NAME} PRIVATE core)

# Defenitions
#target_compile_definitions(${PROJECT_NAME} PUBLIC ASSERTIONS_ENABLED)
