-- Write your PostgreSQL query statement below
SELECT name AS Customers FROM Customers
WHERE NOT EXISTS 
    (SELECT customerId FROM Orders WHERE customerId = Customers.id)