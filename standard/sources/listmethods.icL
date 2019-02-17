@empty = [];
@fonts = ["Arial", "Helvetica", "Times", "Courier"];

@empty.append "";                 `` [""]
@fonts.at 2;                      `` "Times"
@fonts.contains "arial";          `` false
@fonts.contains ("arial", false); `` true
@empty.clear;                     `` []
@fonts.count "Arial";             `` 1

@fonts.filter "e";           `` ["Helvetica", "Times", "Courier"]
@fonts.indexOf "Times";      `` 2
@fonts.insert (1, "DejaVu"); `` ["Arial", "DejaVu", "Helvetica", "Times", "Courier"]
@fonts.join ", ";            `` "Arial, DejaVu, Helvetica, Times, Courier"
@fonts.lastIndexOf "Arial";  `` 0

@fonts.mid (2, 2);       `` ["Times", "Courier"]
@fonts.prepend "DejaVu"; `` ["DejaVu", "Arial", "DejaVu" .. "Courier"]
@fonts.move (1, 2);      `` ["DejaVu", "DejaVu", "Arial", "Helvetica" ..]

@fonts.removeAll "Helvetica"; `` ["DejaVu", "DejaVu", "Arial", "Times", "Courier"]
@fonts.removeAt 3;            `` ["DejaVu", "DejaVu", "Arial", "Courier"]
@fonts.removeDuplicates;      `` ["DejaVu", "Arial", "Courier"]
@fonts.removeFirst;           `` ["Arial", "Courier"]
@fonts.removeLast;            `` ["Arial"]
@fonts.removeOne "Arial";     `` []

@fonts = ["Arial", "Helvetica", "Times", "Courier"];

@fonts.replaceInStrings ("e", "-"); `` ["Arial", "H-lv-tica", "Tim-s", "Couri-r"];
@fonts.sort;                        `` ["Arial", "Couri-r", "H-lv-tica", "Tim-s"];
