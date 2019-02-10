fun = () : int {
    @ = 23
}

if (fun() == 12) {
    Log.out 12345678
} 
else {
    Log.out 87654321
}

emiter {
    func(@x)
}
slot:Error1 {
    @x = 45
}
