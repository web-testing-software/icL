`` error
@test1 = @var;
if (@) {
	`` error
	@test2 = @var;
	`` initialization
	@var = 0;
	`` ok
	@test3 = @var;
	if (@) {
		`` ok
		@test4 = @var;
	}
	`` ok
	@test5 = @var;
}
`` error
@test6 = @var;
