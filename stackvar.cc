// stackvar.cc

#include <iostream>
#include <string>

// extern C を付けないとエラー
extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

int main(){
    lua_State *pL = luaL_newstate();

    lua_settop(pL, 0);

    luaL_dofile(pL, "stackvar.lua");

    lua_getglobal(pL, "age");
    lua_getglobal(pL, "name");

    if (!lua_isnumber(pL, 1) || !lua_isstring(pL, 2)){
        std::cout << "\n[C++]: ERROR: Invalid type!\n";
    }

    std::string name = lua_tostring(pL, 2);
    int age = (int)lua_tonumber(pL, 1);

    std::cout << "name: " << name << "\nage: " << age << '\n';

    lua_close(pL);
    return 0;
}