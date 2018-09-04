-- Table creation
drop table VideoForRent1 CASCADE CONSTRAINTS;
drop table RentalAgreement1 CASCADE CONSTRAINTS;
drop table Registration1 CASCADE CONSTRAINTS;
drop table MEMBER1 CASCADE CONSTRAINTS;
drop table role1 CASCADE CONSTRAINTS;
drop table actor1 CASCADE CONSTRAINTS;
drop table staff1 CASCADE CONSTRAINTS;
drop table video1 CASCADE CONSTRAINTS;
drop table director1 CASCADE CONSTRAINTS;
drop table branch1 CASCADE CONSTRAINTS;

-- branch1
create table branch1(branchNo varchar2(4) PRIMARY KEY,  
		constraint START_WITH_CAPITAL_B check (branchNo like 'B%'), 
		street varchar2(30) not null, 
		city varchar2(20) not null, 
		state varchar2(2) not null, 
		zipCode varchar2(5),
		mgrStaffNo varchar2(5));

-- director1
create table director1(directorNo varchar2(5) PRIMARY KEY, 
		constraint START_WITH_CAPITAL_D check (directorNo like 'D%'), 
		directorName varchar2(30) NOT NULL);

-- video1
create table video1(catalogNo varchar2(6) primary key,
		title varchar2(40) not null,
		category varchar2(10) not null,
		dailyRental DECIMAL(4,2)  DEFAULT 5.00 not null,
		price DECIMAL(4,2),
		directorNo varchar2(5),
		foreign key (directorNo ) references director1(directorNo)); 

-- staff1
create table staff1(staffNo VARCHAR2(5) PRIMARY KEY,
		constraint START_WITH_CAPITAL_S check (staffNo like 'S%'),
		name varchar2(40) not null,
		position varchar2(40) not null,
		salary NUMBER(5) not null,
		branchNo varchar2(4),
		foreign key ( branchNo ) references branch1(branchNo)); 

-- branch1
-- alter table branch1 add (
-- 	foreign key ( mgrStaffNo )
-- 	references staff1(staffNo));

-- actor1
create table actor1( actorNo VARCHAR2(5) PRIMARY  KEY, 
		actorName varchar2(40) NOT NULL);

-- role1
create table role1(actorNo varchar2(5)  NOT NULL constraint START_WITH_CAPITAL_A check(actorNo like 'A%'),
	catalogNo varchar2(6) ,
	character varchar2(40)  NOT NULL,
	primary key (actorNo,catalogNo));

-- MEMBER1
create table MEMBER1(
	memberNo varchar2(7) not null  check(memberNo like 'M%') PRIMARY KEY,
	fName varchar2(40) not null,
	lName varchar2(40) not null,
	address varchar2(40) not null
);

-- Registration1
create table Registration1(branchNo varchar2(4), CONSTRAINT B check (branchNo like 'B%'),
			memberNo varchar2(7), CONSTRAINT M check (memberNo like 'M%'),
			staffNo varchar2(5), foreign key (staffNo) references staff1(staffNo),
			dateJoined Date not null,
			primary key (branchNo, memberNo));
			
-- VideoForRent1
create table VideoForRent1(	
	VideoNo NUMBER(7,0) PRIMARY KEY NOT NULL,
	AVAIABLE VARCHAR2(1) DEFAULT 'N',
	catalogNo varchar2(6),
	foreign key (catalogNo) references video1(catalogNo),
	branchNo varchar2(4) not null constraint beg_with_B check(branchNo like 'B%'),
	foreign key (branchNo) references branch1(branchNo)
);
			-- RenalAgreement3
create table RentalAgreement1(rentalNo varchar(7) primary key not null constraint R check(rentalNo like 'R%'),
	dateOut DATE not null,
--	dateReturn Date not null, was the previous declaration.
    dateReturn Date,
	memberNo varchar2(7),
	Foreign key (memberNo) references  MEMBER1(memberNo),
	videoNo number(6,0)  not null ,
	Foreign key  (VideoNo) references VideoForRent1(VideoNo)); 

