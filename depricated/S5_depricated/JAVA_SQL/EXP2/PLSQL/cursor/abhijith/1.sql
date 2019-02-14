set verify off;
set serveroutput on;
declare
	staffNo staff1.staffNo%type;
	name staff1.name%type;
	position staff1.position%type;
	salary staff1.salary%type;
	branch varchar2(40);
	cursor staff_det is select staffNo,name,position,salary from staff1 where branchNo='&branch';
begin
	open staff_det;
	loop 
		fetch staff_det into staffNo,name,position,salary ;
		EXIT WHEN staff_det%NOTFOUND;
		dbms_output.put_line(staffNo ||' '|| name||' ' || position||' ' || salary||' ' || branch);
	end loop;
	close staff_det;
end;
/