`` example 1

@a = exists(css:try[#el])'text | "";
`` replaces
@a = "";
if (css:all[#el]'length > 0) {
	@a = css[#el]'text;
}

`` example 2

@links = tags[a];

@links.add css:try[#special];
`` replaces
if (!css:all[#special]'empty) {
	@links.add css[#special];
}
`` or
if exists(css[#special]) {
	@links.add @;
}
