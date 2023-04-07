#include <iostream>
#include "common/Graph.hpp"
#include "io/GraphBuilder.hpp"

int main([[maybe_unused]] int argc, char *argv[]) {
    const auto graph_builder = graphs::io::GraphBuilder(argv[1]);
    if (graph_builder.is_json_valid()) {
        const auto graph = graph_builder.build();
        std::cout << graph.vertex_count << ' ' << graph.start_vertex << '\n';
        for (auto v : graph.matrix) {
            for (auto u : v) {
                std::cout << u << ' ';
            }
            std::cout << '\n';
        }
    }
}