use market
go
create proc proc_hub 
as
begin
declare @orderid int,@goodsid int,@customerid int
select @goodsid=goodsid from goods where goodsname='¸ë¸ë'
select @orderid=orderid from orders where goodsid=@goodsid
select @customerid=customerid from orders where orderid=@orderid
select @orderid,customername from customer where @customerid=customerid
end

exec proc_hub
-- É¾³ý´æ´¢¹ý³Ì
drop proc proc_hub