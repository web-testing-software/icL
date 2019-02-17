@list = ["apple", "banana", "fruit"];

filter (@list; # \ 2 == 0) {
	@; `` apple, fruit
}
