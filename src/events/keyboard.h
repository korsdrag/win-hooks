#pragma once

#include <cstdint>
#include <span>

#include <Windows.h>
#include <minwindef.h>
#include <windef.h>
#include <winuser.h>

#include "events/key.h"
#include "utils/formatter.h"

namespace win
{

class Keyboard
{
    FORMATTABLE;

  public:
    Keyboard() = default;

    auto hook_input() -> void;
    auto send_input(std::span<Key> keys, std::uint32_t sleep_duration = 1000) const -> void;

  private:
    bool is_hooked_;
};

}
