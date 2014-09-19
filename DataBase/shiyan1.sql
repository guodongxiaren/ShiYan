use market;
create table customer (
    customerid int,
    customername char(20),
    loginname varchar(20),
    password varchar(20),
    logindate datetime,
    creditgradeid tinyint,
    address varchar(40),
    zipcode char(6),
    tel varchar(40),
    email varchar(40),
    note varchar(100)
);
show tables;
create table supplier (
    supplierid int primary key not null,
    suppliername char(20) not null,
    loginname varchar(20),
    password varchar(20),
    logindate datetime,
    creditgradeid tinyint,
    description varchar(100),
    address varchar(40),
    zipcode char(6),
    tel varchar(40),
    email varchar(40),
    note varchar(100)
);
create table goods (
    goodsid int primary key not null,
    goosname varchar(20) not null,
    supplierid int not null,
    goodstypeid int,
    brand varchar(20),
    goodsmodel varchar(20),
    description varchar(100),
    price double(20 , 4 ),
    storages int
);
show tables;
create table orders (
    orderind int primary key not null,
    customerid int not null,
    goodsid int not null,
    quantity int,
    ordersum double(20 , 4 ),
    orderdata datetime
);
create table creditgrade (
    creditgradeid tinyint primary key not null,
    creditgradename varchar(20)
);
create table goodstype (
    goodstypeid int primary key,
    goodstypename varchar(20)
);
