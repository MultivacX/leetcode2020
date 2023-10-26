-- Write your PostgreSQL query statement below
SELECT 
(CASE 
WHEN Seat.id % 2 != 0 AND Seat.id = (SELECT COUNT(*) FROM Seat) THEN Seat.id
WHEN Seat.id % 2 != 0 THEN Seat.id + 1
ELSE Seat.id - 1
END) AS id,
student
FROM Seat
ORDER BY id;