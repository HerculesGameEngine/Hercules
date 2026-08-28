#pragma once

#include <string>

struct lua_State;

namespace Hercules {

class LuaEngine {
public:
    LuaEngine();
    ~LuaEngine();

    bool initialize();
    void shutdown();

    bool executeFile(const std::string& path);
    bool executeString(const std::string& code);

    lua_State* getState();

private:
    lua_State* state;
};

}
