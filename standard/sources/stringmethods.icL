@empty = "";
@fonts = "Arial, Helvetica, Times, Courier";
@index = 2;

@empty.append "data";   `` "data"
@empty.append @fonts'0; `` "dataA"
@empty = "";

@empty.at @index; `` error
@fonts.at @index; `` i
@fonts.at 1;      `` r

@empty.beginsWith "";      `` true
@fonts.beginsWith "Arial"; `` true

@empty.compare "data"; `` false
@empty.compare "";     `` true

@fonts.count ",";      `` 3
@fonts.count @fonts'0; `` 1

@fonts.endsWith "Courier"; `` true
@fonts.endsWith "Arial";   `` false

@fonts.indexOf "Courier"; `` 25
@fonts.indexOf @fonts'11; `` 8

@data = "10"
@data.insert ("data", 1);   `` "1data0"
@data.insert (@fonts'0, 2); `` "1dAata0"

@fonts.lastIndexOf "e";      `` 30
@fonts.lastIndexOf @fonts'8; `` 30

@fonts.left 5; `` "Arial"

@data = "10";
@data.leftJustified (4, "0"); `` "0010"
@data.mid (1, 2);             `` "01"

@data.prepend "11";     `` "1100010"
@data.prepend @fonts'0; `` "A1100010"

@data.remove (2, 2);  `` "11010"
@data.remove "01";    `` "110"

@data.replace (2, 1, "0101"); `` "110101"
@data.replace ("01", "01");   `` "111010"

@data.right 4;                 `` "1010"
@data.rightJustified (8, "0"); `` "11101000"

@fonts.split ", ";     `` ["Arial", "Helvica", "Times", "Curier"]
@fonts.split @fonts'5; `` ["Arial", " Helvica", " Times", " Curier"];

@data.substring (1, 3); `` "11"

@str = " , 34px \n";
@str.trim;       `` ", 34px"
@str.trim false; `` "34px"
