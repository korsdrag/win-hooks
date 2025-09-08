#include "console/console.h"

#include <cstdio>
#include <print>
#include <string_view>
#include <utility>

#include <Windows.h>
#include <consoleapi2.h>
#include <minwindef.h>
#include <windef.h>
#include <winuser.h>

#include "console/args.h"
#include "utils/formatter.h"

namespace win
{
Console::Console(std::string_view title, Args &args)
    : title_{title}
    , args_{std::move(args)}
{
    // std::cout << "\x1b]0;TEST \x07" << '\n';
    // std::println("\x1b]0;TEST2 \x07");
    std::println("\x1b]0;TEST2 \x07");
    ::SetConsoleTitle("PLEASE");
    // std::println("\x1b]2; {} \x1b \x5c", title_);
    std::println("{}", title_);
    // std::println("\x1b]0;{}", title_);
    for (const auto &arg : args_)
    {
        std::println("{}", arg);
    }
};

}
