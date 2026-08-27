#include "Application.hpp"
#include "Engine.hpp"

namespace Hercules {

static Engine engine;

Application::Application() {
}

Application::~Application() {
    shutdown();
}

bool Application::initialize() {
    return engine.initialize();
}

void Application::run() {
    engine.run();
}

void Application::shutdown() {
    engine.shutdown();
}

}
