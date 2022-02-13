-- 3. Write a query to find the name (first_name and last_name) and the salary of the employees who earn more than the employee whose last name is Bell.

SELECT FIRST_NAME,
       LAST_NAME,
       SALARY
FROM employees
WHERE SALARY > (SELECT SALARY FROM employees WHERE LAST_NAME='Bell');



SELECT SALARY FROM employees WHERE LAST_NAME='Bell' -- Salary = 4000