const std = @import("std");

fn hammingDistance(s: []const u8, t: []const u8) usize {
    std.debug.assert(s.len == t.len);
    var distance: usize = 0;
    for (s, t) |a, b| {
        if (a != b) distance += 1;
    }
    return distance;
}

test "computes the hamming distance between two dna strings" {
    const s = "GAGCCTACTAACGGGAT";
    const t = "CATCGTAATGACGGCCT";
    try std.testing.expectEqual(7, hammingDistance(s, t));
}

pub fn main() !void {
    var args = std.process.args();
    _ = args.next(); // ignore program name

    const path = args.next() orelse @panic("no input file");
    var file = try std.fs.cwd().openFile(path, .{});
    defer file.close();

    var reader = file.reader();
    var s_buf: [2000]u8 = undefined;
    const s = try reader.readUntilDelimiter(&s_buf, '\n');

    var t_buf: [2000]u8 = undefined;
    const t = try reader.readUntilDelimiterOrEof(&t_buf, '\n');

    var out = std.io.getStdOut().writer();
    try out.print("{d}\n", .{hammingDistance(s, t.?)});
}
