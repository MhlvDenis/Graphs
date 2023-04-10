#include <gtest/gtest.h>

#include <algorithms/Algorithms.hpp>
#include <common/Consts.hpp>

using namespace graphs::common;
using namespace graphs::algorithms;

bool ResultsAreEQ(const Result& r1, const Result& r2) {
    return r1.vertex_count == r2.vertex_count &&
           r1.start_vertex == r2.start_vertex &&
           r1.distances == r2.distances;
}

const Graph ordinary_graph = {
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

const Result ordinary_expected_result = {
        5,
        1,
        { 0, 3, 1, 2, 4 }
};

TEST(Dijkstra, OrdinaryGraph) {
    ASSERT_TRUE(ResultsAreEQ(ordinary_expected_result, Dijkstra(ordinary_graph)));
}

TEST(FordBellman, OrdinaryGraph) {
    ASSERT_TRUE(ResultsAreEQ(ordinary_expected_result, FordBellman(ordinary_graph)));
}

const Graph spilt_graph = {
        6,
        3,
        {
                {INFINITY_LENGTH, 1, 1, INFINITY_LENGTH, INFINITY_LENGTH, INFINITY_LENGTH},
                {1, INFINITY_LENGTH, 1, INFINITY_LENGTH, INFINITY_LENGTH, INFINITY_LENGTH},
                {1, 1, INFINITY_LENGTH, INFINITY_LENGTH, INFINITY_LENGTH, INFINITY_LENGTH},
                {INFINITY_LENGTH, INFINITY_LENGTH, INFINITY_LENGTH, INFINITY_LENGTH, 1, 1},
                {INFINITY_LENGTH, INFINITY_LENGTH, INFINITY_LENGTH, 1, INFINITY_LENGTH, 1},
                {INFINITY_LENGTH, INFINITY_LENGTH, INFINITY_LENGTH, 1, 1, INFINITY_LENGTH},
        }
};

const Result split_expected_result = {
        6,
        3,
        { 1, 1, 0, INFINITY_LENGTH, INFINITY_LENGTH, INFINITY_LENGTH}
};

TEST(Dijkstra, SplitGraph) {
    ASSERT_TRUE(ResultsAreEQ(split_expected_result, Dijkstra(spilt_graph)));
}

TEST(FordBellman, SplitGraph) {
    ASSERT_TRUE(ResultsAreEQ(split_expected_result, FordBellman(spilt_graph)));
}

const Graph empty_graph = {
        0, 0, {},
};

const Result empty_expected_result = {
        0, 0, {},
};

TEST(Dijkstra, EmptyGraph) {
    ASSERT_TRUE(ResultsAreEQ(empty_expected_result, Dijkstra(empty_graph)));
}

TEST(FordBellman, EmptyGraph) {
    ASSERT_TRUE(ResultsAreEQ(empty_expected_result, FordBellman(empty_graph)));
}
