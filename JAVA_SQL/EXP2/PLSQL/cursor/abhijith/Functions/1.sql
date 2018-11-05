set serveroutput on;
create or replace procedure srch(wildcard in varchar2) is
		cursor s is select name from staff1 where name like wildcard;
	begin
		for i in s loop
			dbms_output.put_line(i.name);
		end loop;
	end;
/
declare 
	i integer;
	c char;
	wildcard varchar2(40):='';
begin
	i := '&i';
	c := '&c';
	for k in 2..i loop
		wildcard:=wildcard ||'_';
	end loop;
	wildcard:=wildcard||c||'%';
	dbms_output.put_line(wildcard);
	srch(wildcard);
	end;
/