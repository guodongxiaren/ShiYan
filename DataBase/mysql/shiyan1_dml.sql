USE market;
/*一次性插入多条记录，可以提高mysql性能，但要保证插入的记录都是相同的字段*/
INSERT INTO customer
VALUES ( 1,  '吴垂优',  'YoYo',  '1234',  '2014-10-16', 1,  '赣州',  '341400', 123456,  'YoYo@gmail.com',  'student' ),
    ( 2,  '钟彦博',  'suoge',  '1234',  '2014-10-16', 3,  '赣州',  '341400',  'abcdef',  'suoge@gmail.com',  'student' ) ;

INSERT INTO customer(
customerid,
customername,
loginname,

PASSWORD ,
logindate,
creditgradeid,
address,
zipcode
)
VALUES ( 3,  '杜超',  'John',  '1234',  '2014-10-16', 2,  '南昌',  '331700' ) ;

SELECT * 
FROM customer;

INSERT supplier(
supplierid,
suppliername,
loginname,

PASSWORD ,
address,
tel
)
VALUES ( 1,  '威益威',  'weiyiwei',  '123456',  '山东德州',  '15806887088' ) ;

INSERT supplier(
supplierid,
suppliername,
loginname,

PASSWORD ,
address,
tel
)
VALUES ( 2,  '鸽鸽食品',  'gege',  '123456',  '江西鹰潭',  '15207011808' ) ;

INSERT supplier(
supplierid,
suppliername,
loginname,

PASSWORD ,
address,
tel
)
VALUES ( 3,  '奥泉',  'aoquan',  'qwerty',  '湖南湘潭',  '0731-56769098' ) ;

SELECT * 
FROM supplier;

INSERT goods(
goodsid,
goodsname,
supplierid,
goodstypeid,
brand
)
VALUES ( 1,  '凤爪', 1, 1,  '威益威' ) ;

INSERT goods
VALUES ( 2,  '棒棒花干', 3, 3,  '奥泉',  'DB43',  '湖南风味', 1.0, 10 ) ;

INSERT goods(
goodsid,
goodsname,
supplierid,
goodstypeid,
brand
)
VALUES ( 3,  '鸽鸽', 2, 2,  '鸽鸽食品' ) ;

SELECT * 
FROM goods;

INSERT orders(
orderid,
customerid,
goodsid,
quantity
)
VALUES ( 1, 1, 1, 4 ) ;

INSERT orders(
orderid,
customerid,
goodsid,
quantity,
ordersum
)
VALUES ( 2, 3, 2, 4, 4 ) ;

INSERT orders
VALUES ( 3, 2, 2, 3, 3,  '2014-10-16' ) ;

SELECT * 
FROM orders;

INSERT creditgrade
VALUES ( 1,  '铁牌会员' ),( 2,  '铜牌会员' )
,( 3,  '银牌会员' ), ( 4,  '金牌会员' ) ;

SELECT * 
FROM creditgrade;

INSERT goodstype
VALUES ( 1,  '肉制品' ),( 2,  '挤压糕点' ), ( 3,  '豆制品' ) ;

SELECT * 
FROM goodstype;

-- 更新数据
UPDATE goods SET price = 2.0 WHERE goodsid =1;

SELECT * 
FROM goods;
/*删除信用表中的记录
DELETE FROM creditgrade WHERE creditgradeid =4;*/

SELECT * 
FROM creditgrade;