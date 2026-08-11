SELECT name,bonus 
FROM EMPLOYEE e LEFT JOIN BONUS b
ON e.empId = b.empId
WHERE bonus is NULL OR bonus < 1000;