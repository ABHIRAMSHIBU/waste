set serveroutput on;
declare
cursor sal is select * from staff3 order by salary desc;
c integer :=0;
begin
for i in sal loop
	if(c=1) then
		dbms_output.put_line(i.name||'	'||i.staffno||'   '||i.position);
	end if;
	c:=c+1;
end loop;
end;
/