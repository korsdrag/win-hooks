#pragma once

#include <cstdint>
#include <stacktrace>
#include <stdexcept>

#include <Windows.h>
#include <string>
#include <winnt.h>

namespace win
{

class RegistryException : public std::runtime_error
{
  public:
    RegistryException(const std::string &message, std::int32_t error_code);

    [[nodiscard]] auto error_code() const noexcept -> std::uint32_t;
    [[nodiscard]] auto to_string() const -> std::string;

  private:
    LONG            m_error_code;
    std::string     m_win32_error;
    std::stacktrace m_stacktrace;
};

}
