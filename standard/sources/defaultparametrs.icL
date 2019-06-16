$fun = (@a = 21, @b = 23) {}

`` the line 

$fun(exists(@a, # > 3), exists(@b, # < 5));

`` replace the next code

if (@a > 3) {
	if (@b < 5) {
		$fun (@a, @b);
	}
	else {
		$fun (@a, 23);
	}
}
else {
	if (@b < 5) {
		$fun (21, @b);
	}
	else {
		$fun (21, 23);
	}
}
