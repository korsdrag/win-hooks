cmake_minimum_required(VERSION 3.31)

project(win-hook
    VERSION "1.0.0"
    DESCRIPTION ""
    LANGUAGES CXX C)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
set(USE_STATIC_MSVC_RUNTIME_LIBRARY ON CACHE BOOL "" FORCE)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)

target_include_directories(win-hook PUBLIC ${CMAKE_SOURCE_DIR}/src/hook)
