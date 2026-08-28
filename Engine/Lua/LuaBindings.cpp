#include "LuaBindings.hpp"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace Hercules {

// --------------------------------------------------
// Entity
// --------------------------------------------------

static int lua_Entity(lua_State* state) {

    const char* name =
        luaL_optstring(
            state,
            1,
            "GameObject"
        );

    // Será conectado ao Scene/GameObject.
    (void)name;

    lua_pushstring(
        state,
        "Entity criada"
    );

    return 1;
}

// --------------------------------------------------
// Camera
// --------------------------------------------------

static int lua_Camera(lua_State* state) {

    lua_pushstring(
        state,
        "Camera criada"
    );

    return 1;
}

// --------------------------------------------------
// Input
// --------------------------------------------------

static int lua_InputIsKeyDown(
    lua_State* state
) {

    const char* key =
        luaL_checkstring(state, 1);

    // Backend de Input será conectado depois.
    (void)key;

    lua_pushboolean(state, false);

    return 1;
}

// --------------------------------------------------
// Time
// --------------------------------------------------

static int lua_TimeDeltaTime(
    lua_State* state
) {

    // Será conectado ao Hercules::Time.
    lua_pushnumber(state, 0.016f);

    return 1;
}

// --------------------------------------------------
// Registration
// --------------------------------------------------

void LuaBindings::registerEntity(
    lua_State* state
) {

    lua_pushcfunction(
        state,
        lua_Entity
    );

    lua_setglobal(
        state,
        "Entity"
    );
}

void LuaBindings::registerCamera(
    lua_State* state
) {

    lua_pushcfunction(
        state,
        lua_Camera
    );

    lua_setglobal(
        state,
        "Camera"
    );
}

void LuaBindings::registerInput(
    lua_State* state
) {

    lua_newtable(state);

    lua_pushcfunction(
        state,
        lua_InputIsKeyDown
    );

    lua_setfield(
        state,
        -2,
        "isKeyDown"
    );

    lua_setglobal(
        state,
        "Input"
    );
}

void LuaBindings::registerTime(
    lua_State* state
) {

    lua_newtable(state);

    lua_pushcfunction(
        state,
        lua_TimeDeltaTime
    );

    lua_setfield(
        state,
        -2,
        "deltaTime"
    );

    lua_setglobal(
        state,
        "Time"
    );
}

void LuaBindings::registerAll(
    lua_State* state
) {

    registerEntity(state);
    registerCamera(state);
    registerInput(state);
    registerTime(state);
}

}
