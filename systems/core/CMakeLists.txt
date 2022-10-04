cmake_minimum_required (VERSION 3.22.1)

# Core files
set (CORE
	types.h
	os.h
	debug.h
	debug.cpp
	engine.h
	engine.cpp
	timer.h
	timer.cpp
)
# prepend path before source files
#list(TRANSFORM CORE PREPEND "./core/")


# Container files
set (CONTAINER_TYPES
	array_list.h
	array_list.cpp
	container_types.h
)
# prepend path before source files
list(TRANSFORM CONTAINER_TYPES PREPEND "./containers/")


# Math files
set (MATH_TYPES
	math_types.h
	mat3.h
	mat3.cpp
	mat4.h
	mat4.cpp
	math.h
	math.cpp
	vector2.h
	vector2.cpp
	vector3.h
	vector3.cpp
	vector4.h
	vector4.cpp
)
# prepend path before source files
list(TRANSFORM MATH_TYPES PREPEND "./math/")


# Allocator files
set (ALLOCATORS
	memory_tools.h
	allocators.h
	allocators.cpp
	MallocAllocator.h
	MallocAllocator.cpp
	PoolAllocator.h
	PoolAllocator.cpp
)
# prepend path before source files
list(TRANSFORM ALLOCATORS PREPEND "./memory/")


# Subsystem files
set (SUBSYSTEMS
	log_manager.h
	log_manager.cpp
	logger.h
	logger.cpp
	memory_manager.h
	memory_manager.cpp
	subsystem_manager.h
	subsystem_manager.cpp
)
# prepend path before source files
list(TRANSFORM SUBSYSTEMS PREPEND "./subsystems/")

# World files
set (WORLD
	world.h
	world.cpp
	updateloop.h
	updateloop.cpp
)
# prepend path before source files
list(TRANSFORM WORLD PREPEND "./World/")

# Add library
add_library (core ${CORE} ${CONTAINER_TYPES} ${MATH_TYPES} ${ALLOCATORS} ${SUBSYSTEMS} ${WORLD})

# Add includes
target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/)

# VS Filters
source_group("core"			FILES ${CORE})
source_group("containers" 	FILES ${CONTAINER_TYPES})
source_group("maths"		FILES ${MATH_TYPES})
source_group("allocators" 	FILES ${ALLOCATORS})
source_group("subsystems" 	FILES ${SUBSYSTEMS})
source_group("world" 		FILES ${WORLD})

# Dependencies
#target_link_libraries(core PRIVATE subsystems)

target_compile_definitions(core PUBLIC ASSERTIONS_ENABLED)


# filesystem - just some filepaths for saving data - loading data
# engine configurations - reading config files like ini
