#include <iostream>
#include "common/Graph.hpp"
#include "json/JsonBuilder.hpp"
#include "json/GraphBuilder.hpp"
#include "algorithms/Algorithms.hpp"

int main([[maybe_unused]] int argc, char *argv[]) {
    const auto graph_builder = graphs::json::GraphBuilder(argv[1]);
    if (graph_builder.is_json_valid()) {
        const auto graph = graph_builder.build();

        const auto result = graphs::algorithms::Dijkstra(graph);
        const auto result1 = graphs::algorithms::FordBellman(graph);

        std::cout << graphs::json::JsonBuilder(result).build().dump(2) << '\n';
        std::cout << graphs::json::JsonBuilder(result1).build().dump(2) << '\n';
    }
}