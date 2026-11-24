/* ed25519: signature verification for Lua (Monocypher). The check a package manager makes before trusting a signed index.
     ed25519.verify(signature, message, public_key) -> true | false   (signature 64 bytes, public key 32 bytes)
   Verification only: signing belongs to the publisher (openssl, signify...). Works on Lua 5.1 to 5.4 and LuaJIT. */
#include "lauxlib.h"
#include "lua.h"
#include "monocypher-ed25519.h"

static int l_verify(lua_State *L)
{
    size_t siglen, msglen, keylen;
    const char *sig = luaL_checklstring(L, 1, &siglen);
    const char *msg = luaL_checklstring(L, 2, &msglen);
    const char *key = luaL_checklstring(L, 3, &keylen);

    luaL_argcheck(L, siglen == 64, 1, "signature must be 64 bytes");
    luaL_argcheck(L, keylen == 32, 3, "public key must be 32 bytes");
    lua_pushboolean(L, crypto_ed25519_check((const uint8_t *)sig, (const uint8_t *)key, (const uint8_t *)msg, msglen) == 0);
    return 1;
}

int luaopen_ed25519(lua_State *L)
{
    lua_createtable(L, 0, 2);
    lua_pushcfunction(L, l_verify);
    lua_setfield(L, -2, "verify");
    lua_pushliteral(L, "ed25519 0.1 (Monocypher 4.0.3)");
    lua_setfield(L, -2, "_VERSION");
    return 1;
}
