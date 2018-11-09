set serveroutput on;
create or replace procedure MXMN(MX out staff1.salary%type,MN out staff1.salary%type) is
begin
            select max(price),min(price) into MX,MN from video1;
end;
/
declare 
	MX staff1.salary%type;
	MN staff1.salary%type;
begin
    MXMN(MX,MN);
    dbms_output.put_line('The maximum salary is ' || MX);
    dbms_output.put_line('The minimum salary is ' || MN);
end;
/
