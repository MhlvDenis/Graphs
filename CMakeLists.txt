cmake_minimum_required(VERSION 3.22)
project(Graphs)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Testing framework
set(DIRECTORY_GTEST ${PROJECT_SOURCE_DIR}/deps/googletest)
set(INCLUDE_GTEST ${DIRECTORY_GTEST}/googletest/include)
set(LIBRARY_GTEST gtest_main)

# JSON parce library
set(DIRECTORY_JSON ${PROJECT_SOURCE_DIR}/deps/json)
set(INCLUDE_JSON ${DIRECTORY_JSON}/include)

message(STATUS "JSON include: ${INCLUDE_JSON}")

# Core library
set(DIRECTORY_CORE ${PROJECT_SOURCE_DIR}/core)
set(INCLUDE_CORE ${DIRECTORY_CORE})
set(LIBRARY_CORE core)

add_subdirectory(${DIRECTORY_CORE})
message(STATUS "Core include: ${INCLUDE_CORE}")
message(STATUS "Core library: ${LIBRARY_CORE}")

# App binaries
set(DIRECTORY_APP ${PROJECT_SOURCE_DIR}/app)
set(EXECUTABLE_APP app)

add_subdirectory(${DIRECTORY_APP})
message(STATUS "App executable: ${EXECUTABLE_APP}")