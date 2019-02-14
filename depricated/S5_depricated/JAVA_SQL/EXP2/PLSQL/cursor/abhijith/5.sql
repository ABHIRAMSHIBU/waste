set serveroutput on;
declare
	cursor temp(n varchar ) is select * from Staff1 where position=(select position from Staff1 where name=n);
begin
	for i in temp('Sally Stern')
	loop
		dbms_output.put_line(i.staffNo||' '||i.name||' '||i.position||' '||i.salary||' '||i.branchNo);
	end loop;
end;
/