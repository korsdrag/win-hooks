#pragma once
#include <print>

#include <Windows.h>
#include <minwindef.h>
#include <vector>
#include <windef.h>

#include "utils/formatter.h"

#include "events/keyboard.h"
#include "hooks/hooks_base.h"

namespace win
{

auto CALLBACK keyboard_hook(int code, WPARAM wParam, LPARAM lParam) -> LRESULT
{
    if (wParam == WM_KEYDOWN /*|| wParam == WM_KEYUP */)
    {
        // std::println("code {}, wParam {}, lParam {:#04x}", code, wParam, lParam);
        auto *kbd_struct = reinterpret_cast<KBDLLHOOKSTRUCT *>(lParam);
        auto  v_key      = kbd_struct->vkCode;
        auto  scan_code  = kbd_struct->scanCode;

        BYTE lp_key_state[256]{};

        if (::GetKeyboardState(lp_key_state) == 0)
        {
            std::println("failed to get keyboard state: {}", ::GetLastError());
        }

        lp_key_state[16] = 0;
        lp_key_state[20] = 0;

        std::println(
            "{} {} ({}), {}", static_cast<win::KeyState>(wParam), v_key, static_cast<win::Key>(v_key), scan_code);

        // char result;
        // ::ToAscii(v_key, scan_code, lp_key_state, (LPWORD)&result, 0);

        // std::println("key pressed = {}", result);
    }

    return ::CallNextHookEx(hook, code, wParam, lParam);
}

auto hook_keyboard() -> void
{
    // auto hook = HHOOK{};
    hook = ::SetWindowsHookExA(WH_KEYBOARD_LL, &keyboard_hook, nullptr, 0);

    if (hook == nullptr)
    {
        std::println("failed to hook keyboard");
    }

    std::println("successfully hooked keyboard");

    // while (::GetMessage(nullptr, nullptr, 0, 0) != 0)
    // {
    // }
}

}
