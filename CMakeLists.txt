cmake_minimum_required(VERSION 3.20)
project(i18n VERSION "1.0" LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -static-libstdc++")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*")

add_library(i18n STATIC ${SOURCES})
target_include_directories(i18n PRIVATE "${PROJECT_SOURCE_DIR}/include")
