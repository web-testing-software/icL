@list = ["apple", "banana", "fruit", "kiwi"];

range (@list; @ == "banana"; @ == "kiwi") {
	@; `` banana, fruit, kiwi
}
