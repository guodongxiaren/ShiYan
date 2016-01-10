/*
create database ordersystem;
*/
use ordersystem;

drop table t_user;
drop table t_product;
drop table t_customer;
drop table t_order;

create table if not exists t_user(
    name varchar(20) primary key,
    password varchar(32) not null
);

create table if not exists t_product(
    id int(11) primary key auto_increment,
    name varchar(20) not null,
    price int(11) not null,
    detail varchar(280),
    is_del enum('0', '1') default '0'
);

create table if not exists t_customer(
    id int(11) primary key auto_increment,
    name varchar(20) not null,
    address varchar(60) not null default 'NanChang',
    phone varchar(11) not null,
    is_del enum('0', '1') default '0'
);

create table if not exists t_order(
    id int(11) primary key auto_increment,
    pid int(11) not null, 
    cid int(11) not null, 
    amount int(11) not null default 1,
    order_time date, 
    delivery_time date,
    is_del enum('0', '1') default '0'
);

/* insert data */
insert into t_user(name, password) values('admin', md5('admin'));

INSERT INTO `ordersystem`.`t_order` (`id`, `pid`, `cid`, `amount`, `order_time`, `delivery_time`, `is_del`) VALUES (NULL, '1', '1', '1', '2016-01-03', '2016-01-04', '0');

insert into t_product(id, name, price) values(1, 'iphone6', 4000);
insert into t_customer(id, name, phone) values(1, 'Jelly', '12345678901');
