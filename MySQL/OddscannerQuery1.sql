
-- 1. Write a query to display the name (first_name and last_name) and department ID of all employees in departments 30 or 100 in ascending order.
SELECT FIRST_NAME, 
	   LAST_NAME, 
       DEPARTMENT_ID 
FROM employees 
WHERE DEPARTMENT_ID=30 OR DEPARTMENT_ID=100 
ORDER BY FIRST_NAME ASC;

