"string" << //s.r//;            `` true
"string" <* //s(.)r//;          `` ["str", "t"]
"string" ** //s(?<letter>.)r//; `` [letter = "t"]