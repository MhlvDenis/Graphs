#ifndef GRAPHS_ALGORITHMS_HPP
#define GRAPHS_ALGORITHMS_HPP

#include "../common/Graph.hpp"
#include "../common/Result.hpp"

namespace graphs::algorithms {

    common::Result Dijkstra(const common::Graph& graph);
    common::Result FordBellman(const common::Graph& graph);

}

#endif //GRAPHS_ALGORITHMS_HPP
