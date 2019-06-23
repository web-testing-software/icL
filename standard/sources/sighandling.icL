Signal.add "NumberTooBig";
Signal.add "NumberTooSmall";

@i = 3;

emitter {
    if (@i < 2) {
        emit:NumberTooSmall @i :! string + " is smaller then 2.";
    }

    if (@i > 5) {
        emit:NumberTooBig @i :! string + " is bigger then 5."
    }

    `` @i >= 2 \& @i <= 5
}
slot:NumberTooBig {
    Log.error "Oooops...";
}
slot:NumberTooSmall {
    Log.error "Nope! O_O";
};
