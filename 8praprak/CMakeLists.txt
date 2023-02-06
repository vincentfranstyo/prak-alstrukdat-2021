cmake_minimum_required(VERSION 3.23)
project(8praprak C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(hashmap)
include_directories(map)
include_directories(set)

add_executable(8praprak
        hashmap/boolean.h
        hashmap/hashmap.c
        hashmap/hashmap.h
        map/boolean.h
        map/map.c
        map/map.h
        set/boolean.h
        set/set.c
        set/set.h)
