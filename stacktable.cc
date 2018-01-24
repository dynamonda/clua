// stacktable.cc

#include <iostream>
#include <string>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

int main(){
    lua_State *pL = luaL_newstate();
    lua_settop(pL, 0);

    luaL_dofile(pL, "stacktable.lua");

    lua_getglobal(pL, "simple_table");

    if (!lua_istable(pL, 1)){
        std::cout << "\n[C++]: ERROR: simple_table is not a valid table\n";
    }else{
        lua_pushstring(pL, "name");
        lua_gettable(pL, -2);
        if(!lua_isstring(pL, -1)){
            std::cout << "\n[C++]: ERROR: invalid type\n";
        }
        std::string name = lua_tostring(pL, -1);
        std::cout << "name: " << name << '\n';
        lua_pop(pL, 1);
    }

    lua_close(pL);
    return 0;
}