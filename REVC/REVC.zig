const std = @import("std");

fn reverseComplement(sequence: []u8) void {
    var i: usize = 0;
    var j: usize = sequence.len - 1;

    while (i <= j) : ({
        i += 1;
        j -= 1;
    }) {
        const a = sequence[i];
        const b = sequence[j];
        sequence[i] = complementOf(b);
        sequence[j] = complementOf(a);
    }
}

fn complementOf(base: u8) u8 {
    return switch (base) {
        'A' => 'T',
        'T' => 'A',
        'C' => 'G',
        'G' => 'C',
        else => base, // ignore \n or anything else
    };
}

test "reverse complement of a DNA sequence" {
    var sequence: [10]u8 = undefined;
    std.mem.copyForwards(u8, &sequence, "AAAACCCGGT");

    reverseComplement(&sequence);
    try std.testing.expectEqualStrings("ACCGGGTTTT", &sequence);
}

pub fn main() !void {
    var args = std.process.args();
    _ = args.next(); // ignore program name

    const path = args.next() orelse @panic("no input file");
    var file = try std.fs.cwd().openFile(path, .{});
    defer file.close();

    var sequence: [1000]u8 = undefined;
    const seq_size = try file.readAll(&sequence);
    reverseComplement(sequence[0..seq_size]);

    var out = std.io.getStdOut().writer();
    try out.print("{s}\n", .{sequence[0..seq_size]});
}
