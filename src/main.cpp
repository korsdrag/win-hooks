#include <print>
// #include <vector>

#include <Windows.h>
#include <minwindef.h>
#include <windef.h>
#include <winuser.h>

// #include "auto_release.h"
#include "key.h"

auto hook = HHOOK{nullptr};

auto CALLBACK keyboard_hook([[maybe_unused]] int code, WPARAM wParam, LPARAM lParam) -> LRESULT
{
    if (wParam == WM_KEYDOWN /*|| wParam == WM_KEYUP */)
    {
        // std::println("code {}, wParam {}, lParam {:#04x}", code, wParam, lParam);
        auto *kbd_struct = reinterpret_cast<KBDLLHOOKSTRUCT *>(lParam);
        auto  v_key      = kbd_struct->vkCode;
        auto  scan_code  = kbd_struct->scanCode;

        BYTE lp_key_state[256];

        if (::GetKeyboardState(lp_key_state) == 0)
        {
            std::println("failed to get keyboard state: {}", ::GetLastError());
        }

        lp_key_state[16] = 0;
        lp_key_state[20] = 0;

        std::println(
            "{} {} ({}), {}",
            to_string(static_cast<KeyState>(wParam)),
            v_key,
            to_string(static_cast<Key>(v_key)),
            scan_code);

        // char result;
        // ::ToAscii(v_key, scan_code, lp_key_state, (LPWORD)&result, 0);

        // std::println("key pressed = {}", result);
    }

    return ::CallNextHookEx(hook, code, wParam, lParam);
}

auto main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) -> int
{
    // auto hook = HHOOK{};
    hook = ::SetWindowsHookExA(WH_KEYBOARD_LL, &keyboard_hook, nullptr, 0);

    if (hook == nullptr)
    {
        std::println("failed to hook keyboard");
    }

    std::println("successfully hooked keyboard");

    while (::GetMessage(nullptr, nullptr, 0, 0) != 0)
    {
    }
}
