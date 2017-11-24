SELECT `sites`.`site_id` INDEXED BY `url_index`
FROM `sites`
WHERE `sites`.`url` = ?
LIMIT 1
