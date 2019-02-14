set serveroutput on;
declare 
	num integer := 12345;
	revnum integer;
	digit integer;
BEGIN
	dbms_output.put_line('Palindrome numbers between 1 and 100 is ');
	for i in 1..100 loop
		num:=i;
		revnum:=0;
		while(num>0) loop
			digit:=mod(num,10);
			num:=trunc(num/10);
			revnum:=revnum*10+digit;
		end loop;
		if(revnum=i)  then 
			dbms_output.put_line(i);
		end if;
	end loop;
		
END;
/