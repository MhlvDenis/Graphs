#ifndef GRAPHS_OUTPUTPROVIDER_HPP
#define GRAPHS_OUTPUTPROVIDER_HPP

#include <common/Result.hpp>

#include <fstream>

namespace graphs::io {

    class OutputProvider {
    private:
        std::ostream& out;

    public:
        explicit OutputProvider(std::ostream& init_out);

        void output_as_standard(const common::Result& result) const;

        void output_as_json(const common::Result& result) const;
    };

}

#endif //GRAPHS_OUTPUTPROVIDER_HPP
