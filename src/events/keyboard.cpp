#include "events/keyboard.h"

#include <chrono>
#include <print>
#include <span>
#include <thread>
#include <vector>

#include <Windows.h>
#include <errhandlingapi.h>
#include <minwindef.h>
#include <windef.h>
#include <winuser.h>

#include "events/key.h"

namespace
{
auto          h_hook = HHOOK{};
auto CALLBACK hook_function(int code, WPARAM wParam, LPARAM lParam) -> LRESULT
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

    return ::CallNextHookEx(h_hook, code, wParam, lParam);
}

}

namespace win
{

auto Keyboard::hook_input() -> void
{
    // auto hook = HHOOK{};
    h_hook = ::SetWindowsHookExA(WH_KEYBOARD_LL, &hook_function, nullptr, 0);

    if (h_hook == nullptr)
    {
        std::println("failed to hook keyboard");
    }

    std::println("successfully hooked keyboard");

    // while (::GetMessage(nullptr, nullptr, 0, 0) != 0)
    // {
    // }
    is_hooked_ = true;
}

auto Keyboard::send_input([[maybe_unused]] std::span<Key> keys, [[maybe_unused]] std::uint32_t sleep_duration) const
    -> void
{
    std::println("sending keys to keyboard");
    std::vector<::INPUT> inputs{};
    inputs.resize(6);
    // inputs.emplace_back(
    //     INPUT{
    //         .type = INPUT_KEYBOARD,
    //         .ki   = {.wVk = VK_MENU, .wScan = 0, .dwFlags = 0x0000, .time = {}, .dwExtraInfo = {}}});

    // for (auto &key : inputs)
    // {
    //     key.type   = INPUT_KEYBOARD;
    //     key.ki.wVk = VK_MENU;
    // }
    inputs.at(0).type   = INPUT_KEYBOARD;
    inputs.at(0).ki.wVk = VK_MENU;

    inputs.at(1).type   = INPUT_KEYBOARD;
    inputs.at(1).ki.wVk = VK_LSHIFT;

    inputs.at(2).type   = INPUT_KEYBOARD;
    inputs.at(2).ki.wVk = 'D';

    inputs.at(3).type       = INPUT_KEYBOARD;
    inputs.at(3).ki.wVk     = VK_MENU;
    inputs.at(3).ki.dwFlags = KEYEVENTF_KEYUP;

    inputs.at(4).type       = INPUT_KEYBOARD;
    inputs.at(4).ki.wVk     = VK_LSHIFT;
    inputs.at(4).ki.dwFlags = KEYEVENTF_KEYUP;

    inputs.at(5).type       = INPUT_KEYBOARD;
    inputs.at(5).ki.wVk     = 'D';
    inputs.at(5).ki.dwFlags = KEYEVENTF_KEYUP;

    ::SendInput(6, inputs.data(), sizeof(::INPUT));

    std::this_thread::sleep_for(std::chrono::milliseconds(sleep_duration));
}

}
