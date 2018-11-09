DECLARE
    cursor c(name VARCHAR2) is select * from role3 where actorNo=(select actorNo from actor3 where actorName=name);
    actor_name varchar2(30);
PROCEDURE test (n in varchar2) is
    BEGIN
        for i in c(n) loop
            dbms_output.put_line('Role for actor '|| n || ' is '|| i.character);
        end loop;
    end test;
BEGIN
    actor_name:='&Name';
    test(actor_name);
end;
/
