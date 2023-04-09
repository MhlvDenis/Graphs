#include <json/GraphBuilder.hpp>
#include <algorithms/Algorithms.hpp>
#include <io/OutputProvider.hpp>

#include <iostream>

int main([[maybe_unused]] int argc, char *argv[]) {
    const auto graph_builder = graphs::json::GraphBuilder(argv[1]);
    if (graph_builder.is_json_valid()) {
        const auto graph = graph_builder.build();

        const auto dijkstra_result = graphs::algorithms::Dijkstra(graph);
        const auto ford_bellman_result = graphs::algorithms::FordBellman(graph);

        graphs::io::OutputProvider(std::cout).output_as_standard(dijkstra_result);

        std::ofstream dijkstra_fout("DijkstraResult.json");
        graphs::io::OutputProvider(dijkstra_fout).output_as_json(dijkstra_result);

        std::ofstream ford_bellman_fout("FordBellmanResult.json");
        graphs::io::OutputProvider(ford_bellman_fout).output_as_json(ford_bellman_result);
    } else {
        std::cerr << "Json file is not valid\n";
    }
}