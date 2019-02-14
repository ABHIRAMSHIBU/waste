set serveroutput on;
declare 
	string varchar2(20):='12345';
	num integer := 12345;
	revstring varchar2(20);
	revnum integer;
	digit integer;
BEGIN
	for i in reverse 1..length(string) loop
		revstring := revstring || substr(string,i,1);
	end loop;
	dbms_output.put_line('The original string is ' || string);
	dbms_output.put_line('The string after reversing is ' || revstring);
	while(num>0) loop
		digit:=mod(num,10);
		num:=trunc(num/10);
		revnum:=revnum*10+digit;
	end loop;
	dbms_output.put_line('The original number is ' || string);
	dbms_output.put_line('The number after reversing is ' || revstring);
END;
/