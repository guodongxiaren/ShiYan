USE market 

-- 更新ordersum为goodsid对应的price*quantity的积 
UPDATE orders 
SET    ordersum = (SELECT price 
                   FROM   goods 
                   WHERE  goods.goodsid = orders.goodsid) * quantity 

-- (1) 从 customer 表中查询所有客户的姓名和电话
SELECT customername, 
       tel 
FROM   customer 

-- (2) 查询库存量大于 1000 的商品，结果按库存量从大到小排序
SELECT * 
FROM   goods 
WHERE  storage > 1000 
ORDER  BY storage DESC 

-- (3) 查询每个客户的订单金额的总和
SELECT customername, 
       Sum(ordersum) AS sum 
FROM   orders, 
       customer 
WHERE  customer.customerid = orders.customerid 
GROUP  BY customer.customername 

-- (4) 查询 2005 年上半年（ 1 月 1 日到 6 月 30 日）订货总数大于 5000 的商品
SELECT goodsname, 
       Sum(tmp.ordersum) AS sumprice 
FROM   goods, 
       (SELECT * 
        FROM   orders 
        WHERE  orderdate BETWEEN '2005-01-01' AND '2005-06-30')AS tmp 
WHERE  goods.goodsid = tmp.goodsid 
GROUP  BY goodsname 
HAVING Sum(tmp.quantity) > 5000 

-- (5) 查询所有北京客户的订单信息，包括订单的序号、客户的姓名、商品名、数量
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

-- (6) 查询所有商品在什么时间卖出了多少
SELECT goodsname, 
       orderdate, 
       quantity 
FROM   goods, 
       orders 
WHERE  goods.goodsid = orders.goodsid 

-- (7) 查询没有订单的商品信息
SELECT * 
FROM   goods 
WHERE  goodsid NOT IN (SELECT goodsid 
                       FROM   orders 
                       GROUP  BY goodsid) 

-- (8) 查询每种商品的销售总数量和总金额
SELECT goodsname, 
       Sum(quantity)AS 销售总量, 
       Sum(ordersum)AS 总金额 
FROM   goods, 
       orders 
WHERE  goods.goodsid = orders.goodsid 
GROUP  BY goods.goodsname 
