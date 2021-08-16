use db_3180105151;

create table book(
bno int not null,
type varchar(50) not null,
title varchar(50) not null,
author varchar(30) not null,
year year,
press varchar(30),
price double,
total int,
stock int,
primary key (bno));

insert into book(bno,type,title,author,year,press,price,total,stock)
values
(1,"Computer Science","Database System Concepts","Abraham",2011,"McCrawHill",99,5,4),
(2,"Computer Science","Modern Operating Systems","Andrew",2009,"Pearson",75,3,1),
(3,"Computer Science","Computer Network","Tannenbaum",2000,"Pearson",58,4,3);

create table card(
cno int not null,
name varchar(30) not null,
department varchar(20) not null,
type char(1) not null,
primary key (cno)
);

insert into card(cno,name,department,type)
values
(1,"Jack","CS",'T'),
(2,"Lily","Art",'S'),
(3,"John","CS",'S'),
(4,"Lucy","Physics",'S'),
(5,"Any","Chemistry",'T');

create table borrow(
cno int not null,
bno int not null,
borrow_date date not null,
return_date date not null,
manager_id int not null
);

insert into borrow(cno,bno,borrow_date,return_date,manager_id)
values
(1,1,"2018-1-1","2018-1-14",1),
(1,2,"2018-1-6","2018-1-10",1),
(2,2,"2018-2-3","2018-2-8",2),
(3,3,"2018-2-5","2018-3-1",2);


create table manage(
manager_id int not null,
password varchar(20) not null,
manager_name varchar(30) not null,
phone_number char(11),
primary key (manager_id)
);

insert into manage(manager_id,password,manager_name,phone_number)
values
(1,"12345","Jacob","13372530678"),
(2,"12345","Emma","15928603168");


drop table borrow;
drop table book;
drop table card;
drop table manage;