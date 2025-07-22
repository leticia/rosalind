const std = @import("std");

fn rabbits(n: u8, k: u8) usize {
    var month: u8 = 1;
    var new: usize = 1;
    var old: usize = 0;

    while (month < n) : (month += 1) {
        const newborn = old * k;
        old += new;
        new = newborn;
    }

    return new + old;
}

test "compute number of rabbit pairs in n months with k newborn pairs" {
    try std.testing.expectEqual(8, rabbits(6, 1));
    try std.testing.expectEqual(19, rabbits(5, 3));
}

pub fn main() !void {
    var args = std.process.args();
    _ = args.next(); // ignore program name

    const arg1 = args.next() orelse @panic("no n arg");
    const arg2 = args.next() orelse @panic("no k arg");
    const n = try std.fmt.parseInt(u8, arg1, 10);
    const k = try std.fmt.parseInt(u8, arg2, 10);
    const r = rabbits(n, k);

    var out = std.io.getStdOut().writer();
    try out.print("{d}\n", .{r});
}
