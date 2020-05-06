cmake_minimum_required(VERSION 3.1)
project(TP_PROJECT)
set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR})

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)


#add_subdirectory(${CMAKE_SOURCE_DIR}/src/map)
#add_subdirectory(${CMAKE_SOURCE_DIR}/src/building)


add_executable(MAIN main.cpp)

#target_link_libraries(lib)
