#pragma once

struct lua_State;

namespace Hercules {

class LuaBindings {
public:
    static void registerAll(lua_State* state);

private:
    static void registerEntity(lua_State* state);
    static void registerCamera(lua_State* state);
    static void registerInput(lua_State* state);
    static void registerTime(lua_State* state);
};

}
