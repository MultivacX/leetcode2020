-- Write your PostgreSQL query statement below
SELECT stock_name, SUM(cgl) AS capital_gain_loss FROM

(SELECT stock_name, -SUM(price) AS cgl 
FROM Stocks 
WHERE operation = 'Buy' 
GROUP BY stock_name

UNION

SELECT stock_name, SUM(price) AS cgl 
FROM Stocks 
WHERE operation = 'Sell' 
GROUP BY stock_name)

GROUP BY stock_name;