#include "GraphBuilder.hpp"

#include "../common/Consts.hpp"

#include <cinttypes>
#include <fstream>
#include <iostream>
#include <vector>

namespace graphs::io {

    GraphBuilder::GraphBuilder(const std::filesystem::path& path) {
        std::ifstream input_json(path);
        input_json >> graph_json;
    }

    bool GraphBuilder::is_json_valid() const {
        if (graph_json.find("vertex_count") == graph_json.end() ||
            graph_json.find("start_vertex") == graph_json.end() ||
            graph_json.find("matrix") == graph_json.end()) {
            return false;
        }
        if (!graph_json["vertex_count"].is_number_integer() ||
            !graph_json["start_vertex"].is_number_integer() ||
            !graph_json["matrix"].is_array()) {
            return false;
        }
        if (graph_json["vertex_count"] < 0 ||
            graph_json["vertex_count"] < graph_json["start_vertex"] ||
            graph_json["matrix"].size() != graph_json["vertex_count"]) {
            return false;
        }
        for (const auto& line : graph_json["matrix"]) {
            if (!line.is_array() || line.size() != graph_json["vertex_count"]) {
                return false;
            }
            for (const auto& w : line) {
                if (!w.is_number_integer()) {
                    if (!w.is_string() || w != "inf") {
                        return false;
                    }
                } else if (w < 0) {
                    return false;
                }
            }
        }
        return true;
    }

    common::Graph GraphBuilder::build() const {
        int32_t vertex_count = graph_json["vertex_count"];
        std::vector<std::vector<int64_t>> matrix(vertex_count, std::vector<int64_t>(vertex_count));
        for (int32_t u = 0; u < vertex_count; ++u) {
            for (int32_t v = 0; v < vertex_count; ++v) {
                if (graph_json["matrix"][u][v].is_string() ||
                    graph_json["matrix"][u][v] == 0) {
                    matrix[u][v] = common::INFINITY_LENGTH;
                } else {
                    matrix[u][v] = graph_json["matrix"][u][v];
                }
            }
        }

        return {
            vertex_count,
            graph_json["start_vertex"],
            matrix
        };
    }

}
