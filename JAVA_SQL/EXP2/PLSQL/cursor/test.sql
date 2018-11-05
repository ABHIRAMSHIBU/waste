set serveroutput on;
DECLARE
	cursor temp is select * from branch3;
	branchNo varchar2(10);
	street varchar2(100);
	city varchar2 (10);
	stat varchar2(10);
	zipcode integer;
	mgrStaffNo varchar2(100);
BEGIN
	for i in temp
	loop
		dbms_output.put_line(i.branchNo||' '||i.street||' '||i.city);
	end loop;
end;
/