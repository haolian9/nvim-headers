local ffi = require'ffi'

ffi.cdef([[
  void hello_from_zig();
]])

local zig = ffi.load("./zig-out/lib/libzig.so")

zig.hello_from_zig()
