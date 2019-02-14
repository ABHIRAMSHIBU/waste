set verify off;
set serveroutput on;
--catalogno,title,dailyrental,price
declare

	catalogno video3.catalogno%type;
	title video3.title%type;
	dailyrental video3.dailyrental%type;
	price video3.price%type;
	category varchar2(40);
	cursor video_det is select catalogno,title,dailyrental,price from video3 where category='&category';
begin
	open video_det;
	for i in 1..100 loop 
		fetch video_det into catalogno,title,dailyrental,price;
		EXIT WHEN video_det%NOTFOUND;
		dbms_output.put_line(catalogno||'    '||title||'    '||dailyrental||'    ' ||price);
	end loop;
	close video_det;
end;
/