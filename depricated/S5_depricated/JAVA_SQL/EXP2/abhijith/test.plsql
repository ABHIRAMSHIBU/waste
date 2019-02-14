set serveroutput on
declare 
dat varchar2(10);
a integer:=3;
b integer:=4;
c integer;
BEGIN
dat := 'COMPLETED';
c:=a+b;
c:=5;
dbms_output.put_line ('sum of '||a || ' and '|| b||' is ' || c);
if(c<5) then
	dbms_output.put_line('sum is less than 5');
else if(c>5) then
	dbms_output.put_line('sum is greater than 5');
else
	dbms_output.put_line('Sum is equal ro 5');
end if;
end if;
dbms_output.put_line(dat);
END;
/