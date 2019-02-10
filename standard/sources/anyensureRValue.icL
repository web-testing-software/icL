@int = 123;

@int'rValue;   `` false
@int'readOnly; `` false
@int.ensureRValue;
@int'rValue;   `` true
@int'readOnly; `` false
