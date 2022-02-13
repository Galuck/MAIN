-- 4. Write a query to find the name (first_name and last_name), job, department ID and name of all employees that work in London.

SELECT employees.FIRST_NAME,
	   employees.LAST_NAME,
       employees.JOB_ID,
       departments.DEPARTMENT_ID,
       departments.DEPARTMENT_NAME,
       locations.CITY
FROM employees
INNER JOIN departments
ON employees.DEPARTMENT_ID = departments.DEPARTMENT_ID
JOIN locations
ON departments.LOCATION_ID = locations.LOCATION_ID
WHERE locations.CITY='London'