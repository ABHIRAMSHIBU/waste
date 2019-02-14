drop table RentalAgreement1;
drop table VideoForRent1;
drop table Registration1;
drop table Role1;
drop table Member1;
drop table Actor1;
drop table Video1;
drop table Director1;
drop table Staff1;
drop table Branch1;

-- Foreign key not added to Branch1 from staff1
create table Branch1(
	branchNo 	varchar2(4) 	NOT NULL 	PRIMARY KEY 	constraint STARTS_WITH_B check(branchNo like 'B%'),
	street 		varchar2(30) 	NOT NULL, 
	city 		varchar2(20)	NOT NULL,
	state 		varchar2(5) 	NOT NULL,
	zipCode 	varchar2(5) 	NOT NULL 	UNIQUE,
 	mgrStaffNo 	varchar2(5) 	NOT NULL 
);

create table Staff1(
	staffNo 	varchar2(5)		NOT NULL	PRIMARY KEY 	constraint STARTS_WITH_S check(staffNo like 'S%'),
	name		varchar2(40)	NOT NULL,	
	position	varchar2(40)	NOT NULL,
	salary		varchar2(5)		NOT NULL,
	branchNo		varchar2(4)	NOT NULL,
 	FOREIGN KEY (branchNo) references Branch1(branchNo)
 );
--Foreign key not added to Branch1 from staff1
--ALTER TABLE Branch1 MODIFY COULUMN mgrStaffNo varchar2(5) NOT NULL FOREIGN KEY(Branch1) REFERENCES Staff1(staffNo) ;
create table Director1(
	directorNo	 varchar2(5) 	primary key 	not null	 constraint begins_with_d_for_director check(directorNo like 'D%'),
	directorName 	 varchar2(30) 			not null
);
create table Video1(
		catalogNo 	varchar2(6) primary key,
		title varchar2(40) not null,
		category varchar2(10) not null,
		dailyRental DECIMAL(4,2) DEFAULT 5.00  not null,
		price DECIMAL(4,2),
		directorNo varchar2(5),
		foreign key (directorNo ) references Director1(directorNo)
); 

create table Actor1( 
		actorNo 		VARCHAR2(5) PRIMARY  KEY, 
		actorName 	varchar2(40)  NOT NULL);

create table Role1(
	actorNo varchar2(5)  NOT NULL constraint starts_with_a_role1 check(actorNo like 'A%'),
	catalogNo varchar2(6) ,
	character varchar2(40)  NOT NULL,
	primary key (actorNo,catalogNo)
);
	

	
ALTER TABLE Branch1 add  FOREIGN KEY (mgrStaffNo) references staff1(staffNo);

		
create table Member1(
	memberNo varchar2(7) primary key not null  check(memberNo like 'M%'),
	fName varchar2(40) not null,
	lName varchar2(40) not null,
	address varchar2(40) not null
); 
create table Registration1(
		branchNo varchar2(4), CONSTRAINT B_Reg check (branchNo like 'B%'),
		memberNo varchar2(7), CONSTRAINT M_Reg check (memberNo like 'M%'),
		staffNo varchar2(5), foreign key (staffNo) references Staff1(staffNo),
		dateJoined Date not null,
		primary key (branchNo, memberNo));

create table VideoForRent(	
	VideoNo NUMBER(7,7) PRIMARY KEY NOT NULL,
	AVAIABLE VARCHAR2(1) DEFAULT 'N',
	catalogNo varchar2(6),
	foreign key (catalogNo) references Video1(catalogNo),
	branchNo varchar2(4) not null constraint beg_with_B check(branchNo like 'B%'),
	foreign key (branchNo) references Branch1(branchNo)
);		
	
create table RentalAgreement1(
	rentalNo varchar(7) primary key not null constraint R check(rentalNo like 'R%'),
	dateOut DATE not null,
	dateReturn Date not null,
	memberNo varchar2(7),
	Foreign key (memberNo) references  MEMBER1(memberNo),
	videoNo NUMBER(7,7)  not null ,
	Foreign key  (VideoNo) references VideoForRent(VideoNo)
);  




