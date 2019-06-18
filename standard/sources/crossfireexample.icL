@el = tag[button];

func = {
    Log.info "It's working!"
};

js{
    arguments[0].onlick = function (ev) { !{func}() }
}
.crossfire()
.run(@el);
