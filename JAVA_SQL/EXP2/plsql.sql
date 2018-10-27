drop table circle2
create table circle2(radius integer primary key ,circumference decimal(20,10),area decimal(20,10));

set serveroutput on;
accept radius1 integer prompt "Enter Smaller radius";
accept radius2 integer prompt "Enter Larger radius";
declare
	radius1 integer;
	radius2 integer;
	area decimal(20,10);
	circumference decimal(20,10);
BEGIN
	radius1:=&radius1;
	radius2:=&radius2;
	dbms_output.put_line('		radius		circumference   area');
	for r in r1..r2 loop
		area:=3.14*r*r;
		circumference:=2*3.14*r;
		dbms_output.put_line('		'||r||'		'||circumference||'		'||area);
		insert into circle2 values(r,circumference,area);
	end loop;
END;
/