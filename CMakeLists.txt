cmake_minimum_required (VERSION 3.22.1)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# set the project name and version
project(BackPackProject VERSION 1.0
		DESCRIPTION "A Runtime Game Engine"
		LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Build library
add_subdirectory(libbackpack)
#add_subdirectory(framework)
add_subdirectory(gungame)