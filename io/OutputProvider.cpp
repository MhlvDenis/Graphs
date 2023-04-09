#include "OutputProvider.hpp"
#include "../json/JsonBuilder.hpp"

#include <iostream>

namespace graphs::io {

    OutputProvider::OutputProvider(std::ostream& init_out) : out(init_out) { }

    void OutputProvider::output_as_standard(const common::Result& result) const {
        out << "Vertex count: " << result.vertex_count << '\n';
        out << "Distances:\n";
        for (int i = 0; i < result.distances.size(); ++i) {
            out << "\tFrom " << result.start_vertex << " to " << (i + 1) << ": " << result.distances[i] << '\n';
        }
    }

    void OutputProvider::output_as_json(const common::Result& result) const {
        out << json::JsonBuilder(result).build().dump(2) << '\n';
    }

};
