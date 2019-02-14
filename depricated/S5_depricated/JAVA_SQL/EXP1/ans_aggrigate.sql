--Aggregate SQL

--Question 1
select count(salary) as totalstaff,sum(salary) as totalsalary from staff3 where salary>40000; 
--Question 2
SELECT MIN(SALARY) AS MinSalary,MAX(SALARY) as MaxSalary FROM STAFF3; 
--Question 3
SELECT AVG(PRICE) AS AvgPrice FROM VIDEO3;
--Question 4
SELECT COUNT(*) AS NO_WASHINGTON_BRNANCHES FROM BRANCH3 WHERE STATE='WA';
--Question 5
SELECT COUNT(*) AS TOTAL_STAFF_JOINED_JULY FROM REGISTRATION3 WHERE DATEJOINED LIKE '%JUL%';
--Question 6
select  count(*) from video3 where PRICE>20;