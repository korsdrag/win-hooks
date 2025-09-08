#pragma once
#include <print>

#include <Windows.h>
#include <minwindef.h>
#include <vector>
#include <windef.h>
#include <winuser.h>

#include "utils/formatter.h"

#include "events/mouse.h"
#include "hooks/hooks_base.h"

namespace win
{
auto CALLBACK mouse_hook(int code, WPARAM wParam, LPARAM lParam) -> LRESULT
{
    if (wParam != WM_MOUSEMOVE /*|| wParam == WM_KEYUP */)
    {
        // std::println("code {}, wParam {}, lParam {:#04x}", code, wParam, lParam);
        auto *ms_struct = reinterpret_cast<MSLLHOOKSTRUCT *>(lParam);
        auto  point     = ms_struct->pt;
        auto  time      = ms_struct->time;
        auto  data      = ms_struct->mouseData;

        // std::vector<BYTE> lp_key_state{};

        // if (::GetKeyboardState(lp_key_state.data()) == 0)
        // {
        //     std::println("failed to get keyboard state: {}", ::GetLastError());
        // }

        // lp_key_state[16] = 0;
        // lp_key_state[20] = 0;

        std::println("{} {}x{} ({}), {}", static_cast<MouseEvent>(wParam), point.x, point.y, time, data);

        // char result;
        // ::ToAscii(v_key, scan_code, lp_key_state, (LPWORD)&result, 0);

        // std::println("key pressed = {}", result);
    }

    return ::CallNextHookEx(hook, code, wParam, lParam);
}

auto hook_mouse() -> void
{
    // auto hook = HHOOK{};
    hook = ::SetWindowsHookExA(WH_MOUSE_LL, &mouse_hook, nullptr, 0);

    if (hook == nullptr)
    {
        std::println("failed to hook mouse");
    }

    std::println("successfully hooked mouse");

    // while (::GetMessage(nullptr, nullptr, 0, 0) != 0)
    // {
    // }
}

}
