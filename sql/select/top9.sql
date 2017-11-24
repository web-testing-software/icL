SELECT `sites`.`name` AS `name`,
	`sites`.`url` AS `url`,
	COUNT(`history`.`site_id`) AS `count`
FROM `sites`
JOIN `history` INDEXED BY `site_index`
ON `sites`.`site_id` = `history`.`site_id`
GROUP BY `history`.`site_id`
ORDER BY `count` DESC,
	`sites`.`site_id` ASC
LIMIT 9
