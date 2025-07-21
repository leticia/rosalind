const std = @import("std");

const Nucleobases = struct {
    A: usize = 0,
    C: usize = 0,
    G: usize = 0,
    T: usize = 0,

    fn countIn(self: *@This(), sequence: []const u8) void {
        for (sequence) |nucleoide| {
            switch (nucleoide) {
                'A' => self.A += 1,
                'C' => self.C += 1,
                'G' => self.G += 1,
                'T' => self.T += 1,
                else => {}, // ignore \n or anything else
            }
        }
    }
};

test "count nucleotides" {
    var nucleobases = Nucleobases{};
    nucleobases.countIn("AGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGTGGATTAAAAAAAGAGTGTCTGATAGCAGC");

    try std.testing.expectEqual(20, nucleobases.A);
    try std.testing.expectEqual(12, nucleobases.C);
    try std.testing.expectEqual(17, nucleobases.G);
    try std.testing.expectEqual(21, nucleobases.T);
}

pub fn main() !void {
    var args = std.process.args();
    _ = args.next(); // ignore program name

    const path = args.next(); // absolute file name
    if (path == null) {
        @panic("no input file");
    }

    var file = try std.fs.cwd().openFile(path.?, .{});
    defer file.close();

    var sequence: [1000]u8 = undefined;
    const seq_size = try file.readAll(&sequence);

    var nucleobases = Nucleobases{};
    nucleobases.countIn(sequence[0..seq_size]);

    const out = std.io.getStdOut().writer();
    try out.print("{} {} {} {}\n", .{
        nucleobases.A,
        nucleobases.C,
        nucleobases.G,
        nucleobases.T,
    });
}
