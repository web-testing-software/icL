for any (cookies.new()) {
    @'name = "age";
    @'domain = "example.org";
    @'value = 23 : string;
    @.resetTime().add(1, 0, 0);
    @.save;
};
