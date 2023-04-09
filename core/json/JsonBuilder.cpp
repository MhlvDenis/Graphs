#include "JsonBuilder.hpp"

namespace graphs::json {


    JsonBuilder::JsonBuilder(const common::Result& init_result) {
        result = init_result;
    }

    nlohmann::json JsonBuilder::build() const {
        nlohmann::json result_json = {
                {"vertex_count", result.vertex_count},
                {"start_vertex", result.start_vertex},
                {"distances", nlohmann::json(nlohmann::json::value_type::array())}
        };
        for (const auto& dist : result.distances) {
            result_json["distances"].push_back(dist);
        }
        return result_json;
    }

}
