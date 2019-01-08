`` error
@test1 = @var;
if (@) {
	`` error
	@test2 = @var;
	if (@) {
		`` error
		@test3 = @var;
		`` initialization
		@var = 0;
		`` ok
		@test4 = @var;
	}
	`` ok
	@test5 = @var;
}
`` ok
@test6 = @var;
