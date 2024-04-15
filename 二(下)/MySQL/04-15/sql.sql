create database school;

source C:\\schooldb.sql

use school;

alter table student add check(出生日期>"1995-01-01");

select * from student;

select 出生日期 from student;