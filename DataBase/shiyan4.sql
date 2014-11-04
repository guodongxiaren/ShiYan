-- （1）创建一个仅包含北京客户信息的视图 customer_beijing。 
CREATE VIEW customer_beijing AS 
SELECT * 
FROM   customer 
WHERE  address='北京' WITH CHECK OPTION 
-- （2）通过查询 customer_beijing 视图获得北京客户的信息 
SELECT * 
FROM   customer_beijing 
-- （3）修改 customer_beijing 视图为仅包含北京客户的信誉等级为1的视图ALTER VIEW customer_beijing AS 
SELECT * 
FROM   customer 
WHERE  address='北京' 
AND    creditgradeid=1 
-- （4）删除 customer_beijing 视图
DROP VIEW customer_beijing 
-- （5）创建一个视图 ordersum_goods，其中的内容是每种商品的名称和每种商品的订单金额的总和
CREATE VIEW ordersum_sum AS 
SELECT   goodsname '商品名称', 
         Sum(orders.ordersum) '总金额' 
FROM     goods, 
         orders 
WHERE    goods.goodsid = orders.goodsid 
GROUP BY goodsname 
-- （6）通过查询 ordersum_goods 视图，获得每种商品的名称和每种商品的订单金额的总和 
SELECT * 
FROM   ordersum_sum