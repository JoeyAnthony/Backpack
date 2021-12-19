cmake_minimum_required (VERSION 3.22.1)
project (Inituari)

set (CORE
	./src/benchmarks.h
	./src/benchmarks.cpp
	./src/debug.h
	./src/debug.cpp
	./src/engine.h
	./src/engine.cpp
	./src/main.cpp
	./src/os.h
	./src/pch.h
	./src/pch.cpp
	./src/types.h
	./src/unit_tests.h
	./src/unit_tests.cpp

	./src/Containers/array_list.h
	./src/Containers/array_list.cpp
	./src/Containers/container_types.h

	./src/Memory/memory_tools.h
	./src/Memory/allocators.h
	./src/Memory/allocators.cpp
	./src/Memory/MallocAllocator.h
	./src/Memory/MallocAllocator.cpp
	./src/Memory/PoolAllocator.h
	./src/Memory/PoolAllocator.cpp

	./src/Subsystems/log_manager.h
	./src/Subsystems/log_manager.cpp
	./src/Subsystems/memory_manager.h
	./src/Subsystems/memory_manager.cpp
	./src/Subsystems/subsystem_manager.h
	./src/Subsystems/subsystem_manager.cpp
)

set (MyMath 
	./src/Math/math_types.h
	./src/Math/mat3.h
	./src/Math/mat3.cpp
	./src/Math/mat4.h
	./src/Math/mat4.cpp
	./src/Math/math.h
	./src/Math/math.cpp
	./src/Math/vector2.h
	./src/Math/vector2.cpp
	./src/Math/vector3.h
	./src/Math/vector3.cpp
	./src/Math/vector4.h
	./src/Math/vector4.cpp
)

add_executable (Inituari ${CORE} ${MyMath})