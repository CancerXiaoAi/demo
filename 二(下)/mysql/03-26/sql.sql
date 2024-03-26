-- delete database when it not exist.
drop database school if exist;

-- create new database
create database school;

-- entry database
use school;

-- create new table
create table user(
    number char(10) not null,
    name char(10) not null
);

-- delete the table
drop table user;

-- delete database
drop database school;


-- DONE