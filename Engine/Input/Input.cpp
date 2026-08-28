#include "Input.hpp"

#include <unordered_map>
#include <algorithm>
#include <cctype>

namespace Hercules {

static std::unordered_map<int, bool> currentKeys;
static std::unordered_map<int, bool> previousKeys;

void Input::initialize() {

    currentKeys.clear();
    previousKeys.clear();
}

void Input::update() {

    previousKeys = currentKeys;
}

bool Input::isKeyDown(Key key) {

    return currentKeys[
        static_cast<int>(key)
    ];
}

bool Input::isKeyPressed(Key key) {

    int k = static_cast<int>(key);

    return currentKeys[k] &&
           !previousKeys[k];
}

bool Input::isKeyReleased(Key key) {

    int k = static_cast<int>(key);

    return !currentKeys[k] &&
           previousKeys[k];
}

void Input::setKeyState(
    Key key,
    bool down
) {

    currentKeys[
        static_cast<int>(key)
    ] = down;
}

Key Input::keyFromString(
    const std::string& key
) {

    std::string value = key;

    std::transform(
        value.begin(),
        value.end(),
        value.begin(),
        [](unsigned char c) {
            return static_cast<char>(
                std::toupper(c)
            );
        }
    );

    if (value == "A") return Key::A;
    if (value == "B") return Key::B;
    if (value == "C") return Key::C;
    if (value == "D") return Key::D;
    if (value == "E") return Key::E;
    if (value == "F") return Key::F;
    if (value == "G") return Key::G;
    if (value == "H") return Key::H;
    if (value == "I") return Key::I;
    if (value == "J") return Key::J;
    if (value == "K") return Key::K;
    if (value == "L") return Key::L;
    if (value == "M") return Key::M;
    if (value == "N") return Key::N;
    if (value == "O") return Key::O;
    if (value == "P") return Key::P;
    if (value == "Q") return Key::Q;
    if (value == "R") return Key::R;
    if (value == "S") return Key::S;
    if (value == "T") return Key::T;
    if (value == "U") return Key::U;
    if (value == "V") return Key::V;
    if (value == "W") return Key::W;
    if (value == "X") return Key::X;
    if (value == "Y") return Key::Y;
    if (value == "Z") return Key::Z;

    if (value == "UP") return Key::Up;
    if (value == "DOWN") return Key::Down;
    if (value == "LEFT") return Key::Left;
    if (value == "RIGHT") return Key::Right;

    if (value == "SPACE") return Key::Space;
    if (value == "ENTER") return Key::Enter;
    if (value == "ESCAPE") return Key::Escape;

    if (value == "SHIFT") return Key::Shift;
    if (value == "CTRL") return Key::Ctrl;
    if (value == "ALT") return Key::Alt;

    return Key::Unknown;
}

}
