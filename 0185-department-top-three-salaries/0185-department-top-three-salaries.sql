# Write your MySQL query statement below

select Department, Employee, Salary from(
    select 
    d.name as Department,
    e.name as Employee,
    e.salary as Salary,
    DENSE_RANK() OVER(
        Partition by e.departmentId
        Order by e.salary DESC
    ) as rn
    FROM Employee as e
    JOIN 
    Department as d
    on d.id = e.departmentId
) as t1
where t1.rn <= 3
