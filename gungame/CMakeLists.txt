project("GunGame" 
	DESCRIPTION "Backpack runtime library"
	VERSION 0.1) 

cmake_minimum_required (VERSION 3.22.1)

if(NOT CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	message(STATUS "${PROJECT_NAME} is not the top-level project. Top-level: ${CMAKE_PROJECT_NAME}")
else()
	message(STATUS "${PROJECT_NAME} library is the top-level project.")
endif()

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set (SOURCE
	gungame/main.cpp
	gungame/game.h
	gungame/game.cpp
	gungame/subsystems.h
	gungame/subsystems.cpp
	gungame/window.h
	gungame/window.cpp
)

# Create project
add_executable (${PROJECT_NAME} ${SOURCE})

# Link Library
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/libbackpack)
target_link_libraries(${PROJECT_NAME} PRIVATE Backpack)
