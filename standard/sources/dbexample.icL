DBManager.openSQLite "db.sqlite";

`` simple query
sql{
    SELECT country
    FROM artists
}.create().exec();

while (Query.next) {
    $doSomething Query'country;
};

`` query with parameters
sql{
    SELECT name
    FROM programmers
    WHERE country = :country
    LIMIT 1
}.create();
Query'country = "Moldova";
`` is equivalent to
@md = "Moldova";
sql{
    SELECT name
    FROM programmers
    WHERE country = @:md
    LIMIT 1
}.create();

`` insert query
sql{
    INSERT INTO person (id, forname, name)
    VALUE (:id, :forname, :name)
}.create();
Query'id = 1001;
Query'forname = "Bart";
Query'name = "Simpson";
Query.exec();
