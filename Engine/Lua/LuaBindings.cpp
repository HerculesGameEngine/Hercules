#include "LuaBindings.hpp"

#include "../Input/Input.hpp"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace Hercules {

// ============================================================
// ENTITY
// ============================================================

static int lua_Entity(lua_State* state)
{
    const char* name =
        luaL_optstring(
            state,
            1,
            "GameObject"
        );

    // TODO:
    // Conectar futuramente ao Scene/GameObject.
    (void)name;

    lua_pushstring(
        state,
        "Entity criada"
    );

    return 1;
}

// ============================================================
// CAMERA
// ============================================================

static int lua_Camera(lua_State* state)
{
    // TODO:
    // Conectar futuramente ao sistema de Camera.

    lua_pushstring(
        state,
        "Camera criada"
    );

    return 1;
}

// ============================================================
// INPUT - isKeyDown
// ============================================================

static int lua_InputIsKeyDown(
    lua_State* state
)
{
    const char* keyName =
        luaL_checkstring(
            state,
            1
        );

    Hercules::Key key =
        Hercules::Input::keyFromString(
            keyName
        );

    bool down =
        Hercules::Input::isKeyDown(
            key
        );

    lua_pushboolean(
        state,
        down
    );

    return 1;
}

// ============================================================
// INPUT - isKeyPressed
// ============================================================

static int lua_InputIsKeyPressed(
    lua_State* state
)
{
    const char* keyName =
        luaL_checkstring(
            state,
            1
        );

    Hercules::Key key =
        Hercules::Input::keyFromString(
            keyName
        );

    bool pressed =
        Hercules::Input::isKeyPressed(
            key
        );

    lua_pushboolean(
        state,
        pressed
    );

    return 1;
}

// ============================================================
// INPUT - isKeyReleased
// ============================================================

static int lua_InputIsKeyReleased(
    lua_State* state
)
{
    const char* keyName =
        luaL_checkstring(
            state,
            1
        );

    Hercules::Key key =
        Hercules::Input::keyFromString(
            keyName
        );

    bool released =
        Hercules::Input::isKeyReleased(
            key
        );

    lua_pushboolean(
        state,
        released
    );

    return 1;
}

// ============================================================
// TIME
// ============================================================

static int lua_TimeDeltaTime(
    lua_State* state
)
{
    // TODO:
    // Conectar ao Hercules::Time.

    lua_pushnumber(
        state,
        0.016
    );

    return 1;
}

// ============================================================
// REGISTER ENTITY
// ============================================================

void LuaBindings::registerEntity(
    lua_State* state
)
{
    lua_pushcfunction(
        state,
        lua_Entity
    );

    lua_setglobal(
        state,
        "Entity"
    );
}

// ============================================================
// REGISTER CAMERA
// ============================================================

void LuaBindings::registerCamera(
    lua_State* state
)
{
    lua_pushcfunction(
        state,
        lua_Camera
    );

    lua_setglobal(
        state,
        "Camera"
    );
}

// ============================================================
// REGISTER INPUT
// ============================================================

void LuaBindings::registerInput(
    lua_State* state
)
{
    lua_newtable(state);

    // Input.isKeyDown()

    lua_pushcfunction(
        state,
        lua_InputIsKeyDown
    );

    lua_setfield(
        state,
        -2,
        "isKeyDown"
    );

    // Input.isKeyPressed()

    lua_pushcfunction(
        state,
        lua_InputIsKeyPressed
    );

    lua_setfield(
        state,
        -2,
        "isKeyPressed"
    );

    // Input.isKeyReleased()

    lua_pushcfunction(
        state,
        lua_InputIsKeyReleased
    );

    lua_setfield(
        state,
        -2,
        "isKeyReleased"
    );

    lua_setglobal(
        state,
        "Input"
    );
}

// ============================================================
// REGISTER TIME
// ============================================================

void LuaBindings::registerTime(
    lua_State* state
)
{
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

// ============================================================
// REGISTER ALL
// ============================================================

void LuaBindings::registerAll(
    lua_State* state
)
{
    registerEntity(state);
    registerCamera(state);
    registerInput(state);
    registerTime(state);
}

}
