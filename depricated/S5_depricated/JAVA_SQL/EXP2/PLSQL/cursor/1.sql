set verify off;
set serveroutput on;
declare
	staffNo staff3.staffNo%type;
	name staff3.name%type;
	position staff3.position%type;
	salary staff3.salary%type;
	branch varchar2(40);
	cursor staff_det is select staffNo,name,position,salary from staff3 where branchNo='&branch';
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