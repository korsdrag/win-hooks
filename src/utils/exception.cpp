#include "exception.h"

#include <format>

// namespace
// {

auto Exception::stacktrace() const -> std::string
{
    return std::to_string(trace_);
}

auto Exception::what() const -> std::string
{
    return what_;
}

auto Exception::to_string() const -> std::string
{
    return std::format("{}\n{}", what(), stacktrace());
}
// }
