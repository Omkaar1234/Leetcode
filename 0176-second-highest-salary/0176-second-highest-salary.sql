# Write your MySQL query statement below
SELECT MAX(salary) as SecondHighestSalary from (
    SELECT e.salary , DENSE_RANK() OVER(ORDER BY salary DESC) as "salary_rank"
    from Employee as e
) As emp
where salary_rank = 2;