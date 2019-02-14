--Aggregate functions in SQL

--Question 1
select count(salary) as totalstaff,sum(salary) as totalsalary from staff1 where salary>40000; 
--Question 2
SELECT MIN(SALARY) AS MinSalary,MAX(SALARY) as MaxSalary FROM STAFF1; 
--Question 3
SELECT AVG(PRICE) AS AvgPrice FROM VIDEO1;
--Question 4
SELECT COUNT(*) AS NO_WASHINGTON_BRNANCHES FROM BRANCH1 WHERE STATE='WA';
--Question 5
SELECT COUNT(*) AS TOTAL_STAFF_JOINED_JULY FROM REGISTRATION1 WHERE DATEJOINED LIKE '%JUL%';
--Question 6
select  count(*) from video1 where PRICE>20;
