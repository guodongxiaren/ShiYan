USE market 

go 

CREATE PROC proc_hub 
AS 
  BEGIN 
      SELECT orderid      '订单号', 
             customername '客户姓名', 
             quantity     '订货数量' 
      FROM   orders, 
             customer 
      WHERE  orders.customerid = customer.customerid 
             AND orderid IN (SELECT orderid 
                             FROM   orders 
                             WHERE  goodsid = (SELECT goodsid 
                                               FROM   goods 
                                               WHERE  goodsname = 'hub')); 
  END 

-- 执行存储过程proc_hub 
EXEC proc_hub 

-- 创建带参数的存储过程proc_goods 
go 

CREATE PROC proc_goods @goodsname VARCHAR(20) 
AS 
  BEGIN 
      SELECT * 
      FROM   orders 
      WHERE  goodsid = (SELECT goodsid 
                        FROM   goods 
                        WHERE  goodsname = @goodsname); 
  END 

-- 执行proc_goods 
EXEC proc_goods 'hub' 

-- 删除存储过程 
DROP PROC proc_hub 
DROP PROC proc_goods