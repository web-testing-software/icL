@el = tag[button];

func = {
    Log.info "It's working!"
};

$run {
    @{el}[0].onlick = function (ev) { !{func}() }
};
