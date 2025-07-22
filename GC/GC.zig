const std = @import("std");

const Result = struct {
    label: [14:0]u8 = undefined,
    gcContent: f64 = 0,

    fn copyFrom(self: *@This(), other: *@This()) void {
        std.mem.copyForwards(u8, &self.label, &other.label);
        self.gcContent = other.gcContent;
    }
};

fn gcContent(path: []const u8) !Result {
    const file = try std.fs.cwd().openFile(path, .{});
    defer file.close();

    var bufReader = std.io.bufferedReader(file.reader());
    var reader = bufReader.reader();

    var curr: Result = .{};
    var best: Result = .{};

    _ = try reader.skipUntilDelimiterOrEof('>');

    while (true) {
        const label = reader.readUntilDelimiter(&curr.label, '\n') catch break;
        curr.label[label.len] = 0; // null-terminated string (like in C)

        var total: f64 = 0;
        var gcCount: f64 = 0;

        while (true) {
            switch (reader.readByte() catch break) {
                'G', 'C' => {
                    total += 1;
                    gcCount += 1;
                },
                'A', 'T' => {
                    total += 1;
                },
                '>' => break,
                else => {}, // ignore
            }
        }

        curr.gcContent = (gcCount / total) * 100;
        if (curr.gcContent > best.gcContent) {
            best.copyFrom(&curr);
        }
    }

    return best;
}

test "compute GC-content" {
    const res = try gcContent("GC.txt");
    const label = std.mem.span(@as([*:0]const u8, &res.label));
    try std.testing.expectEqualStrings("Rosalind_0808", label);
    try std.testing.expectApproxEqRel(60.919540, res.gcContent, 0.001);
}

pub fn main() !void {
    var args = std.process.args();
    _ = args.next(); // ignore program name

    const path = args.next() orelse @panic("no input file");
    const res = try gcContent(path);

    var out = std.io.getStdOut().writer();
    try out.print("{s}\n{d}\n", .{ res.label, res.gcContent });
}
