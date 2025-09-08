#include "registry/registry_exception.h"

#include <cstdint>
#include <errhandlingapi.h>
#include <format>
#include <stacktrace>
#include <stdexcept>

#include <Windows.h>
#include <string>
#include <winnt.h>

namespace win
{

RegistryException::RegistryException(const std::string &message, std::int32_t error_code)
    : std::runtime_error{message}
    , m_error_code{error_code}
    , m_win32_error{"s"}
    , m_stacktrace{std::stacktrace::current(1)}
{
}

auto RegistryException::error_code() const noexcept -> std::uint32_t
{
    return m_error_code;
}

auto RegistryException::to_string() const -> std::string
{
    return std::format("({}) {}\n{}", m_error_code, m_win32_error, m_stacktrace);
}

}
