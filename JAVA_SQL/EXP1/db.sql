-- Table creation
drop table VideoForRent3 CASCADE CONSTRAINTS;
drop table RentalAgreement3 CASCADE CONSTRAINTS;
drop table Registration3 CASCADE CONSTRAINTS;
drop table Member3 CASCADE CONSTRAINTS;
drop table Role3 CASCADE CONSTRAINTS;
drop table Actor3 CASCADE CONSTRAINTS;
drop table Staff3 CASCADE CONSTRAINTS;
drop table Video3 CASCADE CONSTRAINTS;
drop table Director3 CASCADE CONSTRAINTS;
drop table Branch3 CASCADE CONSTRAINTS;

-- Branch3
create table Branch3(branchNo varchar2(4) PRIMARY KEY,  
		constraint START_WITH_CAPITAL_B check (branchNo like 'B%'), 
		street varchar2(30) not null, 
		city varchar2(20) not null, 
		state varchar2(2) not null, 
		zipCode varchar2(5),
		mgrStaffNo varchar2(5));

-- Director3
create table Director3(directorNo varchar2(5) PRIMARY KEY, 
		constraint START_WITH_CAPITAL_D check (directorNo like 'D%'), 
		directorName varchar2(30) NOT NULL);

-- Video3
create table Video3(catalogNo varchar2(6) primary key,
		title varchar2(40) not null,
		category varchar2(10) not null,
		dailyRental DECIMAL(4,2)  DEFAULT 5.00 not null,
		price DECIMAL(4,2),
		directorNo varchar2(5),
		foreign key (directorNo ) references Director3(directorNo)); 

-- Staff3
create table Staff3(staffNo VARCHAR2(5) PRIMARY KEY,
		constraint START_WITH_CAPITAL_S check (staffNo like 'S%'),
		name varchar2(40) not null,
		position varchar2(40) not null,
		salary NUMBER(5) not null,
		branchNo varchar2(4),
		foreign key ( branchNo ) references Branch3(branchNo)); 

-- Branch3
-- alter table Branch3 add (
-- 	foreign key ( mgrStaffNo )
-- 	references Staff3(staffNo));

-- Actor3
create table Actor3( actorNo VARCHAR2(5) PRIMARY  KEY, 
		actorName varchar2(40) NOT NULL);

-- Role3
create table Role3(actorNo varchar2(5)  NOT NULL constraint START_WITH_CAPITAL_A check(actorNo like 'A%'),
	catalogNo varchar2(6) ,
	character varchar2(40)  NOT NULL,
	primary key (actorNo,catalogNo));

-- Member3
create table Member3(
	memberNo varchar2(7) not null  check(memberNo like 'M%') PRIMARY KEY,
	fName varchar2(40) not null,
	lName varchar2(40) not null,
	address varchar2(40) not null
);

-- Registration3
create table Registration3(branchNo varchar2(4), CONSTRAINT B check (branchNo like 'B%'),
			memberNo varchar2(7), CONSTRAINT M check (memberNo like 'M%'),
			staffNo varchar2(5), foreign key (staffNo) references Staff3(staffNo),
			dateJoined Date not null,
			primary key (branchNo, memberNo));
			
-- VideoForRent3
create table VideoForRent3(	
	VideoNo NUMBER(7,0) PRIMARY KEY NOT NULL,
	AVAIABLE VARCHAR2(1) DEFAULT 'N',
	catalogNo varchar2(6),
	foreign key (catalogNo) references Video3(catalogNo),
	branchNo varchar2(4) not null constraint beg_with_B check(branchNo like 'B%'),
	foreign key (branchNo) references Branch3(branchNo)
);
			-- RenalAgreement3
create table RentalAgreement3(rentalNo varchar(7) primary key not null constraint R check(rentalNo like 'R%'),
	dateOut DATE not null,
--	dateReturn Date not null, was the previous declaration.
    dateReturn Date,
	memberNo varchar2(7),
	Foreign key (memberNo) references  MEMBER3(memberNo),
	videoNo number(6,0)  not null ,
	Foreign key  (VideoNo) references VideoForRent3(VideoNo)); 

