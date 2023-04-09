#ifndef GRAPHS_JSONBUILDER_HPP
#define GRAPHS_JSONBUILDER_HPP

#include "../common/Result.hpp"

#include <nlohmann/json.hpp>

namespace graphs::json {

    class JsonBuilder {
    private:
        common::Result result;

    public:
        explicit JsonBuilder(const common::Result& init_result);

        [[nodiscard]] nlohmann::json build() const;
    };

}

#endif //GRAPHS_JSONBUILDER_HPP
