SELECT user_id, 
       CONCAT(Upper(LEFT(name, 1)), LCASE(SUBSTRING(name, 2))) AS name
FROM Users
ORDER BY user_id; 