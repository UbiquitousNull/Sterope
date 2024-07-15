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

add_executable(SteropeLauncher ${CORE_SOURCES})

target_include_directories(SteropeLauncher PRIVATE main/include)