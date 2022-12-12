const std = @import("std");
const testing = std.testing;

const h = @cImport(@cInclude("nvim.h"));

export fn hello_from_zig() void {
    var data = "hello".*;
    const str = h.String{ .data = &data, .size = 5 };
    h.nvim_err_writeln(str);
}
