#include <common/Graph.hpp>
#include <common/Result.hpp>
#include <common/Consts.hpp>

#include <cinttypes>
#include <vector>
#include <set>

namespace graphs::algorithms {

    common::Result Dijkstra(const common::Graph& graph) {
        if (graph.vertex_count == 0) {
            return {
                graph.vertex_count,
                graph.start_vertex,
                {}
            };
        }

        std::vector<std::vector<std::pair<int32_t, int64_t>>> connectivity_list(graph.vertex_count);
        for (int32_t u = 0; u < graph.vertex_count; ++u) {
            for (int32_t v = 0; v < graph.vertex_count; ++v) {
                if (graph.matrix[u][v] < common::INFINITY_LENGTH) {
                    connectivity_list[u].push_back({v, graph.matrix[u][v]});
                }
            }
        }

        std::vector<int64_t> distances(graph.vertex_count, common::INFINITY_LENGTH);
        std::set<std::pair<int64_t, int32_t>> query;

        distances[graph.start_vertex - 1] = 0;
        query.insert({0, graph.start_vertex - 1});
        while (!query.empty()) {
            const auto u = query.begin()->second;
            query.erase(query.begin());
            for (const auto& [to, w] : connectivity_list[u]) {
                if (distances[u] + w < distances[to]) {
                    query.erase({distances[to], to});
                    distances[to] = distances[u] + w;
                    query.insert({distances[to], to});
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