create database stuact_考生号;
 
use stuact_考生号;
create table s_考生号(
	sno char(8) not null primary key,
	sname varchar(10)
);
create table act_考生号(
	ano char(10) primary key,
	aname varchar(100),
	adepart varchar(20)
);
create table sa_考生号(
	sno char(8) not null,
	ano char(10),
	score real,
	primary key(sno,ano)
);

insert into s_考生号 (sno,sname) values("10000111","刘洋");
insert into s_考生号 (sno,sname) values("10000265","林晨");
insert into act_考生号 (ano,aname,adepart) values("10011001","爱国教育","学生处");
insert into act_考生号 (ano,aname,adepart) values("10021002","新生军训","学生处");
insert into act_考生号 (ano,aname,adepart) values("10031003","社团活动","团委");
insert into sa_考生号 (sno,ano,score) values("10000111","10011001",87);
insert into sa_考生号 (sno,ano,score) values("10000111","10031003",79);
insert into sa_考生号 (sno,ano,score) values("10000265","10011001",70);
insert into sa_考生号 (sno,ano,score) values("10000265","10021002",83);
insert into sa_考生号 (sno,ano,score) values("10000265","10031003",97);

alter table sa_考生号 add foreign key (sno) references s_考生号 (sno) on update cascade on delete cascade;
alter table sa_考生号 add check(score>=55 and score<=100);