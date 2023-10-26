-- Write your PostgreSQL query statement below
SELECT U.name, T.balance FROM Users U
JOIN 
    (SELECT account, SUM(amount) AS balance FROM Transactions GROUP BY account HAVING SUM(amount) > 10000) T
ON U.account = T.account;