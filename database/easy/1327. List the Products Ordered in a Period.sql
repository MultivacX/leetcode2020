-- Write your PostgreSQL query statement below
SELECT product_name, O.unit FROM Products 
JOIN
(SELECT product_id, SUM(unit) AS unit FROM Orders
WHERE EXTRACT(YEAR FROM order_date) = 2020 AND EXTRACT(MONTH FROM order_date) = 2
GROUP BY product_id
HAVING SUM(unit) >= 100) O
ON O.product_id = Products.product_id;