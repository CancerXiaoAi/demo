create database school;

use school;

create table student(
    number int(10) not null,
    name char(10) not null,
    date date not null
);

insert into student values(1,"cancerai","2007-01-01");
insert into student (number, name, date) values(2,"xiaoai","2007-02-02");
