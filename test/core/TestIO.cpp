#include <gtest/gtest.h>
#include <fstream>
#include <sstream>
#include <nlohmann/json.hpp>

#include <io/OutputProvider.hpp>

using namespace graphs::common;
using namespace graphs::io;

TEST(OutputProvider, JsonOutput) {
    const Result input_result = {
            5, 1, {0, 3, 1, 2, 4}
    };

    const nlohmann::json expected_json = {
            {"vertex_count", 5},
            {"start_vertex", 1},
            {"distances", {0, 3, 1, 2, 4}}
    };

    std::ofstream fout("ouput.json");
    OutputProvider(fout).output_as_json(input_result);
    fout.close();

    std::ifstream fin("ouput.json");
    nlohmann::json result_json;
    fin >> result_json;

    ASSERT_EQ(expected_json, result_json);
}

TEST(OutputProvider, StandardOutput) {
    {
        std::ofstream fout("expected_output");
        fout << "Vertex count: 5\n";
        fout << "Distances:\n";
        fout << "\tFrom 1 to 1: 0\n";
        fout << "\tFrom 1 to 2: 3\n";
        fout << "\tFrom 1 to 3: 1\n";
        fout << "\tFrom 1 to 4: 2\n";
        fout << "\tFrom 1 to 5: 4\n";
        fout.close();
    }

    {
        const Result result = {
                5, 1, {0, 3, 1, 2, 4}
        };
        std::ofstream fout("actual_output");
        OutputProvider(fout).output_as_standard(result);
        fout.close();
    }

    std::string expected_output;
    std::string actual_output;

    {
        std::ifstream fin("expected_output");
        std::stringstream buffer;
        buffer << fin.rdbuf();
        fin.close();
        expected_output = buffer.str();
    }

    {
        std::ifstream fin("actual_output");
        std::stringstream buffer;
        buffer << fin.rdbuf();
        fin.close();
        actual_output = buffer.str();
    }

    ASSERT_EQ(expected_output, actual_output);
}
