@empty = [];
@fonts = ["Arial" "Helvetica" "Times" "Courier"];

@empty'empty;  `` true
@fonts'empty;  `` false

@empty'length; `` 0
@fonts'length; `` 4

@empty'last;   `` error
@fonts'last;   `` "Courier"

@empty'0;      `` error
@fonts'0;      `` "Arial"
