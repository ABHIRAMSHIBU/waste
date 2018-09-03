-- Question number 1
update video3 set dailyrental=dailyrental+dailyrental*0.1 where category='Fantasy' ;
commit;
-- Question number 2
select DISTINCT(category) from video3;
-- Question number 3
select title,dailyrental*3 as ThreeDayRate from Video3;
-- Question number 4
select * from staff3 where salary between 45000 and 50000;
-- Question number 5
select * from video3 where category in ('Action','Children');
-- Question number 6
select * from staff3 where name like 'Sally %';
-- Question number 7
select * from rentalagreement3 where dateReturn is NULL;
-- Question number 8
select position from staff3 where name like '_o%';
-- Question number 9
select name from staff3 where position!='Manager' order by (name);
-- Question number 10
select * from video3 where price>20 order by (price);
-- Question number 11
--alter table video3 add constraint 
--delete from video3 where catalogno=634817 cascade constraint;
