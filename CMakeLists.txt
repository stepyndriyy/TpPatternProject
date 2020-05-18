cmake_minimum_required(VERSION 3.1)
project(TP_PROJECT)
set(CMAKE_CXX_STANDARD 17)

#include_directories(${CMAKE_SOURCE_DIR})
#include_directories(${CMAKE_SOURCE_DIR}/src/map)
#include_directories(${CMAKE_SOURCE_DIR}/src/commands)
#include_directories(${CMAKE_SOURCE_DIR}/src/buildings)
#include_directories(${CMAKE_SOURCE_DIR}/src/interface)
#include_directories(${CMAKE_SOURCE_DIR}/src/player)
#include_directories(${CMAKE_SOURCE_DIR}/src/units)

#include_directories(${CMAKE_SOURCE_DIR}/src)


set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)


#set(SRC main.cpp src/game.h)

#add_subdirectory(${CMAKE_SOURCE_DIR}/src/map)
#add_subdirectory(${CMAKE_SOURCE_DIR}/src/buildings)
#add_subdirectory(${CMAKE_SOURCE_DIR}/src/commands)

#file (SRC "*.h" "*.cpp")

#message("src is: " ${SRC})

#add_executable(MAIN ${SRC})



#target_link_libraries(MAIN buildings gamemap commands)

    add_executable(MAIN 

        src/map/map.cpp
        src/map/gamemap.cpp 
        #src/map/map.h
        #src/map/gamemap.h 
        
        src/buildings/barracks.cpp 
        #src/buildings/barracks.h
        src/buildings/adapted_barracks.cpp
        #src/buildings/adapted_barracks.h
        
        #src/commands/command.h
        #src/commands/command_attack.h
        #src/commands/commandbarracks.h
        #src/commands/moveunit.h
        
        #src/interface/entity.h

        #src/player/player.h
        
        #src/units/archer.h 
        #src/units/swordman.h
        
        main.cpp

        #src/game.h
        ) 


