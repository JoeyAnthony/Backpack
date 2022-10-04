project("Backpack" 
	DESCRIPTION "Backpack runtime library"
	VERSION 0.1) 

cmake_minimum_required (VERSION 3.22.1)

if(NOT CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	message(STATUS "${PROJECT_NAME} is not the top-level project. Top-level: ${CMAKE_PROJECT_NAME}")
else()
	message(STATUS "${PROJECT_NAME} library is the top-level project.")
endif()

# Set install prefix
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/install)
message(STATUS "CMAKE_INSTALL_PREFIX set to ${CMAKE_INSTALL_PREFIX}")

# Core files
set (CORE_H
	backpack/core/types.h 
	backpack/core/os.h
	backpack/core/debug.h
	backpack/core/engine.h
	backpack/core/timer.h
	backpack/core/hashing.h
)
set (CORE_SRC
	backpack/core/debug.cpp
	backpack/core/engine.cpp
	backpack/core/timer.cpp
	backpack/core/hashing.cpp
)

# Container files
set (CONTAINER_H
	backpack/containers/array_list.h
	backpack/containers/container_types.h
)
set(CONTAINER_SRC
	backpack/containers/array_list.cpp
)

# Math files
set (MATH_H
	backpack/math/math_types.h
	backpack/math/mat3.h
	backpack/math/mat4.h
	backpack/math/math.h
	backpack/math/vector2.h
	backpack/math/vector3.h
	backpack/math/vector4.h
)
set (MATH_SRC
	backpack/math/mat3.cpp
	backpack/math/mat4.cpp
	backpack/math/math.cpp
	backpack/math/vector2.cpp
	backpack/math/vector3.cpp
	backpack/math/vector4.cpp
)

# Allocator files
set (ALLOCATORS_H
	backpack/memory/memory_tools.h
	backpack/memory/allocators.h
	backpack/memory/MallocAllocator.h
	backpack/memory/PoolAllocator.h
)
set(ALLOCATORS_SRC
	backpack/memory/allocators.cpp
	backpack/memory/MallocAllocator.cpp
	backpack/memory/PoolAllocator.cpp
)

# Subsystem files
set (SUBSYSTEMS_H
	backpack/subsystems/log_manager.h
	backpack/subsystems/logger.h
	backpack/subsystems/memory_manager.h
	backpack/subsystems/subsystem_manager.h
)
set(SUBSYSTEMS_SRC
	backpack/subsystems/log_manager.cpp
	backpack/subsystems/logger.cpp
	backpack/subsystems/memory_manager.cpp
	backpack/subsystems/subsystem_manager.cpp
)

# World files
set (WORLD_H
	backpack/world/world.h
	backpack/world/updateloop.h
	backpack/world/objectlookup.h
)
set (WORLD_SRC
	backpack/world/world.cpp
	backpack/world/updateloop.cpp
	backpack/world/objectlookup.cpp
)

# Add library
add_library (${PROJECT_NAME} STATIC)
target_sources(${PROJECT_NAME} PRIVATE
	backpack/backpack.h
	${CORE_H} 		${CORE_SRC}
	${SUBSYSTEMS_H} ${SUBSYSTEMS_SRC}
	${ALLOCATORS_H} ${ALLOCATORS_SRC}
	${WORLD_H} 		${WORLD_SRC}
)

target_include_directories(${PROJECT_NAME} 
	PRIVATE
		# where the library itself will look for its internal headers
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/backpack>
	PUBLIC 
		# where top-level project will look for the library's public headers
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
		# where external projects will look for the library's public headers
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDE_DIR}>
)

# Set public headers
set(public_headers ${CORE_H} ${CONTAINER_H} ${SUBSYSTEMS_H} ${WORLD_H})
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${public_headers}")
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "d")

# # Adds include definitions
# include(GNUInstallDirs)
# # install the target and create export-set
# install(TARGETS ${PROJECT_NAME}
    # EXPORT "${PROJECT_NAME}Targets"
    # # these get default values from GNUInstallDirs, no need to set them
    # #RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} # bin
    # #LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} # lib
    # #ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} # lib
    # # except for public headers, as we want them to be inside a library folder
    # PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
    # INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} # include
# )
# # -----------------------------------------------------------------------------------------
# # generate and install export file
# install(EXPORT "${PROJECT_NAME}Targets"
    # FILE "${PROJECT_NAME}Targets.cmake"
    # #NAMESPACE ${namespace}::
    # DESTINATION cmake
# )

# include(CMakePackageConfigHelpers)

# # generate the version file for the config file
# write_basic_package_version_file(
    # "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    # VERSION "${version}"
    # COMPATIBILITY AnyNewerVersion
# )
# # create config file
# configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake.in
    # "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    # INSTALL_DESTINATION cmake
# )
# # install config files
# install(FILES
    # "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    # "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    # DESTINATION cmake
# )
# # generate the export targets for the build tree
# export(EXPORT "${PROJECT_NAME}Targets"
    # FILE "${CMAKE_CURRENT_BINARY_DIR}/cmake/${PROJECT_NAME}Targets.cmake"
    # #NAMESPACE ${namespace}::
# )

# VS Filters
source_group("core"			FILES ${CORE_H} ${CORE_SRC})
# source_group("containers" 	FILES ${CONTAINER_TYPES_H} ${CONTAINER_TYPES_SRC})
# source_group("maths"			FILES ${MATH_TYPES_H} ${MATH_TYPES_SRC})
source_group("allocators" 	FILES ${ALLOCATORS_H} ${ALLOCATORS_SRC})
source_group("subsystems" 	FILES ${SUBSYSTEMS_H} ${SUBSYSTEMS_SRC})
source_group("world" 			FILES ${WORLD_H} ${WORLD_SRC})


# Aditional includes
find_package(EASTL CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE EASTL)

# # compile definitions
target_compile_definitions(${PROJECT_NAME} PUBLIC ASSERTIONS_ENABLED)
