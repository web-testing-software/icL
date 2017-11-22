CREATE TABLE versions (
	version_id	INTEGER PRIMARY KEY,
	sites		INTEGER,
	history		INTEGER
);

INSERT INTO versions (sites, history)
	VALUES (1, 1);

CREATE TABLE sites (
	site_id	INTEGER PRIMARY KEY,
	url		varchar,
	name	varchar
);

CREATE TABLE history (
	visit_id	INTEGER PRIMARY KEY,
	site_id		INTEGER,
	date_time	DATETIME,
	name		varchar
);
