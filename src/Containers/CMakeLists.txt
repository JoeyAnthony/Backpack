cmake_minimum_required (VERSION 3.22.1)
project (Inituari)

set (CORE
	./src/Containers/array_list.h
	./src/Containers/array_list.cpp
	./src/Containers/container_types.h
)

add_executable (Inituari ${CORE} ${MyMath})