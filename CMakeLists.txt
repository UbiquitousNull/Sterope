# # # # # # # # # # # # # # # # # # # # # # #
#   This file is for building the program
#
#   DO NOT DELETE!
#
#

cmake_minimum_required(VERSION 3.15)
project(SteropeLauncher)

set(CMAKE_C_STANDARD 99)

set(CORE_SOURCES
    main/src/main/main.c
    main/src/main/SDL.c
    main/src/main/GL.c
    main/src/main/eventSys.c
    main/src/main/io.c
    main/src/main/logging.c
    main/src/etc/GLAD/gl.c
)

set(CORE_INCLUDES
    main/include/main/
    main/include/etc/SDL/
    main/include/etc/GLAD/
)

find_package(SDL2 REQUIRED)
if (SDL2_FOUND)
    include_directories(${SDL_INCLUDE_DIRS})
    link_libraries(${SDL_LIBRARIES})
else()
    message(FATAL_ERROR "SDL not found")
endif()

include_directories(main/include/etc/GLAD)
#link_libraries(${GLAD_LIBRARIES})

add_executable(SteropeLauncher WIN32 ${CORE_SOURCES})

target_link_libraries(SteropeLauncher ${GLAD_LIBRARIES} SDL2::SDL2)

target_include_directories(SteropeLauncher PRIVATE ${CORE_INCLUDES})