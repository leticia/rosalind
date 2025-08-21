const std = @import("std");

const prt2rna: [25]u8 = .{
    4, // A
    0, // B
    2, // C
    2, // D
    2, // E
    2, // F
    4, // G
    2, // H
    3, // I
    0, // J
    2, // K
    6, // L
    1, // M
    2, // N
    0, // O
    4, // P
    2, // Q
    6, // R
    6, // S
    4, // T
    0, // U
    4, // V
    1, // W
    0, // X
    2, // Y
};

fn computePossibleRNAStrings(protein: []const u8) usize {
    var res: usize = 3; // stop codons
    for (protein) |p| {
        if (p >= 'A' and p < 'Z') {
            const m = prt2rna[p - 'A'];
            std.debug.assert(m > 0);
            res = (res * m) % 1_000_000;
        }
    }
    return res;
}

test "compute number of possible RNA strings" {
    try std.testing.expectEqual(12, computePossibleRNAStrings("MA"));
    try std.testing.expectEqual(102976, computePossibleRNAStrings("MAMAPRTEINSTRING"));
    try std.testing.expectEqual(352192, computePossibleRNAStrings("MAMAPRTEINSTRINGMAMAPRTEINSTRING"));
    try std.testing.expectEqual(68288, computePossibleRNAStrings("MAMAPRTEINSTRINGMAMAPRTEINSTRINGMAMAPRTEINSTRINGMAMAPRTEINSTRING"));
}

pub fn main() !void {
    var args = std.process.args();
    _ = args.next(); // ignore program name

    const path = args.next() orelse @panic("no input file");
    var file = try std.fs.cwd().openFile(path, .{});
    defer file.close();

    var protein: [1000 * 2]u8 = undefined; // 1000 aa
    const size = try file.readAll(&protein);
    const res = computePossibleRNAStrings(protein[0..size]);

    var out = std.io.getStdOut().writer();
    try out.print("{}\n", .{res});
}
