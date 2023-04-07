#ifndef GRAPHS_GRAPH_HPP
#define GRAPHS_GRAPH_HPP

#include <cinttypes>
#include <vector>

namespace graphs::common {

    struct Graph {
        int32_t vertex_count;
        int32_t start_vertex;
        std::vector<std::vector<int64_t>> matrix;
    };

}

#endif //GRAPHS_GRAPH_HPP
