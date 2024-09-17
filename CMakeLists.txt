#   This file is for building the program into a .exe
#
#   DO NOT DELETE!
#
#

cmake_minimum_required(VERSION 3.15)
project(SteropeLauncher)

set(CMAKE_C_STANDARD 99)

set(CORE_SOURCES
    main/src/main/main.c
    main/src/main/windowSDL2.c
    main/src/main/windowGl.c
    main/src/main/eventSys.c
    main/src/main/io.c
    main/src/main/logging.c
    main/src/etc/gl.c
)

set(CORE_INCLUDES
    main/include/main/
    main/include/etc/SDL2/
    main/include/etc/GLAD2/
)

find_package(SDL2 REQUIRED)
if (SDL2_FOUND)
    include_directories(${SDL2_INCLUDE_DIRS})
    link_libraries(${SDL2_LIBRARIES})
else()
    message(FATAL_ERROR "SDL2 not found")
endif()

include_directories(main/include/etc/GLAD2)
#link_libraries(${GLAD2_LIBRARIES})

add_executable(SteropeLauncher WIN32 ${CORE_SOURCES})

target_link_libraries(SteropeLauncher ${GLAD2_LIBRARIES} SDL2::SDL2)

target_include_directories(SteropeLauncher PRIVATE ${CORE_INCLUDES})