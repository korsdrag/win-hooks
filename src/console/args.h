#pragma once

#include <format>
#include <ranges>
#include <set>
#include <span>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

#include "utils/formatter.h"

using namespace std::literals;

namespace win
{

template <class T>
struct Arg
{
    std::string name;
    T           value;
};

// template <class T>
// using Arg = std::tuple<std::string, T>;

using Args = std::vector<Arg<std::string>>;
// using Args = std::set<Arg<std::string>>;
// using Args = std::unordered_map<std::string, Arg<std::string_view>>;

constexpr static auto parse_args(std::span<std::string> argv) -> Args
{
    auto args = Args{};

    [[maybe_unused]] const auto split = std::views::split(argv, " ");

    for (const auto &arg : argv)
    {
        // auto arg1 = Arg<std::string>{.name = "a", .value = "s"};
        args.emplace_back(Arg<std::string>{.name = "arg", .value = arg});
    }

    return args;
}
inline auto to_string(const Arg<std::string> &obj) -> std::string
{
    return std::format("{} {}", obj.name, obj.value);
}

}
