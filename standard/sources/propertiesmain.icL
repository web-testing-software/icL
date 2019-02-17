@int = 2;
@double = 3;
@string = "int";

@int'typeName == @string;        `` true
@int'typeId == @double'typeId ;  `` false
@string'typeId == Types'string;  `` true

@int'rValue;   `` false
1234'rValue;   `` true

@int'readOnly; `` false
1234'readOnly; `` true

@int'lValue;   `` true
1234'lValue;   `` false

@int'link;     `` true
1234'link;     `` false
