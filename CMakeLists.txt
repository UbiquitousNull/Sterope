#   This file is for building the program into a .exe
#
#   DO NOT DELETE!
#
#

cmake_minimum_required(VERSION 3.15)
project(SteropeLauncher)

set(CMAKE_C_STANDARD 99)

set(CORE_SOURCES
    main/src/main.c
    main/src/window.c
    main/src/gl.c
)

set(CORE_INCLUDES
    main/include/core/
    main/include/SDL2/
    main/include/GLAD2/
)

find_package(SDL2 REQUIRED)
if (SDL2_FOUND)
    include_directories(${SDL2_INCLUDE_DIRS})
    link_libraries(${SDL2_LIBRARIES})
else()
    message(FATAL_ERROR "SDL2 not found")
endif()

include_directories(main/include/GLAD2)
#link_libraries(${GLAD2_LIBRARIES})

add_executable(SteropeLauncher ${CORE_SOURCES})

target_link_libraries(SteropeLauncher ${GLAD2_LIBRARIES} SDL2::SDL2)

target_include_directories(SteropeLauncher PRIVATE ${CORE_INCLUDES})