-- Write your PostgreSQL query statement below
SELECT DISTINCT T1.id, 
-- T1.p_id,
-- T2.id AS child,
-- T2.p_id AS self
(CASE 
  WHEN T1.p_id IS NULL THEN 'Root'
  WHEN T2.p_id IS NULL THEN 'Leaf'
  ELSE 'Inner'
END) AS type
FROM Tree T1
LEFT JOIN Tree T2
ON T1.id = T2.p_id