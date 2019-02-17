DBManager.openSQLite "db.sqlite";

`` simple query
DB.query {
    SELECT country
    FROM artists
};
Query.exec();

while (Query.next) {
    doSomething Query'country;
};

`` query with parameters
DB.query {
    SELECT name
    FROM programmers
    WHERE country = :country
    LIMIT 1
};
Query'country = "Moldova";
`` is equivalent to
@md = "Moldova";
DB.query {
    SELECT name
    FROM programmers
    WHERE country = @:md
    LIMIT 1
};

`` insert query
DB.query {
    INSERT INTO person (id, forname, name)
    VALUE (:id, :forname, :name)
};
Query'id = 1001;
Query'forname = "Bart";
Query'name = "Simpson";
Query.exec();
