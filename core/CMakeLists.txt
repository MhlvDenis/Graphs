set(
        SOURCES_CORE

        algorithms/Algorithms.hpp
        algorithms/Dijkstra.cpp
        algorithms/FordBellman.cpp

        common/Graph.hpp
        common/Result.hpp
        common/Consts.hpp

        io/OutputProvider.cpp
        io/OutputProvider.hpp

        json/JsonBuilder.cpp
        json/JsonBuilder.hpp
        json/GraphBuilder.cpp
        json/GraphBuilder.hpp)

add_library(
        ${LIBRARY_CORE} STATIC

        ${SOURCES_CORE}
)

target_include_directories(
        ${LIBRARY_CORE} PUBLIC

        ${INCLUDE_CORE}
        ${INCLUDE_JSON}
)

target_link_libraries(
        ${LIBRARY_CORE}

        ${LIBRARY_JSON}
)