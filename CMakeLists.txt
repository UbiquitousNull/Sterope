#   This file is for building the program into a .exe
#
#   DO NOT DELETE!
#
#

cmake_minimum_required(VERSION 3.15)
project(SteropeLauncher)

# Specify the C standard
set(CMAKE_C_STANDARD 99)

# Add source files
set(CORE_SOURCES
    main/src/main.c
    main/src/window.c
    main/src/gl.c
)

# Add include directories
set(CORE_INCLUDES
    main/include/core/
    main/include/SDL2/
    main/include/GLAD2/
)

# Find SDL2
find_package(SDL2 REQUIRED)
if (SDL2_FOUND)
    include_directories(${SDL2_INCLUDE_DIRS})
    link_libraries(${SDL2_LIBRARIES})
else()
    message(FATAL_ERROR "SDL2 not found")
endif()

# Add GLAD2
#list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
#find_package(GLAD2 REQUIRED)
#if (GLAD2_FOUND)
    include_directories(${GLAD2_INCLUDE_DIRS})
    link_libraries(${GLAD2_LIBRARIES})
#else()
    #message(FATAL_ERROR "GLAD2 not found")
#endif()

# Create executable
add_executable(SteropeLauncher ${CORE_SOURCES})

# Link SDL2 library
target_link_libraries(SteropeLauncher ${GLAD2_LIBRARIES} SDL2::SDL2)

# Include core includes
target_include_directories(SteropeLauncher PRIVATE ${CORE_INCLUDES})