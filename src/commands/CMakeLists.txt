cmake_minimum_required(VERSION 3.1)
project(commands)

set(SOURCE_LIB command_attack.cpp moveunit.cpp commandbarracks.cpp)
add_library(commands STATIC command_attack.cpp moveunit.cpp commandbarracks.cpp)  
