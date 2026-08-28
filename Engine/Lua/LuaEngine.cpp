#include "LuaEngine.hpp"
#include "LuaBindings.hpp"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

namespace Hercules {

LuaEngine::LuaEngine()
    : state(nullptr) {
}

LuaEngine::~LuaEngine() {
    shutdown();
}

bool LuaEngine::initialize() {

    state = luaL_newstate();

    if (!state) {
        return false;
    }

    luaL_openlibs(state);

    LuaBindings::registerAll(state);

    return true;
}

void LuaEngine::shutdown() {

    if (state) {
        lua_close(state);
        state = nullptr;
    }
}

bool LuaEngine::executeFile(
    const std::string& path
) {

    if (!state) {
        return false;
    }

    if (luaL_dofile(
            state,
            path.c_str()) != LUA_OK) {

        const char* error =
            lua_tostring(state, -1);

        (void)error;

        lua_pop(state, 1);

        return false;
    }

    return true;
}

bool LuaEngine::executeString(
    const std::string& code
) {

    if (!state) {
        return false;
    }

    if (luaL_dostring(
            state,
            code.c_str()) != LUA_OK) {

        lua_pop(state, 1);

        return false;
    }

    return true;
}

lua_State* LuaEngine::getState() {
    return state;
}

}
