#include "Engine.hpp"

namespace Hercules {

Engine::Engine()
    : running(false) {
}

Engine::~Engine() {
    shutdown();
}

bool Engine::initialize() {
    running = true;
    return true;
}

void Engine::run() {
    while (running) {
        // Game loop da Hércules
    }
}

void Engine::shutdown() {
    running = false;
}

bool Engine::isRunning() const {
    return running;
}

void Engine::quit() {
    running = false;
}

}
