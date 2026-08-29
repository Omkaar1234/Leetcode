select d.name as "Department", e.name as "Employee", e.salary as "Salary" from
Employee as e INNER JOIN
Department as d
on e.departmentId = d.id
where e.salary = (
select MAX(salary) from
Employee 
GROUP BY Employee.departmentId 
HAVING Employee.departmentId = d.id)
