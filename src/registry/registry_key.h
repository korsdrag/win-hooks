#pragma once

#include <basetsd.h>
#include <string_view>

#include <Windows.h>
#include <minwindef.h>

namespace win
{

template <class T>
struct RegistryKey
{
    std::string_view path;
    T                value;
};

}
