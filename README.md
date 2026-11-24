# ed25519

Ed25519 signature verification for Lua 5.1 to 5.4 and LuaJIT, built on [Monocypher](https://monocypher.org) (vendored).
Small (about 57 KB of code), no dependencies, no allocation: it runs on microcontrollers.

```lua
local ed25519 = require("ed25519")
ed25519.verify(signature, message, public_key)   -- 64-byte signature, 32-byte public key -> true | false
```

Verification only; sign with whatever you already use (openssl, signify, ...). `lua test.lua` checks it against RFC 8032 vectors.

License: MIT for the binding; Monocypher is BSD-2-Clause or CC0 (see `monocypher.c`).
