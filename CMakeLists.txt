cmake_minimum_required(VERSION 3.11)
project(raylibtemplate)

# Change this
set(base_DIR /home/user)

# MinGW is not fun
if (MINGW)
    set(raylib_INCLUDE_DIRS ${base_DIR}/raylib/src)
    set(raylib_LIBRARIES ${PROJECT_SOURCE_DIR}/lib/win/libraylib.dll)
elseif (EMSCRIPTEN)
    add_definitions(-DPLATFORM_WEB)
    set(raylib_INCLUDE_DIRS ${base_DIR}/raylib/src)
    set(raylib_LIBRARIES ${PROJECT_SOURCE_DIR}/lib/web/libraylib.a)
    set(CMAKE_TOOLCHAIN_FILE ${base_DIR}/emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake)
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
else()
    find_package(raylib QUIET) # Let CMake search for a raylib-config.cmake
endif()

# Because who wants to bother linking these statically?
set( MINGW_DLLS
    /usr/x86_64-w64-mingw32/bin/libgcc_s_seh-1.dll
    /usr/x86_64-w64-mingw32/bin/libssp-0.dll
    /usr/x86_64-w64-mingw32/bin/libstdc++-6.dll
    /usr/x86_64-w64-mingw32/bin/libwinpthread-1.dll
    ${raylib_LIBRARIES}
)

# C++17 support pls
add_definitions("-std=c++17")

# Source files
aux_source_directory(src SRC_LIST)
aux_source_directory(src/Components SRC_LIST)
aux_source_directory(src/Managers SRC_LIST)
aux_source_directory(src/Systems SRC_LIST)

# Conan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Includes
include_directories(${raylib_INCLUDE_DIRS})
include_directories(include)
include_directories(include/Components)
include_directories(include/Managers)
include_directories(include/Systems)

# Executable
add_executable(${PROJECT_NAME} ${SRC_LIST})

# Linker stuff. Does this matter? Who knows.
link_directories(${PROJECT_SOURCE_DIR}/lib/win)
link_directories(${PROJECT_SOURCE_DIR}/lib/web)
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS} ${raylib_LIBRARIES})

# Horrible but works lol
if (MINGW)
    target_link_libraries(${PROJECT_NAME} winmm pthread gdi32 user32 kernel32 opengl32)

    foreach(file_dll ${MINGW_DLLS})
        add_custom_command(
            TARGET ${PROJECT_NAME} 
            POST_BUILD
            COMMAND ${CMAKE_COMMAND}
            ARGS -E copy ${file_dll} "${CMAKE_BINARY_DIR}/bin"
        )
    endforeach(file_dll)
endif()

# HTML5 garbage
if (EMSCRIPTEN)
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "-s USE_GLFW=3 -s TOTAL_MEMORY=67108864 -s FORCE_FILESYSTEM=1 --preload-file ../resources --shell-file ${raylib_INCLUDE_DIRS}/shell.html")
endif()

# macOS garbage, probably broken lol
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()