`` init
@set1 = [age : int, name : string];
@set2 = [age : int, name : string];
@set3 = [age : int, name : string];

@obj1 = [age = 24, name = "User1"];
@obj2 = [age = 23, name = "User2"];
@obj3 = [age = 26, name = "User3"];
@obj4 = [age = 24, length = 80, height = 40, arc = 1];

@set1.insert @obj1;
@set1.insert @obj2;
@set2.insert @obj3;
@set2.insert @obj2;
@set3.insert @obj2;
@set3.insert @obj1;

`` operators
@set1 == @set2;                 `` false
@set1 == @set3;                 `` true
@obj1 == @obj2;                 `` false
@set2 != @set3;                 `` true
@obj2 != @obj3;                 `` true

@set1 << @obj2;                 `` false
@set1 << @set2;                 `` false
@set1 <* [age = 23];            `` true
@obj4 <* [age = 24, arc = 1];   `` true

@set1 + @set2;                  `` [@obj1, @obj2, @obj3]
@set1 - @set2;                  `` [@obj1, @obj3]
@set1 \ @set2;                  `` [@obj1]
@set1 * @set2;                  `` [@obj2]

@set1 ** @set2;	
