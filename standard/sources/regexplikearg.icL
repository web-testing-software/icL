@str = "Hello world, collaborators!";

@str.count //\wo//;       `` 5
@str.indexOf //\w{6}//;   `` 13
@str.lastIndexOf //l+o//; `` 2
@str.remove //\w{2}o//;   `` "He world, collrrs!"
@str.split //,?\s//;      `` ["He", "world", "collrrs!"]

@fonts = ["Arial", "Helvetica", "Times", "Courier"];

@fonts.filter //^[ac]//i;       `` ["Arial", "Courier"]
@fonts.indexOf //e.//;          `` 1
@fonts.indexOf (//e.//, 2);     `` 2
@fonts.lastIndexOf //e.//;      `` 3
@fonts.lastIndexOf (//e.//, 2); `` 2
