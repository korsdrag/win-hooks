#include <print>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

#include <Windows.h>
#include <minwindef.h>
#include <windef.h>
#include <winuser.h>

#include "console/args.h"
#include "console/console.h"

auto main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) -> int
{
    try
    {
        std::println("initializing...");
        // statements

        // auto args_str = std::vector<std::string>{};

        // args_str.emplace_back(argv[0]);

        // for (int i = 0; i < argc; i++)
        // {
        //     std::println("{}", argv[i]);
        // }
        // auto       args_str2 = std::vector<std::string>{"hello", "hello pls"};
        auto       args_str = std::vector<std::string>{argv, argv + argc};
        auto       args     = win::parse_args(args_str);
        const auto console  = win::Console{"Windows hacking", args};
        // for ([[maybe_unused]] auto idx : std::views::iota(0, 1))
        // {
        //     send_input({}, {});
        // }
        // auto kbd = win::Keyboard{};
        // kbd.hook_input();
        // // win::hook_keyboard();
        // win::hook_mouse();

        // while (::GetMessage(nullptr, nullptr, 0, 0) != 0)
        // {
        // }
        std::println("exiting...");
    }
    catch (std::runtime_error &ex)
    {
        std::println("{}", ex.what());
    }
}
