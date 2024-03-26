-- delete database when it not exist.
drop database if exists school;

-- create new database
create database school;

-- entry database
use school;

-- create new table
create table user(
    number char(10) not null,
    name char(10) not null
);

-- insert data
insert into user (number,name) values("001","CancerAi");

-- delete the table
drop table user;

-- delete database
drop database school;


-- DONE