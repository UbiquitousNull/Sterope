cmake_minimum_required(VERSION 3.15)
project(SteropeLauncher)

set(CMAKE_C_STANDARD 99)

# Source files
set(CORE_SOURCES
    main/src/main/main.c
    main/src/main/SDL.c
    main/src/main/GL.c
    main/src/main/eventSys.c
    main/src/main/io.c
    main/src/main/logging.c
    main/src/etc/GLAD/gl.c
)

# Include paths
set(CORE_INCLUDES
    main/include/main/
    main/include/etc/SDL/
    main/include/etc/GLAD/
)

# Add ANSI stdio compatibility for snprintf
add_definitions(-D__USE_MINGW_ANSI_STDIO=1)

# Add include directories
include_directories(
    ${CORE_INCLUDES}
    main/include/etc/GLAD
)

# Executable
add_executable(SteropeLauncher WIN32 ${CORE_SOURCES})

# Link SDL2 statically (no find_package)
target_link_libraries(SteropeLauncher
    ${CMAKE_SOURCE_DIR}/main/src/etc/SDL/libSDL2.a
    -lsetupapi
    -lcfgmgr32
    -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32
    -lshell32 -lversion -luuid -lkernel32 -lwinspool
    -lcomdlg32 -ladvapi32
)

# Add GLAD if needed
# target_link_libraries(SteropeLauncher ${GLAD_LIBRARIES}) ← optional if GLAD is pure source
