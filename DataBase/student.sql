create database student;
use student;
create table student (
    sno char(8) primary key,
    sname char(8) not null,
    sex char(2),
    native char(20),
    birthday datetime,
    dno char(6),
    spno char(8),
    classno char(4),
    entime datetime,
    home varchar(40),
    tel varchar(40)
);
create table course (
    cno char(10) primary key,
    cname char(20) not null,
    spno char(8),
    ctno tinyint,
    lecture tinyint,
    experiment tinyint,
    semester tinyint,
    credit tinyint
);
create table teacher (
    tno char(8) primary key,
    tname char(8) not null,
    sex char(2),
    birthday datetime,
    dno char(6),
    pno tinyint,
    home varchar(40),
    zipcode char(6),
    tel varchar(40),
    email varchar(40)
);
create table student_course (
    sno char(8),
    tcid smallint,
    score tinyint,
    primary key (sno , tcid)
);
create table teacher_course
(
tcid smallint primary key,
tno char(8),
spno char(8),
classno char(4),
cno char(10) not null,
semester char(6),
schoolyear char(10),
classtime varchar(40),
classroom varchar(40),
weektime tinyint
);