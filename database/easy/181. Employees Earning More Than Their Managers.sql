-- Write your PostgreSQL query statement below
-- A.name AS Employee
SELECT A.name AS Employee FROM Employee A
LEFT JOIN Employee B
ON A.managerId = B.id
WHERE A.managerid IS NOT NULL AND A.salary > B.salary;