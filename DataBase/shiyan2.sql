CREATE DATABASE market
ON
(NAME=student_data,
FILENAME='E:\wangwei\sql_data\student_data.mdf',
SIZE=10,
FILEGROWTH=10%
)
LOG ON
(NAME=student_log,
FILENAME='E:\wangwei\sql_data\student_log.ldf',
SIZE=5,
FILEGROWTH=10%
);