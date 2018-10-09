--Question 1
select * from registration1 natural join staff1
where to_char(dateJoined,'mm')=10;
--Question 2
select 	memberNo,videoNo,to_char(dateReturn,'Day' ) as Day 
from RentalAgreement1;
--Question 3
select staffNo,to_char(dateJoined,'Month-DD-yyyy') from Registration1 natural join staff1;
--Question 4
select (sysdate+15) as fifteen_days_from_now from dual;