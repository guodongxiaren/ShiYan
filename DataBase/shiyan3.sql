USE market 

-- 更新ordersum为goodsid对应的price*quantity的积 
UPDATE orders 
SET    ordersum = (SELECT price 
                   FROM   goods 
                   WHERE  goods.goodsid = orders.goodsid) * quantity 

-- (1) 
SELECT customername, 
       tel 
FROM   customer 

-- (2) 
SELECT * 
FROM   goods 
WHERE  storage > 1000 
ORDER  BY storage DESC 

-- (3) 
SELECT customername, 
       Sum(ordersum) AS sum 
FROM   orders, 
       customer 
WHERE  customer.customerid = orders.customerid 
GROUP  BY customer.customername 

-- (4) 
SELECT goodsname, 
       Sum(tmp.ordersum) AS sumprice 
FROM   goods, 
       (SELECT * 
        FROM   orders 
        WHERE  orderdate BETWEEN '2005-01-01' AND '2005-06-30')AS tmp 
WHERE  goods.goodsid = tmp.goodsid 
GROUP  BY goodsname 
HAVING Sum(tmp.ordersum) > 5000 

-- (5) 
SELECT orderid, 
       customername, 
       goodsname, 
       quantity 
FROM   customer, 
       orders, 
       goods 
WHERE  customer.address = '北京' 
       AND orders.customerid = customer.customerid 
       AND orders.goodsid = goods.goodsid 

-- (6) 
SELECT goodsname, 
       orderdate, 
       quantity 
FROM   goods, 
       orders 
WHERE  goods.goodsid = orders.goodsid 

-- (7) 
SELECT * 
FROM   goods 
WHERE  goodsid NOT IN (SELECT goodsid 
                       FROM   orders 
                       GROUP  BY goodsid) 

-- (8) 
SELECT goodsname, 
       Sum(quantity)AS 销售总量, 
       Sum(ordersum)AS 总金额 
FROM   goods, 
       orders 
WHERE  goods.goodsid = orders.goodsid 
GROUP  BY goods.goodsname 