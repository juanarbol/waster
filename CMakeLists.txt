cmake_minimum_required(VERSION 3.14)

project(waster LANGUAGES C)

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to Release")
    set(CMAKE_BUILD_TYPE "Release")
endif()
message(STATUS "Building in ${CMAKE_BUILD_TYPE} mode")
message(STATUS "Building with ${CMAKE_C_COMPILER_ID} ${CMAKE_C_COMPILER_VERSION} on ${CMAKE_SYSTEM}")

set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if (CMAKE_BUILD_TYPE MATCHES "Debug")
    list(APPEND waster_cflags -g -O0 -fno-omit-frame-pointer)
endif()

add_subdirectory(deps/quickjs-0.3.0 EXCLUDE_FROM_ALL)

option(libuv_buildtests "" OFF)
add_subdirectory(deps/libuv-1.47.0 EXCLUDE_FROM_ALL)

add_executable(waster
    src/main.c
    src/tcp-server.c
    src/utils.c
)

set_target_properties(waster PROPERTIES
    C_STANDARD 11
    C_STANDARD_REQUIRED ON
)
target_compile_options(waster PRIVATE ${waster_cflags})
target_link_libraries(waster qjs uv_a)
