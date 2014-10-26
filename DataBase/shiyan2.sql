USE market 

-- 设置外键约束  
ALTER TABLE orders 
  ADD FOREIGN KEY(goodsid) REFERENCES goods(goodsid) 

ALTER TABLE orders 
  ADD FOREIGN KEY(customerid) REFERENCES customer(customerid) 

ALTER TABLE goods 
  ADD FOREIGN KEY(supplierid) REFERENCES supplier(supplierid) 

ALTER TABLE goods 
  ADD FOREIGN KEY(goodstypeid) REFERENCES goodstype(goodstypeid) 

ALTER TABLE customer 
  ADD FOREIGN KEY(creditgradeid) REFERENCES creditgrade(creditgradeid) 

ALTER TABLE supplier 
  ADD FOREIGN KEY(creditgradeid) REFERENCES creditgrade(creditgradeid) 

-- 设置唯一约束  
ALTER TABLE customer 
  ADD UNIQUE(loginname) 

ALTER TABLE supplier 
  ADD UNIQUE(loginname) 

ALTER TABLE supplier 
  ADD UNIQUE(suppliername) 

ALTER TABLE creditgrade 
  ADD UNIQUE(creditgradename) 

ALTER TABLE goodstype 
  ADD UNIQUE(goodstypename) 

-- 设置检查约束 
ALTER TABLE customer 
  ADD CHECK(Len(password)>=3) 

ALTER TABLE supplier 
  ADD CHECK(Len(password)>=3) 

ALTER TABLE customer 
  ADD CHECK(zipcode LIKE '[0-9][0-9][0-9][0-9][0-9][0-9]') 

ALTER TABLE customer 
  ADD CHECK(email LIKE '%@%') 

ALTER TABLE supplier 
  ADD CHECK(email LIKE '%@%') 

ALTER TABLE customer 
  ADD CHECK(LEFT(loginname, 1) NOT IN ('[', ']', '^', '_', '@', '#', '.')) 

ALTER TABLE supplier 
  ADD CHECK(LEFT(loginname, 1) NOT IN ('[', ']', '^', '_', '@', '#', '.')) 

-- 设置默认约束  
ALTER TABLE customer 
  ADD CONSTRAINT df_customer_password DEFAULT '000' FOR password 

ALTER TABLE supplier 
  ADD CONSTRAINT df_supplier_password DEFAULT '000' FOR password 

ALTER TABLE customer 
  ADD CONSTRAINT df_customer_logindate DEFAULT Getdate() FOR logindate 

ALTER TABLE supplier 
  ADD CONSTRAINT df_supplier_logindate DEFAULT Getdate() FOR logindate 

ALTER TABLE customer 
  ADD CONSTRAINT df_customer_creditgradeid DEFAULT 2 FOR creditgradeid 

ALTER TABLE supplier 
  ADD CONSTRAINT df_supplier_creditgradeid DEFAULT 2 FOR creditgradeid 

ALTER TABLE goods 
  ADD CONSTRAINT df_goods_goodstypeid DEFAULT 1 FOR goodstypeid 

ALTER TABLE goodstype 
  ADD CONSTRAINT df_goodstype_goodstypeid DEFAULT 1 FOR goodstypeid 

-- 创建触发器,orders增加一个订单,goods表中相应的减少库存量 
go 

CREATE TRIGGER orderinsert1 
ON orders 
after INSERT 
AS 
    UPDATE goods 
    SET    storage = storage - inserted.quantity 
    FROM   goods, 
           inserted 
    WHERE  goods.goodsid = inserted.goodsid 