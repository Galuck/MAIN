-- 2. Write a query to find the manager ID and the salary of the lowest-paid employee for that MANAGER
SELECT MANAGER_ID, 
	   MIN(SALARY),
       FIRST_NAME, 
       LAST_NAME 
FROM employees 
WHERE MANAGER_ID=100  -- 100 foi usado aqui apenas para testes  // 100 was used here only for testing
ORDER BY SALARY ASC
LIMIT 3;

