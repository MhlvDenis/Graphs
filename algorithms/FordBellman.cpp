#include "../common/Graph.hpp"
#include "../common/Result.hpp"
#include "../common/Consts.hpp"

#include <cinttypes>
#include <vector>

namespace graphs::algorithms {

    common::Result FordBellman(const common::Graph& graph) {
        if (graph.vertex_count == 0) {
            return {
                    graph.vertex_count,
                    graph.start_vertex,
                    {}
            };
        }

        struct Edge {
            int32_t u, v;
            int64_t w;
        };

        std::vector<Edge> edges;
        for (int32_t u = 0; u < graph.vertex_count; ++u) {
            for (int32_t v = 0; v < graph.vertex_count; ++v) {
                if (graph.matrix[u][v] < common::INFINITY_LENGTH) {
                    edges.push_back({u, v, graph.matrix[u][v]});
                }
            }
        }

        std::vector<int64_t> distances(graph.vertex_count, common::INFINITY_LENGTH);
        distances[graph.start_vertex - 1] = 0;
        for (int k = 0; k < graph.vertex_count - 1; ++k) {
            for (const auto& [u, v, w] : edges) {
                if (distances[u] != common::INFINITY_LENGTH &&
                    distances[u] + w < distances[v]) {
                    distances[v] = distances[u] + w;
                }
            }
        }

        return {
            graph.vertex_count,
            graph.start_vertex,
            distances
        };
    }

}