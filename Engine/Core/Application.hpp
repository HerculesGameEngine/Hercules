#pragma once

namespace Hercules {

class Application {
public:
    Application();
    ~Application();

    bool initialize();
    void run();
    void shutdown();
};

}
