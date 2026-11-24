rockspec_format = "3.0"
package = "ed25519"
version = "0.1-1"
source = { url = "git+https://github.com/tibocub/lua-ed25519.git", tag = "v0.1" }
description = {
  summary = "Ed25519 signature verification (Monocypher), small enough for microcontrollers",
  detailed = "ed25519.verify(signature, message, public_key) -> boolean. Vendors Monocypher 4.0.3 (BSD-2-Clause / CC0).",
  license = "MIT",
}
dependencies = { "lua >= 5.1" }
build = {
  type = "builtin",
  modules = { ed25519 = { sources = { "ed25519.c", "monocypher.c", "monocypher-ed25519.c" } } },
}
