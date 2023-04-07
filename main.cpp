#include <iostream>
#include "common/Graph.hpp"
#include "io/GraphBuilder.hpp"
#include "algorithms/Algorithms.hpp"

int main([[maybe_unused]] int argc, char *argv[]) {
    const auto graph_builder = graphs::io::GraphBuilder(argv[1]);
    if (graph_builder.is_json_valid()) {
        const auto graph = graph_builder.build();

        const auto result = graphs::algorithms::Dijkstra(graph);
        for (auto i : result.distances) {
            std::cout << i << ' ';
        }
        std::cout << '\n';

        const auto result1 = graphs::algorithms::FordBellman(graph);
        for (auto i : result1.distances) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }
}