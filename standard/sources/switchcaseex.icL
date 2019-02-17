@v = 0 | 1 | 2 | 3 | 4 | 5 | 6;

switch (@v) {
	case (0) { `code1` }
	case (1, 2) { `code2` }
	case (#, 3) { `code3` }
	case (4) { `code4` }
	case (~) { `code5` }
}
