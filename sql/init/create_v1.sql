CREATE TABLE `versions` (
	`version_id`		INTEGER PRIMARY KEY,
	`version_number`	INTEGER
);

INSERT INTO `versions` (`version_number`)
VALUES (1);

CREATE TABLE `sites` (
	`site_id`	INTEGER PRIMARY KEY,
	`url`		varchar,
	`name`	varchar
);

CREATE TABLE `history` (
	`visit_id`	INTEGER PRIMARY KEY,
	`site_id`	INTEGER,
	`date_time`	DATETIME,
	`name`		varchar
);
