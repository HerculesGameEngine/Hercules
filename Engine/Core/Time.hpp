#pragma once

namespace Hercules {

class Time {
public:
    static void initialize();

    static void update(float deltaTime);

    static float deltaTime();
    static float time();

private:
    static float currentDeltaTime;
    static float elapsedTime;
};

}
