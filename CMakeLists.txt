cmake_minimum_required(VERSION 3.26)
project(trail)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE PROJECT_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h)
file(GLOB_RECURSE PROJECT_SOURCE_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp)
file(GLOB_RECURSE PROJECT_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)


add_library(${PROJECT_NAME} SHARED
        ${PROJECT_HEADERS}
        ${PROJECT_SOURCE_HEADERS}
        ${PROJECT_SOURCES}
)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/")

include(FetchContent)
#dxsdk
include(FindDirectX9)
target_link_libraries(${PROJECT_NAME} PRIVATE DirectX9)

add_compile_definitions(_USE_MATH_DEFINES)

set_target_properties(
        ${PROJECT_NAME}
        PROPERTIES
        OUTPUT_NAME ${PROJECT_NAME}
        SUFFIX ".asi"
)