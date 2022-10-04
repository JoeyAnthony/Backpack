project("BackpackFrameWork" 
	DESCRIPTION "Backpack runtime library"
	VERSION 0.1) 

cmake_minimum_required (VERSION 3.22.1)

if(NOT CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	message(STATUS "${PROJECT_NAME} is not the top-level project. Top-level: ${CMAKE_PROJECT_NAME}")
else()
	message(STATUS "${PROJECT_NAME} library is the top-level project.")
endif()

set (FrameWorkSource
	main.cpp
	unit_tests.h
	unit_tests.cpp
)
# prepend path before source files
list(TRANSFORM FrameWorkSource PREPEND "./framework/")

# Create project
add_executable (${PROJECT_NAME} ${FrameWorkSource})

# Link Libraries
include_directories(${CMAKE_SOURCE_DIR}/libbackpack/)
target_link_libraries(${PROJECT_NAME} PRIVATE Backpack)
