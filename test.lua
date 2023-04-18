local ffi = require'ffi'

ffi.cdef([[
  void error_from_zig();
  void notify_from_zig(const char *msg);
]])

local zig = ffi.load("./zig-out/lib/libzig.so")

zig.error_from_zig()
zig.notify_from_zig('hello world!')
