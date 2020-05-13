cmake_minimum_required(VERSION 3.1)
project(buildings)

set(SOURCE_LIB barracks.cpp)

add_library(buildings STATIC ${SOURCE_LIB} adapted_barracks.cpp)  
