/*
create table circle1(radius integer primary key ,circumference decimal(20,10),area decimal(20,10));
*/

set serveroutput on;
accept r1 integer prompt "Enter Smaller radius";
accept r2 integer prompt "Enter Larger radius";
declare
	r1 integer;
	r2 integer;
	area decimal(20,10);
	circumference decimal(20,10);
BEGIN
	r1:=&r1;
	r2:=&r2;
	dbms_output.put_line('		radius		circumference   area');
	for r in r1..r2 loop
		area:=3.14*r*r;
		circumference:=2*3.14*r;
		dbms_output.put_line('		'||r||'		'||circumference||'		'||area);
		insert into circle1 values(r,circumference,area);
	end loop;
END;
/
/*
delete from circle1;
*/