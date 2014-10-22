USE market;
SHOW TABLES;
DESC customer;
-- 设置主键约束
/*因为在建表的时候已经设置了主键，所以这里就不再设置了。格式如下：
ALTER TABLE customer ADD PRIMARY KEY(customerid);
*/
-- 设置外键约束
ALTER TABLE orders ADD FOREIGN KEY(goodsid) REFERENCES goods(goodsid); 
ALTER TABLE orders ADD FOREIGN KEY(customerid) REFERENCES customer(customerid);
ALTER TABLE goods ADD FOREIGN KEY(supplierid) REFERENCES supplier(supplierid);
ALTER TABLE goods ADD FOREIGN KEY(goodstypeid) REFERENCES goodstype(goodstypeid);
ALTER TABLE customer ADD FOREIGN KEY(creditgradeid) REFERENCES creditgrade(creditgradeid);
ALTER TABLE supplier ADD FOREIGN KEY(creditgradeid) REFERENCES creditgrade(creditgradeid);
-- 设置唯一约束
ALTER TABLE customer ADD UNIQUE(loginname);
ALTER TABLE supplier ADD UNIQUE(loginname),ADD UNIQUE(suppliername);
ALTER TABLE creditgrade ADD UNIQUE(creditgradename);
ALTER TABLE goodstype ADD UNIQUE(goodstypename);
-- 设置默认约束
ALTER TABLE customer ALTER password SET DEFAULT '000';
ALTER TABLE supplier ALTER password SET DEFAULT '000';
ALTER TABLE customer ALTER creditgradeid SET DEFAULT 2;
ALTER TABLE supplier ALTER creditgradeid SET DEFAULT 2;
ALTER TABLE creditgrade ALTER creditgradeid SET DEFAULT 2;
ALTER TABLE goods ALTER goodstypeid SET DEFAULT 1;
ALTER TABLE goodstype ALTER goodstypeid SET DEFAULT 1;
/*mysql 不支持设置默认值为函数*/
ALTER TABLE customer CHANGE logindate logindate DATETIME DEFAULT CURRENT_TIMESTAMP;
