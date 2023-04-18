const std = @import("std");
const testing = std.testing;

const h = @cImport(@cInclude("nvim.h"));

export fn error_from_zig() void {
    const data = "hello";
    const str = h.String{ .data = data, .size = data.len };
    h.nvim_err_writeln(str);
}

const LogLevel = enum(h.Integer) { trace, debug, info, warn, @"error", off };

export fn notify_from_zig(cmsg: [*:0]const u8) void {
    const msg = std.mem.span(cmsg);
    const str = h.String{ .data = msg.ptr, .size = msg.len };
    const opts: h.Dictionary = .{ .size = 0, .capacity = 0, .items = 0 };
    var err: h.Error = undefined;
    const result = h.nvim_notify(str, @enumToInt(LogLevel.info), opts, &err);
    std.debug.assert(result.type == h.kObjectTypeNil);
}
