-- Write your PostgreSQL query statement below
SELECT customer_id 
FROM (SELECT customer_id, COUNT(DISTINCT(product_key)) AS count FROM Customer GROUP BY customer_id) t 
WHERE t.count = (SELECT COUNT(*) FROM Product)