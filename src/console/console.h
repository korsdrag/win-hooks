#pragma once

#include <string_view>

#include "console/args.h"
#include "utils/formatter.h"

namespace win
{

class Console
{
    FORMATTABLE;

  public:
    Console(std::string_view title, Args &args);

    auto print_usage() const -> void;

    template <class T>
    auto read_input() -> T
    {
        auto parsed_input = T{};
        return parsed_input;
    }

  private:
    std::string_view title_;
    const Args       args_;
};

}
