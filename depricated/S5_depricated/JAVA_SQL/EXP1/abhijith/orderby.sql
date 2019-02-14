--ORDER BY GROUP BY AND HAVING CLAUSE
--Question 1
SELECT BRANCHNO AS BRANCH, COUNT(BRANCHNO) AS NO_OF_WORKERS , SUM (SALARY) FROM STAFF1  GROUP BY BRANCHNO ORDER BY BRANCHNO; 
--Question 2
 SELECT BRANCHNO AS BRANCH, COUNT(BRANCHNO) AS NO_OF_WORKERS , SUM (SALARY) 
	FROM STAFF1 
	GROUP BY BRANCHNO 
	HAVING COUNT(BRANCHNO) >1 
	ORDER BY BRANCHNO;
--QUESTION 3
SELECT POSITION,COUNT(STAFFNO),SUM(SALARY) 
	FROM STAFF1 WHERE POSITION IN ('Manager','Supervisor') 
	GROUP BY POSITION;
-- Question 3
select Position,count(*),sum(salary) salary 
	from staff1 
	where position in ('Manager','Supervisor') 
	GROUP by (position);
-- Question 4
select sum(PRICE) total 
	from video1 
	where category='Children';
-- Question 5
select Actorno,count(ActorNo) Times 
from role1
group by ACTORNo;