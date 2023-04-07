cmake_minimum_required(VERSION 3.22)
project(Graphs)

set(CMAKE_CXX_STANDARD 17)

include_directories(deps/googletest/googlemock/include)
include_directories(deps/googletest/googletest/include)
include_directories(deps/json/include)

add_executable(App
        main.cpp

        algorithms/Algorithms.hpp
        algorithms/Dijkstra.cpp
        algorithms/FordBellman.cpp

        common/Graph.hpp
        common/Result.hpp
        common/Consts.hpp

        io/GraphBuilder.cpp
        io/GraphBuilder.hpp)
