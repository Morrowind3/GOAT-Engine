#ifndef GOAT_ENGINE_LUAHELPER_HPP
#define GOAT_ENGINE_LUAHELPER_HPP

#include "../Lua/include/lua.hpp"

class LuaHelper {
public:
    static void execute(const char* filename);
};


#endif //GOAT_ENGINE_LUAHELPER_HPP
