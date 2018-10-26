--Question 1
select * from registration3 natural join staff3
where to_char(dateJoined,'mm')=10;
--Question 2
select 	memberNo,videoNo,to_char(dateReturn,'Day' ) as Day from RentalAgreement3;
--Question 3
select staffNo,to_char(dateJoined,'Month-DD-yyyy') from Registration3 natural join staff3;
--Question 4
select (sysdate+15) as fifteen_days_from_now from dual;
--Question 5
select sysdate-datereturn as no_of_days_elapsed from rentalagreement3,dual;