set verify off;
set serveroutput on;
--catalogno,title,dailyrental,price
declare

	catalogno video1.catalogno%type;
	title video1.title%type;
	dailyrental video1.dailyrental%type;
	price video1.price%type;
	category varchar2(40);
	cursor video_det is select catalogno,title,dailyrental,price from video1 where category='&category';
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