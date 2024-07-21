#   This file is for building the program into a .exe
#
#   DO NOT DELETE!
#
#

cmake_minimum_required(VERSION 3.15)
project(SteropeLauncher)

set(CORE_SOURCES
    main/src/main.c
    main/src/window.c
)

set(CORE_INCLUDES
    main/include/
)

set(SDL2_INCLUDE_DIR "D:/VSC/Sterope/SDL2/include/SDL2")
set(SDL2_LIBRARY_DIR "D:/VSC/Sterope/SDL2/lib")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mwindows")


# Include and link directories
include_directories(${SDL2_INCLUDE_DIR} ${CORE_INCLUDES})
link_directories(${SDL2_LIBRARY_DIR})

# Find SDL2 libraries
find_library(SDL2_LIBRARY NAMES SDL2 PATHS ${SDL2_LIBRARY_DIR} NO_DEFAULT_PATH)
find_library(SDL2MAIN_LIBRARY NAMES SDL2main PATHS ${SDL2_LIBRARY_DIR} NO_DEFAULT_PATH)

find_package(SDL2 REQUIRED)

add_executable(SteropeLauncher ${CORE_SOURCES})

# Linking libraries
target_link_libraries(SteropeLauncher PRIVATE ${SDL2MAIN_LIBRARY} ${SDL2_LIBRARY})