#pragma once

#include <string_view>

#include <Windows.h>
#include <minwindef.h>
#include <winreg.h>

#include "registry/registry_key.h"
#include "utils/error.h"

namespace win
{

class Registry
{
  public:
    Registry(std::string_view hive);

    template <class T>
    auto get_value() -> RegistryKey<T>
    {
        // HKEY s{};
        // ::RegGetValueA(
        //     HKEY hkey, LPCSTR lpSubKey, LPCSTR lpValue, DWORD dwFlags, LPDWORD pdwType, PVOID pvData, LPDWORD
        //     pcbData)
    }

  private:
    std::string_view m_hive;
};

}
