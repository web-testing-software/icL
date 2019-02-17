"String1" == "String2";                  `` false
["a", "b"] == ["a", "b"];                `` true
["a", "b"] == ["b", "a"];                `` true
["a", "b"] << "c";                       `` false
"abc" << "c";                            `` true
"ab" + "c";                              `` "abc"
"ab" + ["c"];                            `` ["ac", "c"]
["a", "b"] + "c";                        `` ["a", "b", "c"]
["a", "b"] + ["c", "d"];                 `` ["a", "b", "c", "d"]
"abc" * "*c";                            `` true
["ac", "bc"] * "*c";                     `` true
["ac", "bc"] * "a*";                     `` false
["ad", "ac", "bd", "cc"] * ["*d", "*c"]; `` true
["ad", "ac", "bc", "cd"] * ["*d", "*c"]; `` false
"Tom is a cat" ** "Tom is not a cat";    `` 0.875
