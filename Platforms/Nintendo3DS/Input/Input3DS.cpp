#include "Input3DS.hpp"

#include "../../Engine/Input/Input.hpp"

#include <3ds.h>

namespace Hercules {

void Input3DS::initialize() {
    Input::initialize();
}

void Input3DS::update() {

    /*
     * libctru lê os controles.
     */
    hidScanInput();

    u32 held = hidKeysHeld();

    Input::setKeyState(
        Key::A,
        (held & KEY_A) != 0
    );

    Input::setKeyState(
        Key::B,
        (held & KEY_B) != 0
    );

    Input::setKeyState(
        Key::X,
        (held & KEY_X) != 0
    );

    Input::setKeyState(
        Key::Y,
        (held & KEY_Y) != 0
    );

    Input::setKeyState(
        Key::L,
        (held & KEY_L) != 0
    );

    Input::setKeyState(
        Key::R,
        (held & KEY_R) != 0
    );

    Input::setKeyState(
        Key::Up,
        (held & KEY_UP) != 0
    );

    Input::setKeyState(
        Key::Down,
        (held & KEY_DOWN) != 0
    );

    Input::setKeyState(
        Key::Left,
        (held & KEY_LEFT) != 0
    );

    Input::setKeyState(
        Key::Right,
        (held & KEY_RIGHT) != 0
    );

    Input::setKeyState(
        Key::Start,
        (held & KEY_START) != 0
    );

    Input::setKeyState(
        Key::Select,
        (held & KEY_SELECT) != 0
    );
}

void Input3DS::shutdown() {
}

}
