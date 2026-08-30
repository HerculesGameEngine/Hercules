#include "InputWindows.hpp"

#include "../../Engine/Input/Input.hpp"

#ifdef _WIN32

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

namespace Hercules {

static void updateKey(
    Key key,
    int virtualKey
)
{
    const bool pressed =
        (GetAsyncKeyState(virtualKey) & 0x8000) != 0;

    Input::setKeyState(
        key,
        pressed
    );
}

void InputWindows::initialize()
{
    Input::initialize();
}

void InputWindows::update()
{
    updateKey(Key::A, 'A');
    updateKey(Key::B, 'B');
    updateKey(Key::C, 'C');
    updateKey(Key::D, 'D');
    updateKey(Key::E, 'E');
    updateKey(Key::F, 'F');
    updateKey(Key::G, 'G');
    updateKey(Key::H, 'H');
    updateKey(Key::I, 'I');
    updateKey(Key::J, 'J');
    updateKey(Key::K, 'K');
    updateKey(Key::L, 'L');
    updateKey(Key::M, 'M');
    updateKey(Key::N, 'N');
    updateKey(Key::O, 'O');
    updateKey(Key::P, 'P');
    updateKey(Key::Q, 'Q');
    updateKey(Key::R, 'R');
    updateKey(Key::S, 'S');
    updateKey(Key::T, 'T');
    updateKey(Key::U, 'U');
    updateKey(Key::V, 'V');
    updateKey(Key::W, 'W');
    updateKey(Key::X, 'X');
    updateKey(Key::Y, 'Y');
    updateKey(Key::Z, 'Z');

    updateKey(Key::Up, VK_UP);
    updateKey(Key::Down, VK_DOWN);
    updateKey(Key::Left, VK_LEFT);
    updateKey(Key::Right, VK_RIGHT);

    updateKey(Key::Space, VK_SPACE);
    updateKey(Key::Enter, VK_RETURN);
    updateKey(Key::Escape, VK_ESCAPE);

    updateKey(Key::Shift, VK_SHIFT);
    updateKey(Key::Ctrl, VK_CONTROL);
    updateKey(Key::Alt, VK_MENU);
}

void InputWindows::shutdown()
{
}

}

#endif
