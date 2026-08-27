#pragma once

namespace Hercules {

class Engine {
public:
    Engine();
    ~Engine();

    bool initialize();
    void run();
    void shutdown();

    bool isRunning() const;
    void quit();

private:
    bool running;
};

}
