const std = @import("std");

fn transcribeToRNA(sequence: []u8) void {
    for (sequence) |*base| {
        if (base.* == 'T') {
            base.* = 'U';
        }
    }
}

test "transcribe DNA to RNA" {
    var sequence: [23]u8 = undefined;
    std.mem.copyForwards(u8, &sequence, "GATGGAACTTGACTACGTAAATT");

    transcribeToRNA(&sequence);
    try std.testing.expectEqualStrings("GAUGGAACUUGACUACGUAAAUU", &sequence);
}

pub fn main() !void {
    var args = std.process.args();
    _ = args.next(); // ignore program name

    const path = args.next() orelse @panic("no input file");
    var file = try std.fs.cwd().openFile(path, .{});
    defer file.close();

    var sequence: [1000]u8 = undefined;
    const seq_size = try file.readAll(&sequence);
    transcribeToRNA(sequence[0..seq_size]);

    var out = std.io.getStdOut().writer();
    try out.print("{s}\n", .{sequence[0..seq_size]});
}
