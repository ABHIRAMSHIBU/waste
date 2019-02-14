 --Question 1
 --a
 create view role1_view as select * from role1;
 --b
 insert into role1_view values('AB101','207131','HERMIONE GRANGER');
 --b
 delete from role1_view where actorno='A4343';
--c
update role1_view set character='IRONMAN' where actorno='A7525';

--Question 2
 create view manager_staff_view1 as select * from staff1 where position='Manager';
--Question 3
 create index branch_index1 on branch1(branchno);
--Question 4 
 create index composite_index_role1 on role1(actorno,catalogno);
 --Question 5
 create unique index staff_name_index1 on staff1(name);
 --Question 6
 drop index branch_index1 ;
 
 create table DEPARTMENT(DEP_ID NUMBER, DEPT_NAME VARCHAR2(10), MANAGER_ID NUMBER);
 CREATE SEQUENCE DEPT_ID_SEQ MINVALUE 200 MAXVALUE 1000 START WITH 200 INCREMENT BY 10 CACHE 20;
 INSERT INTO DEPARTMENT VALUES (DEPT_ID_SEQ.NEXTVAL, 'CS', '123');
 INSERT INTO DEPARTMENT VALUES (DEPT_ID_SEQ.NEXTVAL, 'CS', '124');
 