accept catalogue_no video3.catalogno%type prompt "Enter the catalogue_no";
set serveroutput on;
declare
	catalogue_no video3.catalogno%type ;
begin
	catalogue_no:=&catalogue_no;
	select catalogno into catalogue_no from video3 where catalogno=catalogue_no;
	update video3 set dailyrental=dailyrental+10 where catalogno=catalogue_no;
	dbms_output.put_line('	Record updated with new value');
	exception
		when NO_DATA_FOUND then
			dbms_output.put_line('No record foung matching catalogno '|| catalogue_no);
			dbms_output.put_line('Please Try again');
end;
/