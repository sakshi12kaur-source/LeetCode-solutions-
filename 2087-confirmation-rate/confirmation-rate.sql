SELECT 
    DISTINCT(s.user_id),
    ROUND(
        SUM(IF(c.action = 'confirmed', 1, 0)) OVER (PARTITION BY s.user_id) / 
        COUNT(*) OVER (PARTITION BY s.user_id), 
        2
    ) AS confirmation_rate
FROM 
    signups s 
LEFT JOIN 
    confirmations c ON s.user_id = c.user_id;