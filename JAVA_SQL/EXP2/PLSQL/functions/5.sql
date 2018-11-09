DECLARE
    cursor c is select * from video3 where price=(select max(price) from video3);
PROCEDURE test is
    BEGIN
        for i in c loop
            dbms_output.put_line(i.catalogNo||' '|| i.title||' '|| i.category||' '|| i.dailyRental||' '|| i.price||' '|| i.directorNo);
            dbms_output.put_line('Title is:'||i.title);
        end loop;
    end test;
BEGIN
    test;
end;
/
