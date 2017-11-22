SELECT `sites`.`name` AS `name`,
	`sites`.`url` AS `url`,
	COUNT(`history`.`site_id`) AS `count`
FROM `sites`
JOIN `history`
ON `sites`.`site_id` = `history`.`site_id`
GROUP BY `history`.`site_id`
ORDER BY `count` DESC,
	`sites`.`site_id` ASC
LIMIT 9
