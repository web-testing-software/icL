@set = [age : int, name : string, sex : string]

@set.applicate (
    ["23",    "45",     "67"],
    ["Basil", "Nataly", "Siri"],
    ["m",     "f",      "f"]);
``` set = [
    [age = 23, name = "Basil",  sex = "m"]
    [age = 45, name = "Nataly", sex = "f"]
    [age = 67, name = "Siri",   sex = "f"]
] ```

@set.getField "name"; `` ["Basil", "Nataly", "Siri"]

@set.insert (34, "Critiano", "m");
``` set = [
    [age = 23, name = "Basil",     sex = "m"]
    [age = 45, name = "Nataly",    sex = "f"]
    [age = 67, name = "Siri",      sex = "f"]
    [age = 34, name = "Cristiano", sex = "m"]
] ```

@set.insert [sex = "f", name = "Sofia", age = 19];
``` set = [
    [age = 23, name = "Basil",    sex = "m"]
    [age = 45, name = "Nataly",   sex = "f"]
    [age = 67, name = "Siri",     sex = "f"]
    [age = 34, name = "Cristiano" sex = "m"]
    [age = 19, name = "Sofia",    sex = "f"]
] ```

@set.insertField ("parity", ["odd", "even"], string);
``` set = [
    [age = 23, name = "Basil",    sex = "m", parity = "odd"]
    [age = 45, name = "Nataly",   sex = "f", parity = "even"]
    [age = 67, name = "Siri",     sex = "f", parity = "odd"]
    [age = 34, name = "Cristiano" sex = "m", parity = "even"]
    [age = 19, name = "Sofia",    sex = "f", parity = "odd"]
] ```

@set.remove (45, "Nataly", "f", "even");
``` set = [
    [age = 23, name = "Basil",    sex = "m", parity = "odd"]
    [age = 67, name = "Siri",     sex = "f", parity = "odd"]
    [age = 34, name = "Cristiano" sex = "m", parity = "even"]
    [age = 19, name = "Sofia",    sex = "f", parity = "odd"]
] ```

@set.remove [age = 34, name = "Cristiano", sex = "m", parity = "even"];
``` set = [
    [age = 23, name = "Basil", sex = "m", parity = "odd"]
    [age = 67, name = "Siri",  sex = "f", parity = "odd"]
    [age = 19, name = "Sofia", sex = "f", parity = "odd"]
] ```

@set.removeField "parity";
``` set = [
    [age = 23, name = "Basil", sex = "m"]
    [age = 67, name = "Siri",  sex = "f"]
    [age = 19, name = "Sofia", sex = "f"]
] ```

@set.clear(); `` set = []
