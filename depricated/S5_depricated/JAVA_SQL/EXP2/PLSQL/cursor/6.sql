set serveroutput on;
declare
	cursor l is select * from Staff3 where salary<30000;
	cursor u is select * from Staff3 where salary>30000;
begin
	for i in l
	loop
		update Staff3 set salary=(salary+(salary*(15/100))) where staffNo=i.staffNo;
	end loop;
	for i in u
	loop
		update Staff3 set salary=(salary+(salary*(10/100))) where staffNo=i.staffNo;
	end loop;
end;
/