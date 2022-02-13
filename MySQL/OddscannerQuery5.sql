-- 5. Write a query to get the department name and number of employees in the department.

SELECT COUNT(EMPLOYEE_ID), 
	   departments.DEPARTMENT_NAME
FROM employees 
JOIN departments
ON employees.DEPARTMENT_ID = departments.DEPARTMENT_ID
GROUP BY DEPARTMENT_NAME;

