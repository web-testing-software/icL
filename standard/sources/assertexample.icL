`` wrong
assert (@val != 2 || @val != 4 || @val != 127, "Message");

`` correct
@message = "Message";
assert (@val != 2,   @message);
assert (@val != 4,   @message);
assert (@val != 127, @message);

`` without using a variable
for any ("Message") {
    assert (@val != 2,   @);
    assert (@val != 4,   @);
    assert (@val != 127, @);
}
