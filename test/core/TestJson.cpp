#include <gtest/gtest.h>

#include <nlohmann/json.hpp>

#include <common/Consts.hpp>
#include <json/GraphBuilder.hpp>
#include <json/JsonBuilder.hpp>

using namespace graphs::json;
using namespace graphs::common;

bool GraphsAreEQ(const Graph& g1, const Graph& g2) {
    return g1.vertex_count == g2.vertex_count &&
        g1.start_vertex == g2.start_vertex &&
        g1.matrix == g2.matrix;
}

TEST(GraphBuilder, OrdinaryGraph) {
    const Graph expected_graph = {
            5,
            1,
            {
                    { INFINITY_LENGTH, 4, 1, INFINITY_LENGTH, INFINITY_LENGTH },
                    { 4, INFINITY_LENGTH, INFINITY_LENGTH, 1, 1 },
                    { 1, INFINITY_LENGTH, INFINITY_LENGTH, 1, INFINITY_LENGTH },
                    { INFINITY_LENGTH, 1, 1, INFINITY_LENGTH, 3 },
                    { INFINITY_LENGTH, 1, INFINITY_LENGTH, 3, INFINITY_LENGTH }
            }
    };

    const GraphBuilder graph_builder("../../resources/graph.json");
    ASSERT_TRUE(graph_builder.is_json_valid());
    ASSERT_TRUE(GraphsAreEQ(expected_graph, graph_builder.build()));
}

TEST(GraphBuilder, EmptyGraph) {
    const Graph expected_graph = {
            0, 0, {},
    };

    const GraphBuilder graph_builder("../../resources/empty.json");
    ASSERT_TRUE(graph_builder.is_json_valid());
    ASSERT_TRUE(GraphsAreEQ(expected_graph, graph_builder.build()));
}

TEST(GraphBuilder, DefectGraph) {
    const GraphBuilder graph_builder("../../resources/defect.json");
    ASSERT_FALSE(graph_builder.is_json_valid());
}

TEST(JsonBuilder, OrdinaryGraph) {
    const nlohmann::json expected_json = {
            {"vertex_count", 5},
            {"start_vertex", 1},
            {"distances", {0, 3, 1, 2, 4}}
    };

    const Result input_result = {
            5, 1, {0, 3, 1, 2, 4}
    };

    ASSERT_EQ(expected_json, JsonBuilder(input_result).build());
}

TEST(JsonBuilder, EmptyGraph) {
    const nlohmann::json expected_json = {
            {"vertex_count", 0},
            {"start_vertex", 0},
            {"distances", nlohmann::json(nlohmann::json::value_type::array())}
    };

    const Result input_result = {
            0, 0, {}
    };

    ASSERT_EQ(expected_json, JsonBuilder(input_result).build());
}
