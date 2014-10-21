-- DROP DATABASE market;
CREATE DATABASE market;
USE market;
CREATE TABLE customer(
	customerid INT PRIMARY KEY,
	customername CHAR(20) NOT NULL,
	loginname VARCHAR(20),
	password VARCHAR(20),
	logindate DATETIME,
	creditgradeid TINYINT,
	address VARCHAR(40),
	zipcode CHAR(60),
	tel VARCHAR(40),
	email VARCHAR(40),
	note VARCHAR(100)
);
CREATE TABLE supplier(
	supplierid INT PRIMARY KEY,
	suppliername CHAR(20) NOT NULL,
	loginname VARCHAR(20),
	password VARCHAR(20),
	logindate DATETIME,
	creditgradeid TINYINT,
	description VARCHAR(40),
	address VARCHAR(40),
	zipcode CHAR(6),
	tel VARCHAR(40),
	email VARCHAR(40),
	note VARCHAR(100)
);
CREATE TABLE goods(
	goodsid INT PRIMARY KEY,
	goodsname VARCHAR(20) NOT NULL,
	supplierid INT NOT NULL,
	goodstypeid INT,
	brand VARCHAR(20),
	goodsmodel VARCHAR(20),
	description VARCHAR(100),
	price DOUBLE,
	storage INT
);
CREATE TABLE orders(
	orderid INT PRIMARY KEY,
	customerid INT NOT NULL,
	goodsid INT NOT NULL,
	quantity INT,
	ordersum DOUBLE,
	orderdate DATETIME
);
CREATE TABLE creditgrade(
	creditgradeid TINYINT PRIMARY KEY,
	creditgradename VARCHAR(20)
);
CREATE TABLE goodstype(
	goodstypeid INT PRIMARY KEY,
	goodstypename VARCHAR(20)
);
