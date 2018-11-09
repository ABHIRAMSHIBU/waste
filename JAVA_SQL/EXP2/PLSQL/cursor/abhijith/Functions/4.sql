set serveroutput on;
create or replace procedure display_char_role(name in actor1.actorName%type ) is
declare
    Cursor r is select character from  role1 where actorNo  = (select actorNo from actor where actorName = name);
begin
    for i in r loop
        dbms_output.put_line(i.character);
    end loop;
end;
/
    
declare 
    name actor1.actorName%type;
BEGIN
    name:='&actorname';
    display_char_role(name);
end;
/
select * from user_errors where name='DISPLAY_CHAR_ROLE';
