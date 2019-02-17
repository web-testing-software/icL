@list = ["apple", "banana", "fruit", "kiwi"];

range (@list; # == 2; true) {
	@; `` fruit, kiwi
}
