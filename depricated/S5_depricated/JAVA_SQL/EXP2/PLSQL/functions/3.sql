set serveroutput on;
create or replace PROCEDURE sumOfSal(branch in staff1.branchno%type ,sumSal out staff1.salary%type) is
BEGIN
    select sum(salary) into sumSal from staff1 where branchNo=branch;
end;
/

SET SERVEROUTPUT ON verify off; 

declare 
    branch staff1.branchno%type;
    sumSal staff1.salary%type;
BEGIN
    branch := '&branch';
    sumOfSal(branch,sumSal);
    dbms_output.put_line('The sum of salary for ' || branch || ' is '|| sumSal);
    
end;
/
