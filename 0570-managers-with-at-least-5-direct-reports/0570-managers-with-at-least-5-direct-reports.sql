# Write your MySQL query statement below
select e2.name from
(select *,COUNT(*) as report
from Employee
group by managerId
having managerId is NOT NULL) as e1
join 
Employee as e2
on e1.managerId = e2.id

where report >= 5