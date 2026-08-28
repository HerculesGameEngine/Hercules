#include "Time.hpp"

namespace Hercules {

float Time::currentDeltaTime = 0.0f;
float Time::elapsedTime = 0.0f;

void Time::initialize() {
    currentDeltaTime = 0.0f;
    elapsedTime = 0.0f;
}

void Time::update(float deltaTime) {
    currentDeltaTime = deltaTime;
    elapsedTime += deltaTime;
}

float Time::deltaTime() {
    return currentDeltaTime;
}

float Time::time() {
    return elapsedTime;
}

}
