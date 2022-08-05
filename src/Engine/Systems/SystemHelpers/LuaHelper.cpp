#include <iostream>
#include "LuaHelper.hpp"


void print_error(lua_State* state) {
    // The error message is on top of the stack.
    // Fetch it, print it and then pop it off the stack.
    const char* message = lua_tostring(state, -1);
    puts(message);
    lua_pop(state, 1);
}

void LuaHelper::execute(const char* filename, const char* function)
{
    lua_State *state = luaL_newstate();
    luaL_openlibs(state);

    int result = luaL_loadfile(state, filename);
    if ( result != LUA_OK ) {
        print_error(state);
        return;
    }

    result = lua_pcall(state, 0, LUA_MULTRET, 0);
    if ( result != LUA_OK ) {
        print_error(state);
        return;
    }

    if(function != nullptr){
        lua_getglobal(state,function);
        if(lua_isfunction(state, -1) )
        {
            // push function arguments into stack
            lua_pushnumber(state, 5.0);
            lua_pushnumber(state, 6.0);
            lua_pcall(state,2,1,0);
            if (!lua_isnil(state, -1))
            {
                lua_pop(state,1);
            }
        }
    }

    lua_close(state);
}


