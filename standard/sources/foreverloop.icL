@times = 5;

for:ever (@ < @times) {
    Log.out("@ = ", @); `` @ = 0, 1, 2, 3, 4
};
`` replaces
for (@i = 0; @i < @times; @i = @i + 1) {
    Log.out("@i = ", @i); `` @i = 0, 1, 2, 3, 4
}
