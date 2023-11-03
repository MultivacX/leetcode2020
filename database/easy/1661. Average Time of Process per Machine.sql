-- Write your PostgreSQL query statement below
SELECT machine_id, ROUND(CAST(AVG(pt * 2) AS numeric), 3) AS processing_time FROM
(SELECT 
    machine_id, 
    (CASE 
        WHEN activity_type = 'start' THEN -timestamp 
        ELSE timestamp 
    END) AS pt
FROM Activity) A
GROUP BY machine_id