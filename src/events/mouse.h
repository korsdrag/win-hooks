#pragma once

#include <format>
#include <string>

#include <Windows.h>
#include <winuser.h>

#include "utils/formatter.h"

namespace win
{

/**
 * Enumeration of keyboard keys. Incomplete.
 */
enum class MouseEvent
{
    MOUSE_MOVE        = WM_MOUSEMOVE,
    LEFT_BUTTON_DOWN  = WM_LBUTTONDOWN,
    LEFT_BUTTON_UP    = WM_LBUTTONUP,
    RIGHT_BUTTON_DOWN = WM_RBUTTONDOWN,
    RIGHT_BUTTON_UP   = WM_RBUTTONDOWN,
    MOUSEWHEEL        = WM_MOUSEWHEEL,
};

inline auto to_string(const MouseEvent &obj) -> std::string
{
    switch (obj)
    {
        using enum MouseEvent;
        case MOUSE_MOVE:        return "MOUSE_MOVE"; break;
        case LEFT_BUTTON_DOWN:  return "LEFT_BUTTON_DOWN"; break;
        case LEFT_BUTTON_UP:    return "LEFT_BUTTON_UP"; break;
        case RIGHT_BUTTON_DOWN: return "RIGHT_BUTTON_DOWN"; break;
        case MOUSEWHEEL:        return "MOUSEWHEEL"; break;
        default:                return "???"; break;
    }
}

}
