@list = ["apple", "banana", "fruit"];

filter (@list; @ << "a") {
	@; `` apple, banana
}
