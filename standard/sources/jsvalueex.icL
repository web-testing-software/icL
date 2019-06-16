@title = js:value {
	document.title;
	document.title = @{value}
};
Log.out @title;
@title = "Yet another title.";
