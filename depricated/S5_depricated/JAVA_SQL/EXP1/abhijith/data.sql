start transaction;

-- Branch data
insert into Branch1 (branchNo, street, city, state, zipcode, mgrstaffno) values ('B001','8 Jefferson Way','Portland','OR','97201','51500');
insert into Branch1 (branchNo, street, city, state, zipcode, mgrstaffno) values ('B002','City Center Plaza','Seattle','WA','98122','50010');
insert into Branch1 (branchNo, street, city, state, zipcode, mgrstaffno) values ('B003','14 - 8th Avenue','NewYork','NY','10012','50415');
insert into Branch1 (branchNo, street, city, state, zipcode, mgrstaffno) values ('B004','16 - 14th Avenue','Seattle','WA','98128','52250');

-- Staff data
insert into staff1 values ('S1500','Tom Daniels','Manager',46000,'B001');
insert into staff1 values ('S0003','Sally Adams', 'Assistant',30000,'B001');
insert into staff1 values ('S0010','Mary Martinez', 'Manager', 50000, 'B002');
insert into staff1 values ('S3250','Robert Chin','Supervisor', 32000,'B002');
insert into staff1 values ('S2250','Sally Stern','Manager',48000,'B004');
insert into staff1 values ('S0415','Art Peters', 'Manager', 41000, 'B003');
commit;

-- Director Data

insert into director1 values('D1001','Lee Tamahori');
insert into director1 values('D7834','Chris Columbus');
insert into director1 values('D4576','Peter Jackson');
insert into director1 values('D0078','Andrew Adamson');
insert into director1 values('D5743','Barry Sonnenfield');
insert into director1 values('D3765','Roland Emmerick');

-- Video data
insert into video1 values ('207132', 'Die Another Day', 'Action',5.00 , 21.99, 'D1001');
insert into video1 values ('902355', 'Harrty Potter', 'Children', 4.50, 14.50, 'D7834');
insert into video1 values ('330553', 'Lord of the Rings', 'Fantasy', 5.00, 31.99, 'D4576');
insert into video1 values ('78132', 'Shrek', 'Children', 4.00, 18.50, 'D0078');
insert into video1 values ('445624', 'Men in Black II', 'Action', 4.00, 29.99, 'D5743');
insert into video1 values ('634817', 'Independence Day', 'SciFy', 4.50, 32.99, 'D3765');

--Actor data
insert into actor1 values ('A1002','Pierce Brosnan');
insert into actor1 values ('A3006','Elijah Wood');
insert into actor1 values ('A2019','Will Smith');
insert into actor1 values ('A7525','Tommy Lee Jones');
insert into actor1 values ('A4343','Mike Myers');
insert into actor1 values ('A8401','Daniel Radcliffe');

-- Role data
insert into role1 values ('A1002', '207132', 'James Bond');
insert into role1 values ('A3006', '330553', 'Frodo Baggins');
insert into role1 values ('A3006', '902355', 'Harry Potter');
insert into role1 values ('A2019', '634817', 'Captain Steve Hiller');
insert into role1 values ('A2019', '445624', 'Agent J');
insert into role1 values ('A7525', '445624', 'Agent K');
insert into role1 values ('A4343', '781132', 'Shrek');

-- Member data
INSERT INTO MEMBER1 VALUES('M250178','Bob','Adams','57 - 11th Avenue,Seattle,WA 98105');
INSERT INTO MEMBER1 VALUES('M166884','Art','Peters','89 Redomnd Rd,Portland,OR 97117');
INSERT INTO MEMBER1 VALUES('M115656','Serena','Parker','22 W Captial Way,Portland,OR 97201');
INSERT INTO MEMBER1 VALUES('M284354','Don','Nelson','123 Suffolk Lane,Seattle,WA 98117');

-- Registration data
insert into Registration1 values ('B002', 'M250178', 'S3250', '1-Jul-01');
insert into Registration1 values ('B001', 'M166884', 'S0003', '4-Sep-02');
insert into Registration1 values ('B001', 'M115656', 'S0003', '12-May-00');
insert into Registration1 values ('B002', 'M284354', 'S3250', '9-Oct-01');

-- VideoForRent
insert into VideoForRent1 values (199004,'y','207132','B001');
insert into VideoForRent1 values (245456,'y','207132','B002');
insert into VideoForRent1 values (178643,'n','634817','B001');
insert into VideoForRent1 values (243431,'y','634817','B002');

--RentalAgreement DATA
INSERT INTO RentalAgreement1 VALUES('R753461','4-Feb-03','6-Feb-03','M284354',245456);
INSERT INTO RentalAgreement1 VALUES('R753462','4-Feb-03','6-Feb-03','M284354',243431);
INSERT INTO RentalAgreement1 VALUES('R668256','5-Feb-03','7-Feb-03','M115656',199004);
INSERT INTO RentalAgreement1 (rentalNo, dateout, memberno, videono) VALUES('R668189','2-Feb-03','M115656',178643);

