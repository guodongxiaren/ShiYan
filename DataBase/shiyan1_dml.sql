USE market
INSERT INTO customer 
VALUES     (1, 
            '吴垂优', 
            'YoYo', 
            '1234', 
            '2014-10-16', 
            1, 
            'NanChang', 
            '330031', 
            123456, 
            'YoYo@gmail.com', 
            'student'); 

INSERT INTO customer 
VALUES     (2, 
            '钟彦博', 
            'Bob', 
            '1234', 
            '2014-10-16', 
            3, 
            'NanChang', 
            '330031', 
            'abcdef', 
            'bob@gmail.com', 
            'student'); 

INSERT INTO customer 
            (customerid, 
             customername, 
             loginname, 
             password, 
             logindate, 
             creditgradeid, 
             address, 
             zipcode) 
VALUES     (3, 
            '杜超', 
            'John', 
            '1234', 
            '2014-10-16', 
            2, 
            'NanChang', 
            '330031');

SELECT * 
FROM   customer 

INSERT supplier 
       (supplierid, 
        suppliername, 
        loginname, 
        password, 
        address, 
        tel) 
VALUES( 1, 
        '威益威', 
        'weiyiwei', 
        '123456', 
        '山东德州', 
        '15806887088' ) 

INSERT supplier 
       (supplierid, 
        suppliername, 
        loginname, 
        password, 
        address, 
        tel) 
VALUES( 2, 
        '鸽鸽食品', 
        'gege', 
        '123456', 
        '江西鹰潭', 
        '15207011808' ) 

INSERT supplier 
       (supplierid, 
        suppliername, 
        loginname, 
        password, 
        address, 
        tel) 
VALUES( 3, 
        '奥泉', 
        'aoquan', 
        'qwerty', 
        '湖南湘潭', 
        '0731-56769098' ) 

INSERT supplier 
VALUES(4, 
       '中粮', 
       'zhongliang', 
       'zl123', 
       NULL, 
       NULL, 
       NULL, 
       '江西南昌', 
       '330031', 
       '18044445555', 
       NULL, 
       NULL); 

SELECT * 
FROM   supplier 
INSERT goods 
       (goodsid, 
        goodsname, 
        supplierid, 
        goodstypeid, 
        brand) 
VALUES(1, 
       '凤爪', 
       1, 
       1, 
       '威益威') 

INSERT goods 
VALUES(2, 
       '棒棒花干', 
       3, 
       3, 
       '奥泉', 
       'DB43', 
       '湖南风味', 
       1.0, 
       10) 

INSERT goods 
       (goodsid, 
        goodsname, 
        supplierid, 
        goodstypeid, 
        brand) 
VALUES(3, 
       '鸽鸽', 
       2, 
       2, 
       '鸽鸽食品') 

SELECT * 
FROM   goods 

INSERT orders 
       (orderid, 
        customerid, 
        goodsid, 
        quantity) 
VALUES(1, 
       1, 
       1, 
       4) 

INSERT orders 
       (orderid, 
        customerid, 
        goodsid, 
        quantity, 
        ordersum) 
VALUES(2, 
       3, 
       2, 
       4, 
       4) 

INSERT orders 
VALUES(3, 
       2, 
       2, 
       3, 
       3, 
       '2014-10-16') 

SELECT * 
FROM   orders 

INSERT creditgrade 
VALUES(1, 
       '铁牌会员') 

INSERT creditgrade 
VALUES(2, 
       '铜牌会员') 

INSERT creditgrade 
VALUES(3, 
       '银牌会员') 

INSERT creditgrade 
VALUES(4, 
       '金牌会员') 

SELECT * 
FROM   creditgrade 

INSERT goodstype 
VALUES(1, 
       '肉制品') 

INSERT goodstype 
VALUES(2, 
       '挤压糕点') 

INSERT goodstype 
VALUES(3, 
       '豆制品') 

INSERT goodstype 
VALUES(4, 
       '饮料')
SELECT * 
FROM   goodstype 
----更新数据
UPDATE goods SET price=2.0 WHERE goodsid=1
SELECT * FROM goods
DELETE FROM creditgrade WHERE creditgradeid=4
SELECT * FROM creditgrade
