// main.cc

#include <stdio.h>
#include <iostream>

// extern C を付けないとエラー
extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

int main(){
    lua_State* lua_state = luaL_newstate();

    luaL_openlibs(lua_state);
    
    if (int error = luaL_dofile(lua_state, "hello.lua") != 0){
        std::cout << "\n[C++]: ERROR(" << error << "): Problem with lua "
                  << "script file!\n\n" << std::endl;
    }

    lua_close(lua_state);
    
    return 0;
}