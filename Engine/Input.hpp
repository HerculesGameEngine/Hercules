#pragma once

#include <string>

namespace Hercules {

enum class Key {
    Unknown,

    A, B, C, D, E, F, G, H, I, J, K, L, M,
    N, O, P, Q, R, S, T, U, V, W, X, Y, Z,

    Up,
    Down,
    Left,
    Right,

    Space,
    Enter,
    Escape,

    Shift,
    Ctrl,
    Alt
};

class Input {
public:
    static void initialize();
    static void update();

    static bool isKeyDown(Key key);
    static bool isKeyPressed(Key key);
    static bool isKeyReleased(Key key);

    static void setKeyState(
        Key key,
        bool down
    );

    static Key keyFromString(
        const std::string& key
    );
};

}
