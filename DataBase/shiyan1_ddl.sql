CREATE DATABASE market
ON
(   NAME=market_data,
	FILENAME='E:\wangwei\sql_data\market_data.mdf',
	SIZE=10,
	FILEGROWTH=10%
)
LOG ON
(   NAME=market_log,
	FILENAME='E:\wangwei\sql_data\market_log.ldf',
	SIZE=5,
	FILEGROWTH=10%
)
USE market
CREATE TABLE customer(
	customerid INT PRIMARY KEY NOT NULL,
	customername CHAR(20) NOT NULL,
	loginname VARCHAR(20),
	password VARCHAR(20),
	logindate SMALLDATETIME,
	creditgradeid TINYINT,
	address VARCHAR(40),
	zipcode CHAR(60),
	tel VARCHAR(40),
	email VARCHAR(40),
	note VARCHAR(100)
)
CREATE TABLE supplier(
	supplierid INT PRIMARY KEY NOT NULL,
	suppliername CHAR(20) NOT NULL,
	loginname VARCHAR(20),
	password VARCHAR(20),
	logindate SMALLDATETIME,
	creditgradeid TINYINT,
	description VARCHAR(40),
	address VARCHAR(40),
	zipcode CHAR(6),
	tel VARCHAR(40),
	email VARCHAR(40),
	note VARCHAR(100)
)
CREATE TABLE goods(
	goodsid INT PRIMARY KEY NOT NULL,
	goodsname VARCHAR(20) NOT NULL,
	supplierid INT NOT NULL,
	goodstypeid INT,
	brand VARCHAR(20),
	goodsmodel VARCHAR(20),
	description VARCHAR(100),
	price MONEY,
	storage INT
)
CREATE TABLE orders(
	orderid INT PRIMARY KEY NOT NULL,
	customerid INT NOT NULL,
	goodsid INT NOT NULL,
	quantity INT,
	ordersum MONEY,
	orderdate DATETIME
)
CREATE TABLE creditgrade(
	creditgradeid TINYINT PRIMARY KEY NOT NULL,
	creditgradename VARCHAR(20)
)
CREATE TABLE goodstype(
	goodstypeid INT PRIMARY KEY,
	goodstypename VARCHAR(20)
)
