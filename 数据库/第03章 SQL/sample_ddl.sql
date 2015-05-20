-- 本SQL语句是MySQL数据库中的。对原书中的代码进行了修改。
CREATE DATABASE student;
USE student;
-- 这个是课本中的表，设计的比较差，不应该存储年龄而应该存储出生日期。
CREATE TABLE Student (
    Sno CHAR(10) PRIMARY KEY,
    Sname VARCHAR(20) UNIQUE,
    Ssex CHAR(2),
    Sage SMALLINT,
    Sdept VARCHAR(20)
);
CREATE TABLE Course (
    Cno CHAR(4) PRIMARY KEY,
    Cname VARCHAR(40),
    Cpno CHAR(4),
    Ccredit SMALLINT,
    FOREIGN KEY (Cpno)
        REFERENCES Course (Cno)
);
CREATE TABLE SC (
    Sno CHAR(10),
    Cno CHAR(4),
    PRIMARY KEY (Sno , Cno),
    FOREIGN KEY (Sno)
        REFERENCES Student (Sno),
    FOREIGN KEY (Cno)
        REFERENCES Course (Cno)
);
