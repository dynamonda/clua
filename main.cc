// main.cc

#include <stdio.h>

// extern C を付けないとエラー
extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

int main(){
    lua_State* lua_state = luaL_newstate();

    luaL_openlibs(lua_state);
    
    lua_close(lua_state);
    
    return 0;
}