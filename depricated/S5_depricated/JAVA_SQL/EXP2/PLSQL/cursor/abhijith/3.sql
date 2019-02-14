set serveroutput on;
declare 
avgsalary decimal(10,5);
cursor s is select name,salary from staff1;
begin
dbms_output.put_line('Average salary is '||avgsalary);
select avg(salary) into avgsalary from staff1;
dbms_output.put_line('Name and salary of people with salary greater than avgsalary');
for i in s loop
if(i.salary>avgsalary) then
	dbms_output.put_line(i.name||' 	'||i.salary);
end if;
end loop;
dbms_output.put_line('Name and salary of people with salary less than avgsalary');
for i in s loop
if(i.salary<avgsalary) then
	dbms_output.put_line(i.name||'   	'||i.salary);
end if;
end loop;
end;
/