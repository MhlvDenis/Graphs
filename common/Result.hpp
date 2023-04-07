#ifndef GRAPHS_RESULT_HPP
#define GRAPHS_RESULT_HPP

#include <cinttypes>
#include <vector>

namespace graphs::common {

    struct Result {
        int32_t vertex_count;
        int32_t start_vertex;
        std::vector<int64_t> distances;
    };

}

#endif //GRAPHS_RESULT_HPP
