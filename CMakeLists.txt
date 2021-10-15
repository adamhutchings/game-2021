cmake_minimum_required(VERSION 3.3)
project(game21)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/build/debug")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

include_directories(${OPENGL_INCLUDE_DIR})

file(GLOB_RECURSE SOURCES src/*.cpp src/gl/glad.c)

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    add_subdirectory(glfw)
else()
    find_package(glfw3 REQUIRED)
endif()

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(CMAKE_CXX_FLAGS "-framework OpenGL -Wall -Wno-unused-command-line-argument -g")
else()
    if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
        find_package(OpenGL REQUIRED)
    else()
        find_package(glfw OpenGL REQUIRED)
    endif()
endif()

add_executable(game21 ${SOURCES})
target_include_directories(game21 PRIVATE src)
target_link_libraries(game21 ${OPENGL_gl_LIBRARY} glfw)

