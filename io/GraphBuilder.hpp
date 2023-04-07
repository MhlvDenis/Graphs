#ifndef GRAPHS_GRAPHBUILDER_HPP
#define GRAPHS_GRAPHBUILDER_HPP

#include "../common/Graph.hpp"

#include <filesystem>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace graphs::io {

    class GraphBuilder {
    private:
        json graph_json;

    public:
        explicit GraphBuilder(const std::filesystem::path& path);

        [[nodiscard]] bool is_json_valid() const;

        [[nodiscard]] common::Graph build() const;
    };

}

#endif //GRAPHS_GRAPHBUILDER_HPP
