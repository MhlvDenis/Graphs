#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main(int argc, char *argv[]) {
    std::ifstream input_graph(argv[1]);
    json graph;
    input_graph >> graph;

    std::cout << graph["vertex_count"] << '\n';
    std::cout << graph["start"] << '\n';
    for (auto v : graph["matrix"]) {
        for (auto c : v) {
            std::cout << c << ' ';
        }
        std::cout << '\n';
    }
}