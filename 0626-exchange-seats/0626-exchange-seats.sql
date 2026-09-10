# Write your MySQL query statement below

select e.id, COALESCE(m.student,e.student) as student
from Seat as e
LEFT JOIN Seat as m
on m.id = CASE
            WHEN e.id % 2 = 1 THEN e.id + 1
            ELSE e.id - 1
        END
ORDER BY e.id ;